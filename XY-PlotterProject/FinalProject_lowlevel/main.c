#define main_C_SRC


#include "All_lib.H"
#define RX1Q_LN 8
#define RX_CMND_FRM_LN 16
#define START_CHR 0xff
#define END_CHR 0xff//UART Queue
#define TX1Q_LN 128



void break_motor(unsigned int8 axis);
void CheckPackage (int8u *Package);
void set_zero();
static void HardwareInit (void) ;
static void VariablesInit (void) ;
static void DynamicMemInit();
static void UARTQueueInit();
static int8u SendTx1(int8u *strPtr);
void PIDcontrol_X_Y_AXIS(float target_x, float target_y, float tolerance);
/****************************************************************************/
/**                                                                        **/
/**                           EXPORTED VARIABLES                           **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                            GLOBAL VARIABLES                            **/
/**                                                                        **/
/****************************************************************************/
static volatile Q8UX_STRUCT Tx1QCB;
static volatile int8u Tx1QArray[TX1Q_LN];
static volatile int8u *Tx1BuffPtr;
static volatile int16u Tx1BuffIdx;
static volatile TX1_STATUS Tx1Flag;
static volatile int16u Tx1FrameIn, Tx1FrameOut, Rx1FrameCount, RxCount, Tx1QFullCount, Rx1QFullCount;
static volatile int8u *RxBuffPtr;
static volatile QPTRX_STRUCT Rx1QCB;
static volatile PTR_STRUCT Rx1BuffPtrArray[RX1Q_LN];
static volatile PTR_STRUCT DestPtrStruct;
static volatile int8u Package[16];

static volatile int16u MemFail, MemCount;


Encoder MotorX_en,
        MotorY_en,
        MotorZ_en;

/*Rotation MotorX_direc,
     MotorY_direc,
     MotorZ_direc;
*/
PID_PARAMIT MotorX_PID,
            MotorY_PID;

Rotation LimitX_Mot,
         LimitY_Mot;

Limit State_lim_X,
      State_lim_Y;

state STATE_OF_BOT;

int X_CHECK_LEVEL = 1, Y_CHECK_LEVEL = 1;
float tolerance = 5;
int16u ip_bX, ip_bY;

int main (void)
{
  int8u errCode, SendTx1Count;
  DisableIntr();
  clear_interrupt(INT_EXT0);
  enable_interrupts(INT_EXT0);
  clear_interrupt(INT_EXT1);
  enable_interrupts(INT_EXT1);
  VariablesInit();
  HardwareInit();
  DynamicMemInit();
  UARTQueueInit();
  EnableIntr();
  for (;;) {
    /* code */
    switch (STATE_OF_BOT) {
      case PID :
        enable_interrupts(INT_TIMER5);
        break;
      case Serial :
        /*free(Package);
          PackageSerial(1,Package, &MotorX_PID, &MotorY_PID);
          SendTx1((int8u *)Package);
        */
        STATE_OF_BOT = wait;
        break;
      case XY_SETZERO :
        set_zero();
        break;
      case STOP_MOTOR :
        break_motor(X_Y_AXIS);
        break;
      default :
        DisableIntr();
        QPtrXGet(&Rx1QCB, &DestPtrStruct, &errCode);
        if (errCode == Q_OK) {
          CheckPackage((int8u *)DestPtrStruct.blockPtr);
          // SendTx1Count = SendTx1((int8u *)DestPtrStruct.blockPtr);
          free ((void *)DestPtrStruct.blockPtr);
          MemCount--;
          EnableIntr();
          // if (SendTx1Count == 0){

          // }
        }
        else {
          EnableIntr();
        }
        break;
    }


  }
}


static void VariablesInit(void) {

  STATE_OF_BOT = wait;


  State_lim_X = N, State_lim_Y = N;
  Tx1Flag = TX1_READY;
  Tx1BuffIdx = 0;
  Tx1FrameIn = 0;
  Tx1FrameOut = 0;
  Tx1QFullCount = 0;
  Rx1FrameCount = 0;
  RxCount = 0;
  Rx1QFullCount = 0;
  MemFail = 0;
  MemCount = 0;

  targetX = 0;
  targetY = 0;

  MotorX_en.Interval = 0;
  MotorX_en.distance = 0;

  MotorY_en.Interval = 0;
  MotorY_en.distance = 0;

  MotorZ_en.Interval = 0;
  MotorZ_en.distance = 0;

  MotorX_PID.K_p = 60.0f;
  MotorX_PID.K_i = 0.0f;
  MotorX_PID.K_d = 0.0f;

  MotorX_PID.u = 0;
  MotorX_PID.error = 0;
  MotorX_PID.previous_error = 0;
  MotorX_PID.integral_error = 0;
  MotorX_PID.currentPosition = 0;
  MotorX_PID.delta_u = 0;
  MotorX_PID.previous_u = 0;
  MotorX_PID.previous_previous_error = 0;

  MotorY_PID.K_p = 60.0f;
  MotorY_PID.K_i = 0.0f;
  MotorY_PID.K_d = 0.0f;

  MotorY_PID.u = 0;
  MotorY_PID.error = 0;
  MotorY_PID.previous_error = 0;
  MotorY_PID.integral_error = 0;
  MotorY_PID.currentPosition = 0;
  MotorY_PID.delta_u = 0;
  MotorY_PID.previous_u = 0;
  MotorY_PID.previous_previous_error = 0;
}


