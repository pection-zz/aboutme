/*
 * savefile.h
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

#ifndef RTW_HEADER_savefile_h_
#define RTW_HEADER_savefile_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef savefile_COMMON_INCLUDES_
# define savefile_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SDL_video_display.h"
#include "v4l2_capture.h"
#endif                                 /* savefile_COMMON_INCLUDES_ */

#include "savefile_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T V4L2VideoCapture_o1[307200]; /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[307200]; /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[307200]; /* '<Root>/V4L2 Video Capture' */
  uint8_T u0[307200];
  uint8_T u1[307200];
  uint8_T u2[307200];
} B_savefile_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_SDLV_T obj; /* '<S1>/MATLAB System' */
  void *MATLABSystem_PWORK;            /* '<S1>/MATLAB System' */
  boolean_T objisempty;                /* '<S1>/MATLAB System' */
} DW_savefile_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: devName
   * Referenced by: '<Root>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_savefile_T;

/* Real-time Model Data Structure */
struct tag_RTM_savefile_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_savefile_T savefile_B;

/* Block states (auto storage) */
extern DW_savefile_T savefile_DW;

/* Constant parameters (auto storage) */
extern const ConstP_savefile_T savefile_ConstP;

/* Model entry point functions */
extern void savefile_initialize(void);
extern void savefile_step(void);
extern void savefile_terminate(void);

/* Real-time Model object */
extern RT_MODEL_savefile_T *const savefile_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'savefile'
 * '<S1>'   : 'savefile/SDL Video Display'
 */
#endif                                 /* RTW_HEADER_savefile_h_ */
