

#define All_lib_C_SRC

#include "All_lib.H"


Rotation DIREC_PID;



void drive_motor(unsigned int8 axis,Rotation &direction, float pwm){
  if (pwm > 750){ pwm = 750;}
  if (axis == AXIS_X){
    if (direction == CW){
      output_low(PIN_A2);
      output_high(PIN_A4);
    }
    else {
      output_low(PIN_A4);
      output_high(PIN_A2);
    }
    set_pwm_duty(1,(int16u)pwm);////////////////////////////////////////////// AXIS_Y
  }
  else{
    if (direction == CW){
      output_low(PIN_A0);
      output_high(PIN_A1);
    }
    else {
      output_low(PIN_A1);
      output_high(PIN_A0);
    }

    set_pwm_duty(2,(int16u)pwm);////////////////////////////////////////////// AXIS_X
  }
}

void Encod_Get_B(unsigned int8 Capture, Encoder *PTR_ENCODER, int16u Pin_A, int16u Pin_B){
  int16u ip_b, c_a, c_b, NewCap, OldCap;
  if (Capture == AXIS_X){
    ip_b = input_b();
    NewCap = get_capture(2);////////////////////////////////////////////// Capture
    PTR_ENCODER->Interval = NewCap - OldCap;
    OldCap = NewCap;
    c_a = (ip_b & (1 << Pin_A) ) >> Pin_A;
    c_b = (ip_b & (1 << Pin_B) ) >> Pin_B;
    if(c_a != c_b){
      //direction = CW;
      PTR_ENCODER->distance -= 1;
    }
    else{
      //direction = CCW;
      PTR_ENCODER->distance += 1;
    }
  }
  else{
    ip_b = input_b();
    NewCap = get_capture(4);////////////////////////////////////////////// Capture
    PTR_ENCODER->Interval = NewCap - OldCap;
    OldCap = NewCap;
    c_a = (ip_b & (1 << Pin_A) ) >> Pin_A;
    c_b = (ip_b & (1 << Pin_B) ) >> Pin_B;
    if(c_a != c_b){
      //direction = CW;
      PTR_ENCODER->distance -= 1;
    }
    else{
      //direction = CCW;
      PTR_ENCODER->distance += 1;
    }
  }
	//printf(" Distance ! =%d  \n" ,(int) PTR_ENCODER->distance);
}


void Encod_Get_A(unsigned int8 Capture, Encoder *PTR_ENCODER, int16u Pin_A, int16u Pin_B){
  int16u ip_b, c_a, c_b, NewCap, OldCap;
  if (Capture == AXIS_X){
    ip_b = input_b();
    NewCap = get_capture(1);////////////////////////////////////////////// Capture
    PTR_ENCODER->Interval = NewCap - OldCap;
    OldCap = NewCap;
    c_a = (ip_b & (1 << Pin_A) ) >> Pin_A;
    c_b = (ip_b & (1 << Pin_B) ) >> Pin_B;
    if(c_a == c_b){
      //direction = CW;
      PTR_ENCODER->distance -= 1;
    }
    else{
      //direction = CCW;
      PTR_ENCODER->distance += 1;
    }
  }
  else{
    ip_b = input_b();
    NewCap = get_capture(3);////////////////////////////////////////////// Capture
    PTR_ENCODER->Interval = NewCap - OldCap;
    OldCap = NewCap;
    c_a = (ip_b & (1 << Pin_A) ) >> Pin_A;
    c_b = (ip_b & (1 << Pin_B) ) >> Pin_B;
    if(c_a == c_b){
      //direction = CW;
      PTR_ENCODER->distance -= 1;
      
    }
    else{
      //direction = CCW;
      PTR_ENCODER->distance += 1;
    }
  }
	//printf("Distance ! = %d  \n" ,(int) PTR_ENCODER->distance);
}