static void HardwareInit (void) {
  setup_adc_ports(NO_ANALOGS);

  set_tris_a (get_tris_a() & 0xffe8); // 1111 1111 1110 1000 A2, A4 o/p
  set_tris_b (get_tris_b() & 0xfff3); // 1111 1111 1111 0011 B2, B3 o/p




  set_compare_time(1, 0);
  setup_compare(1, COMPARE_PWM | COMPARE_TIMER2);
  set_pwm_duty(1, 0);



  set_compare_time(2, 0);
  setup_compare(2, COMPARE_PWM | COMPARE_TIMER2);
  set_pwm_duty(2, 0);

  clear_interrupt(INT_TIMER2);
  set_timer2(0);
  setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1, 1000);

  clear_interrupt(INT_TIMER1);
  set_timer1(0);
  setup_timer1(TMR_INTERNAL | TMR_DIV_BY_256, 624);
  disable_interrupts(INT_TIMER1);


  clear_interrupt(INT_TIMER4);
  set_timer4(0);
  setup_timer4(TMR_INTERNAL | TMR_DIV_BY_256, 31249);
  disable_interrupts(INT_TIMER4);
  enable_interrupts(INT_TIMER4);


  // TIMER5
  clear_interrupt(INT_TIMER5);
  set_timer5(0);
  setup_timer5(TMR_INTERNAL | TMR_DIV_BY_256,3124 ); /////10 ms
  disable_interrupts(INT_TIMER5);


  setup_capture(1, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE | CAPTURE_TIMER3);
  clear_interrupt(INT_IC1);
  enable_interrupts(INT_IC1);

  setup_capture(2, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE | CAPTURE_TIMER3);
  clear_interrupt(INT_IC2);
  enable_interrupts(INT_IC2);

  setup_capture(3, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE | CAPTURE_TIMER3);
  clear_interrupt(INT_IC3);
  enable_interrupts(INT_IC3);

  setup_capture(4, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE | CAPTURE_TIMER3);
  clear_interrupt(INT_IC4);
  enable_interrupts(INT_IC4);

  set_timer3(0);
  setup_timer3(TMR_INTERNAL | TMR_DIV_BY_1, 65535);
  return;
}



void CheckPackage (int8u *Package) {
  int16u HByte, LByte;
  switch (Package[2]) {
    case 1:
      switch (Package[3]) {
        case 1 :////  Coordinate X_Y_AXIS
          HByte = Package[5] << 8;
          LByte = Package[6];
          targetX = (float)(HByte | LByte);
          HByte = Package[7] << 8;
          LByte = Package[8];
          targetY = (float)(HByte | LByte);
          // printf("%d  %d\n",(int)targetX,(int)targetY );
          STATE_OF_BOT = PID;
          break;
        case 2 :
          STATE_OF_BOT = STOP_MOTOR;
          break;
        case 3 :
          STATE_OF_BOT = XY_SETZERO;
          break;
      }
      break;
    case 2 :

      break;
  }
}

void break_motor(unsigned int8 axis) {
  pwm = 0;
  if (axis == AXIS_Y) {
    //disable_interrupts(INT_TIMER5);
    set_pwm_duty(1, 0);
  }
  else if (axis == X_Y_AXIS) {
    set_pwm_duty(1, 0);
    set_pwm_duty(2, 0);
  }
  else {
    set_pwm_duty(2, 0);

  }
}

#INT_TIMER4
void TIMER4 (void) {
  STATE_OF_BOT = Serial;
}


