/*
 * savefile.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "savefile".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Mar 19 16:24:26 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "savefile.h"
#include "savefile_private.h"
#include "savefile_dt.h"

/* Block signals (auto storage) */
B_savefile_T savefile_B;

/* Block states (auto storage) */
DW_savefile_T savefile_DW;

/* Real-time model */
RT_MODEL_savefile_T savefile_M_;
RT_MODEL_savefile_T *const savefile_M = &savefile_M_;

/* Model step function */
void savefile_step(void)
{
  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(savefile_ConstP.V4L2VideoCapture_p1,
                        savefile_B.V4L2VideoCapture_o1,
                        savefile_B.V4L2VideoCapture_o2,
                        savefile_B.V4L2VideoCapture_o3);

  /* MATLABSystem: '<S1>/MATLAB System' */
  memcpy(&savefile_B.u0[0], &savefile_B.V4L2VideoCapture_o1[0], 307200U * sizeof
         (uint8_T));
  memcpy(&savefile_B.u1[0], &savefile_B.V4L2VideoCapture_o2[0], 307200U * sizeof
         (uint8_T));
  memcpy(&savefile_B.u2[0], &savefile_B.V4L2VideoCapture_o3[0], 307200U * sizeof
         (uint8_T));

  /* Start for MATLABSystem: '<S1>/MATLAB System' incorporates:
   *  MATLABSystem: '<S1>/MATLAB System'
   */
  MW_SDL_videoDisplayOutput(savefile_B.u0, savefile_B.u1, savefile_B.u2);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.016666666666666666s, 0.0s] */
    rtExtModeUpload(0, savefile_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.016666666666666666s, 0.0s] */
    if ((rtmGetTFinal(savefile_M)!=-1) &&
        !((rtmGetTFinal(savefile_M)-savefile_M->Timing.taskTime0) >
          savefile_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(savefile_M, "Simulation finished");
    }

    if (rtmGetStopRequested(savefile_M)) {
      rtmSetErrorStatus(savefile_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++savefile_M->Timing.clockTick0)) {
    ++savefile_M->Timing.clockTickH0;
  }

  savefile_M->Timing.taskTime0 = savefile_M->Timing.clockTick0 *
    savefile_M->Timing.stepSize0 + savefile_M->Timing.clockTickH0 *
    savefile_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void savefile_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)savefile_M, 0,
                sizeof(RT_MODEL_savefile_T));
  rtmSetTFinal(savefile_M, -1);
  savefile_M->Timing.stepSize0 = 0.016666666666666666;

  /* External mode info */
  savefile_M->Sizes.checksums[0] = (885321543U);
  savefile_M->Sizes.checksums[1] = (482481485U);
  savefile_M->Sizes.checksums[2] = (949433004U);
  savefile_M->Sizes.checksums[3] = (734142156U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    savefile_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(savefile_M->extModeInfo,
      &savefile_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(savefile_M->extModeInfo, savefile_M->Sizes.checksums);
    rteiSetTPtr(savefile_M->extModeInfo, rtmGetTPtr(savefile_M));
  }

  /* block I/O */
  (void) memset(((void *) &savefile_B), 0,
                sizeof(B_savefile_T));

  /* states (dwork) */
  (void) memset((void *)&savefile_DW, 0,
                sizeof(DW_savefile_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    savefile_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureInit(savefile_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 640U,
                      480U, 2U, 2U, 1U, 0.016666666666666666);

  /* Start for MATLABSystem: '<S1>/MATLAB System' */
  savefile_DW.obj.isInitialized = 0;
  savefile_DW.objisempty = true;
  savefile_DW.obj.isInitialized = 1;
  savefile_DW.obj.PixelFormatEnum = 1;
  MW_SDL_videoDisplayInit(savefile_DW.obj.PixelFormatEnum, 1, 1, 640.0, 480.0);

  /* End of Start for SubSystem: '<Root>/SDL Video Display' */
}

/* Model terminate function */
void savefile_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(savefile_ConstP.V4L2VideoCapture_p1);

  /* Start for MATLABSystem: '<S1>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S1>/MATLAB System'
   */
  if (savefile_DW.obj.isInitialized == 1) {
    savefile_DW.obj.isInitialized = 2;
    MW_SDL_videoDisplayTerminate(0, 0);
  }

  /* End of Start for MATLABSystem: '<S1>/MATLAB System' */
  /* End of Terminate for SubSystem: '<Root>/SDL Video Display' */
}