void Control_POSITION_PID(unsigned int8 axis, float target, Encoder *PTR_ENCODER, PID_PARAMIT *PTR_PID_PARAM,float tolerance) {
  float pwm;
  PTR_PID_PARAM->currentPosition = ((7.5 * 22* (float)(PTR_ENCODER->distance) * 6)/(7 * 180 * 64)); 
  PTR_PID_PARAM->error = target - PTR_PID_PARAM->currentPosition;
  PTR_PID_PARAM->integral_error = PTR_PID_PARAM->integral_error + PTR_PID_PARAM->error;
  PTR_PID_PARAM->u = (PTR_PID_PARAM->K_p * PTR_PID_PARAM->error + PTR_PID_PARAM->K_i * PTR_PID_PARAM->integral_error + PTR_PID_PARAM->K_d * (PTR_PID_PARAM->error - PTR_PID_PARAM->previous_error));
  if(abs(PTR_PID_PARAM->error) >=tolerance){
    pwm = abs(PTR_PID_PARAM->u);
  }
  else {
    pwm = 0;
  }
  if( PTR_PID_PARAM->u > 0){
    DIREC_PID = CCW;
  }
  else{
    DIREC_PID = CW;
  }
 // printf(" DIREC PIC = %d %d \n",DIREC_PID,axis);
  drive_motor(axis,DIREC_PID,pwm);
  PTR_PID_PARAM->previous_error = PTR_PID_PARAM->error;
} 



void Velocity_POSITION_PID(unsigned int8 axis, float target, Encoder *PTR_ENCODER, PID_PARAMIT *PTR_PID_PARAM,float tolerance) {
  float pwm;

  //printf(" TARGET = %d %d %d %u\n",axis,(int)target,(int)PTR_PID_PARAM->currentPosition,PTR_ENCODER->distance); 
  PTR_PID_PARAM->currentPosition = ((7.5 * 22* (float)(PTR_ENCODER->distance) * 6)/(7 * 180 * 64)); 
    
  
  PTR_PID_PARAM->error = target - PTR_PID_PARAM->currentPosition;
 
  PTR_PID_PARAM->delta_u = (PTR_PID_PARAM->K_p + PTR_PID_PARAM->K_i + PTR_PID_PARAM->K_d)*PTR_PID_PARAM->error - (PTR_PID_PARAM->K_p + 2*PTR_PID_PARAM->K_d)*PTR_PID_PARAM->previous_error + PTR_PID_PARAM->K_d*PTR_PID_PARAM->previous_previous_error;
  PTR_PID_PARAM->u = PTR_PID_PARAM->previous_u + PTR_PID_PARAM->delta_u;
 
//printf(" TARGET = %d %d %d %d\n",axis,(int)target,(int)PTR_PID_PARAM->currentPosition,(int)PTR_PID_PARAM->u); 
 //printf("\nY = %d , X = %d\n",(int)MotorY_PID.currentPosition,(int)MotorX_PID.currentPosition );
	 
if(abs(PTR_PID_PARAM->error) > tolerance){
    pwm = abs(PTR_PID_PARAM->u);
  }
  else {
    pwm = 0;
  }
  if( PTR_PID_PARAM->u > 0){
    DIREC_PID = CCW;
  }
  else{
    DIREC_PID = CW;
  } 
  //printf(" DIREC %d %d \n",DIREC_PID,axis);
  drive_motor(axis,DIREC_PID,pwm);
  PTR_PID_PARAM->previous_u = PTR_PID_PARAM->u;
  PTR_PID_PARAM->previous_previous_error = PTR_PID_PARAM->previous_error;
  PTR_PID_PARAM->previous_error = PTR_PID_PARAM->error;
  
} 



void PackageSerial(int8u instruction, int8u *Package, PID_PARAMIT *PTR_PID_PARAMX, PID_PARAMIT *PTR_PID_PARAMY){
  int8u checksum;
  int length = 0;
  Package[0] = 0xff;
  Package[1] = 0xff;
  Package[2] = 1;
  Package[3] = instruction;
  switch (instruction){
    case 1 :
      Package[4] = 5;
      Package[5] = (int8u)((0xff00 & (int16u)PTR_PID_PARAMX->currentPosition) >> 8 );
      Package[6] = (int8u)((0x00ff & (int16u)PTR_PID_PARAMX->currentPosition));
      Package[7] = (int8u)((0xff00 & (int16u)PTR_PID_PARAMY->currentPosition) >> 8 );
      Package[8] = (int8u)((0x00ff & (int16u)PTR_PID_PARAMY->currentPosition));
      length = Package[4];
      for (int i = 2; i < 4+length;i++ ){
        checksum += Package[i];
      }
      checksum =(~checksum) & 0x00ff;
      Package[9] = checksum;
      break;
    case 2 :
      Package[4] = 1;
      Package[5] = 0xFB;
      break;
    case 3 :
      Package[4] = 1;
      Package[5] = 0xFA;

  }
  
}