#INT_TIMER1
void TIMER1 (void) {
  //    printf("TIMER_1 \n");

  if (State_lim_X == Y && State_lim_Y == Y)
  {
    //  printf("RESTATE \n");
    /*printf(" %d  %d \n", (int) MotorX_en.distance, (int)MotorY_en.distance );
    targetX = 0;
    targetY = 0;

    MotorX_en.Interval = 0;
    MotorX_en.distance = 0;

    MotorY_en.Interval = 0;
    MotorY_en.distance = 0;

    MotorZ_en.Interval = 0;
    MotorZ_en.distance = 0;


    MotorX_PID.u = 0;
    MotorX_PID.error = 0;
    MotorX_PID.previous_error = 0;
    MotorX_PID.integral_error = 0;
    MotorX_PID.currentPosition = 0;
    MotorX_PID.delta_u = 0;
    MotorX_PID.previous_u = 0;
    MotorX_PID.previous_previous_error = 0;

    MotorY_PID.u = 0;
    MotorY_PID.error = 0;
    MotorY_PID.previous_error = 0;
    MotorY_PID.integral_error = 0;
    MotorY_PID.currentPosition = 0;
    MotorY_PID.delta_u = 0;
    MotorY_PID.previous_u = 0;
    MotorY_PID.previous_previous_error = 0;
    
      printf(" %d  %d \n",(int) MotorX_en.distance,(int)MotorY_en.distance );
      //free(Package);
      //PackageSerial(2,Package, &MotorX_PID, &MotorY_PID);
      //SendTx1((int8u *)Package);
      break_motor(X_Y_AXIS);
      STATE_OF_BOT = wait;
      disable_interrupts(INT_TIMER1);
    */

    VariablesInit();
    STATE_OF_BOT = wait;
    disable_interrupts(INT_TIMER1);

  }
  if (State_lim_X == N) {
    if (X_CHECK_LEVEL == 1) {
      LimitX_Mot = CW;
      drive_motor(AXIS_X, LimitX_Mot, 400);
      State_lim_X = N;
    }
    else {
      set_pwm_duty(1, 0);
      State_lim_X = Y;

    }
  }
  if (State_lim_Y == N) {
    if (Y_CHECK_LEVEL == 1) {

      LimitY_Mot = CW;
      drive_motor(AXIS_Y, LimitY_Mot, 400);
      State_lim_Y = N;
    }
    else {
      set_pwm_duty(2, 0);
      State_lim_Y = Y;

    }
  }
}


#INT_IC1
void IC1ISR (void) {

  Encod_Get_B(AXIS_X, &MotorX_en, 4, 5);
}


#INT_IC2
void IC2ISR (void) {
  Encod_Get_A(AXIS_X, &MotorX_en, 4, 5);
}


#INT_IC3
void IC3ISR (void) {

  Encod_Get_B(AXIS_Y, &MotorY_en, 0, 1);
}


#INT_IC4
void IC4ISR (void) {
  Encod_Get_A(AXIS_Y, &MotorY_en, 0, 1);

}


#INT_EXT0 /// Y axis
void External_0()
{
  ip_bY = input_b();
  Y_CHECK_LEVEL = (ip_bY & (1 << Limit_y) ) >> Limit_y;
}


#INT_EXT1 /// X axis
void External_1()
{
  ip_bX = input_b();
  X_CHECK_LEVEL = (ip_bX & (1 << Limit_x) ) >> Limit_x;
}

void set_zero() {

  State_lim_X = N;
  State_lim_Y = N;
  X_CHECK_LEVEL = input_state(Limit_x);
  Y_CHECK_LEVEL = input_state(Limit_y);
  // disable_interrupts(INT_TIMER5);
  enable_interrupts(INT_TIMER1);
}




void PIDcontrol_X_Y_AXIS(float target_x, float target_y, float tolerance) {
  printf("\nY = %d , X = %d\n", (int)MotorY_PID.currentPosition, (int)MotorX_PID.currentPosition );



}

static void DynamicMemInit()
{
  RxBuffPtr = (int8u *)malloc ((sizeof (int8u)) * RX_CMND_FRM_LN);
  if (RxBuffPtr != (int8u *)NULL)
  {
    MemCount++;
    clear_interrupt(INT_RDA);
    enable_interrupts(INT_RDA);
  }
  else
  {
    MemFail++;
  }
  return;
}

static void UARTQueueInit()
{
  QPtrXInit (&Rx1QCB, Rx1BuffPtrArray, RX1Q_LN);
  Q8UXInit(&Tx1QCB, Tx1QArray, TX1Q_LN);
  return;
}
static int8u SendTx1 (int8u *strPtr)
{
  int8u strLn;
  int8u strIdx;
  int16u qSpace;
  int8u errCode;
  int8u count;
  count = 0;
  //strLn = strlen(strPtr);
  strLn = strPtr[4] + 5;
  if (strLn != 0)
  {
    /* code */
    qSpace = TX1Q_LN - Q8UXCount(&Tx1QCB);
    if (qSpace >= (int16u)strLn)
    {
      /* code */
      for (strIdx = 0; strIdx < strLn; strIdx++)
      {
        Q8UXPut(&Tx1QCB, strPtr[strIdx], &errCode);
        count++;
      }
      if (Tx1Flag == TX1_READY)
      {
        Tx1Flag = TX1_BUSY;
        TX1IF = 1;
        enable_interrupts(INT_TBE);
      }
    }
  }
  return count;
}


#INT_RDA
void RDA1()
{
  static FRAME_STATE FrameState = FRAME_WAIT;
  static int16u FrmIdx = 0;
  static int16u End_length = NULL;
  int8u Chr;
  int8u *errCode;
  int8u checksum = 0;
  int length = 0;

  // Buffer[0] = 0xFF ,Buffer[1] = 0xFF,Buffer[2] = ID,Buffer[3] = length.
  Chr = getc(); // Read data from Rx1 register
  RxCount++;
  switch (FrameState) // State machine for build frame
  {
    case FRAME_WAIT: // waits for start char of new frame
      if (Chr == 0xFF)
      {
        //Get a start char
        RxBuffPtr[FrmIdx] = Chr;
        if (FrmIdx == 1) {
          FrameState = FRAME_PROGRESS; // Change state to build frame
        }
        FrmIdx++;
      } else {
        FrmIdx = 0;
        FrameState = FRAME_WAIT;
      }
      break;
    case FRAME_PROGRESS: // Build frame

      if (FrmIdx == End_length)
      {
        //Get and char. Frame completes.
        RxBuffPtr[FrmIdx] = Chr;
        length = RxBuffPtr[4];
        for (int i = 2; i < 4 + length; i++ ) {
          checksum += RxBuffPtr[i];
        }
        checksum = (~checksum) & 0x00ff;
        if (checksum != RxBuffPtr[FrmIdx]) {
          FrmIdx = 0;
          FrameState = FRAME_WAIT;
        }
        else {
          FrmIdx++;
          RxBuffPtr[FrmIdx] = 0;
          FrmIdx = 0;
          End_length = NULL;
          Rx1FrameCount++;
          //----------------------- Sends Rx1 event to event queue.-------------------
          QPtrXPut (&Rx1QCB, (void *)RxBuffPtr, &errCode);
          if (errCode == Q_FULL)
          {
            //EvQ full error. Free mem of data block.
            free ((void *)RxBuffPtr);
            MemCount--;
            Rx1QFullCount++;
          }
          FrameState = FRAME_WAIT; // Back to wait for start char of new frame.
          // GEt mem block for better of new frame
          RxBuffPtr = (int8u *)malloc ((sizeof (int8u)) * RX_CMND_FRM_LN);
          if (RxBuffPtr == (int8u *)NULL)
          {
            //Can not get mem block. Disable Rx1 interupt.
            disable_interrupts(INT_RDA);
            MemFail++;
          }
          else
          {
            MemCount++;
          }
        }
      }
      else
      {
        RxBuffPtr[FrmIdx] = Chr;
        if (FrmIdx == 4) {
          End_length = FrmIdx + RxBuffPtr[FrmIdx];
        }
        FrmIdx++;
      }
      break;
    default:
      break;
  }
  return;
}

#INT_TBE
void TBE1ISR()
{
  int8u destChr;
  Q_ERR errCode;
  Q8UXGet (&Tx1QCB, &destChr, &errCode);
  if (errCode == Q_OK)
  {
    /* code */
    putc(destChr);
  }
  else
  {
    disable_interrupts(INT_TBE);
    Tx1Flag = TX1_READY;
  }
  return;
}


#INT_TIMER5
void TIMER5 (void) {

  //printf("TiMer5\n");
  printf("\nY = %d , X = %d\n", (int)MotorY_PID.currentPosition, (int)MotorX_PID.currentPosition );
  //  printf("\TARGETX = %d , TARGETY = %d\n",(int)targetX,(int)targetY);

  Velocity_POSITION_PID (AXIS_Y, targetY, &MotorY_en, &MotorY_PID, tolerance);
  Velocity_POSITION_PID (AXIS_X, targetX, &MotorX_en, &MotorX_PID, tolerance);
  if (abs(MotorY_PID.error) < tolerance && abs(MotorX_PID.error) < tolerance) {
    //free(Package);
    //PackageSerial(3,Package, &MotorX_PID, &MotorY_PID);
    //SendTx1((int8u *)Package);
    disable_interrupts(INT_TIMER5);
    STATE_OF_BOT = wait;
  }


}
