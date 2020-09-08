/*
 * Houghline_real_fast_2.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Houghline_real_fast_2".
 *
 * Model version              : 1.132
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Feb 25 15:36:19 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Houghline_real_fast_2_h_
#define RTW_HEADER_Houghline_real_fast_2_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Houghline_real_fast_2_COMMON_INCLUDES_
# define Houghline_real_fast_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "math.h"
#include "viphough_rt.h"
#include "vipdrawtext_rt.h"
#endif                                 /* Houghline_real_fast_2_COMMON_INCLUDES_ */

#include "Houghline_real_fast_2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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
  real32_T Switch[2764800];            /* '<Root>/Switch' */
  real_T EdgeDetection_o2[144900];     /* '<S4>/Edge Detection' */
  real_T HoughTransform_o1[482760];    /* '<S5>/Hough Transform' */
  real_T ImageDataTypeConversion[153600];/* '<S1>/Image Data Type Conversion' */
  real_T BlurFilter[157136];           /* '<S1>/Blur Filter' */
  real_T SobelFilter[158916];          /* '<S1>/Sobel Filter' */
  real_T ImageDataTypeConversion_i[144900];/* '<S3>/Image Data Type Conversion' */
  real_T EdgeDetection_o1[144900];     /* '<S4>/Edge Detection' */
  real_T Saturation2[144900];          /* '<S4>/Saturation2' */
  real32_T FromMultimediaFile[2764800];/* '<Root>/From Multimedia File' */
  real32_T ColorSpaceConversion[921600];/* '<Root>/Color Space  Conversion' */
  real_T reducenoise1[144900];         /* '<S4>/reduce noise 1' */
  real32_T Selector[153600];           /* '<S1>/Selector' */
  real32_T DrawShapes2[2764800];       /* '<S2>/Draw Shapes2' */
  real32_T InsertText[2764800];        /* '<Root>/Insert Text' */
  boolean_T reducenoise[144900];       /* '<S4>/reduce noise ' */
  boolean_T Dilation[144900];          /* '<S4>/Dilation' */
  real_T HoughTransform_o2[360];       /* '<S5>/Hough Transform' */
  real_T HoughTransform_o3[1341];      /* '<S5>/Hough Transform' */
  int32_T HoughLines[4];               /* '<S5>/Hough Lines' */
  int32_T HoughLines1[4];              /* '<S5>/Hough Lines1' */
  boolean_T Autothreshold[144900];     /* '<S1>/Autothreshold' */
  boolean_T ImageDataTypeConversion2[144900];/* '<S4>/Image Data Type Conversion2' */
} B_Houghline_real_fast_2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T reducenoise1_ONE_PAD_IMG_DW[145761];/* '<S4>/reduce noise 1' */
  boolean_T reducenoise_ONE_PAD_IMG_DW[145761];/* '<S4>/reduce noise ' */
  real_T FromMultimediaFile_HostLib[137];/* '<Root>/From Multimedia File' */
  real_T FromMultimediaFile_AudioInfo[5];/* '<Root>/From Multimedia File' */
  real_T FromMultimediaFile_VideoInfo[11];/* '<Root>/From Multimedia File' */
  real_T FindLocalMaxima_TEMP_IN_DWORKS[482760];/* '<S5>/Find Local Maxima' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  real32_T ColorSpaceConversion_DWORK1[2764800];/* '<Root>/Color Space  Conversion' */
  real32_T InsertText_colorVectorDW[3];/* '<Root>/Insert Text' */
  int32_T BlurFilter_bSEnd[2];         /* '<S1>/Blur Filter' */
  int32_T BlurFilter_bSPreEdg[2];      /* '<S1>/Blur Filter' */
  int32_T BlurFilter_bSPstEdg[2];      /* '<S1>/Blur Filter' */
  int32_T BlurFilter_bSStart[2];       /* '<S1>/Blur Filter' */
  int32_T BlurFilter_inSEnd[2];        /* '<S1>/Blur Filter' */
  int32_T BlurFilter_inSStart[2];      /* '<S1>/Blur Filter' */
  int32_T BlurFilter_mLoc[10];         /* '<S1>/Blur Filter' */
  int32_T BlurFilter_mWidth[10];       /* '<S1>/Blur Filter' */
  int32_T BlurFilter_oSPreEdg[2];      /* '<S1>/Blur Filter' */
  int32_T BlurFilter_oSPstEdg[2];      /* '<S1>/Blur Filter' */
  int32_T BlurFilter_oSStart[2];       /* '<S1>/Blur Filter' */
  int32_T BlurFilter_oSecEnd[2];       /* '<S1>/Blur Filter' */
  int32_T BlurFilter_sCnt[2];          /* '<S1>/Blur Filter' */
  int32_T SobelFilter_bSEnd[2];        /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_bSPreEdg[2];     /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_bSPstEdg[2];     /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_bSStart[2];      /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_inSEnd[2];       /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_inSStart[2];     /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_mLoc[10];        /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_mWidth[10];      /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_oSPreEdg[2];     /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_oSPstEdg[2];     /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_oSStart[2];      /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_oSecEnd[2];      /* '<S1>/Sobel Filter' */
  int32_T SobelFilter_sCnt[2];         /* '<S1>/Sobel Filter' */
  int32_T reducenoise1_NUMNONZ_DW;     /* '<S4>/reduce noise 1' */
  int32_T reducenoise1_STREL_DW;       /* '<S4>/reduce noise 1' */
  int32_T reducenoise1_ERODE_OFF_DW;   /* '<S4>/reduce noise 1' */
  int32_T EdgeDetection_VO_DW[6];      /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<S4>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<S4>/Edge Detection' */
  int32_T reducenoise_NUMNONZ_DW;      /* '<S4>/reduce noise ' */
  int32_T reducenoise_STREL_DW;        /* '<S4>/reduce noise ' */
  int32_T reducenoise_ERODE_OFF_DW;    /* '<S4>/reduce noise ' */
  int32_T Dilation_NUMNONZ_DW;         /* '<S4>/Dilation' */
  int32_T Dilation_STREL_DW;           /* '<S4>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW;      /* '<S4>/Dilation' */
  int32_T InsertText_TxtLoc[2];        /* '<Root>/Insert Text' */
  uint32_T InsertText_TxtSelctn;       /* '<Root>/Insert Text' */
  uint8_T InsertText_RepBuf;           /* '<Root>/Insert Text' */
  uint8_T InsertText_VarHolder;        /* '<Root>/Insert Text' */
  uint8_T InsertText_StringDataDW[6];  /* '<Root>/Insert Text' */
  boolean_T BlurFilter_isHgtUpd[2];    /* '<S1>/Blur Filter' */
  boolean_T SobelFilter_isHgtUpd[2];   /* '<S1>/Sobel Filter' */
} DW_Houghline_real_fast_2_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  real_T EdgeDetection_VC_RTP[6];

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  real_T EdgeDetection_HC_RTP[6];

  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S5>/Hough Transform'
   */
  real_T HoughTransform_SINE_TABLE_RTP[181];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S5>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RTP;

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  int32_T EdgeDetection_VRO_RTP[6];

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  int32_T EdgeDetection_VCO_RTP[6];

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  int32_T EdgeDetection_HRO_RTP[6];

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<S4>/Edge Detection'
   */
  int32_T EdgeDetection_HCO_RTP[6];

  /* Computed Parameter: InsertText_GlyLBearings
   * Referenced by: '<Root>/Insert Text'
   */
  int32_T InsertText_GlyLBearings[256];

  /* Computed Parameter: InsertText_GlyTBearings
   * Referenced by: '<Root>/Insert Text'
   */
  int32_T InsertText_GlyTBearings[256];

  /* Computed Parameter: InsertText_GlyIndexes
   * Referenced by: '<Root>/Insert Text'
   */
  uint32_T InsertText_GlyIndexes[256];

  /* Computed Parameter: InsertText_GlyWidths
   * Referenced by: '<Root>/Insert Text'
   */
  uint16_T InsertText_GlyWidths[256];

  /* Computed Parameter: InsertText_GlyHeights
   * Referenced by: '<Root>/Insert Text'
   */
  uint16_T InsertText_GlyHeights[256];

  /* Computed Parameter: InsertText_GlyXAdvances
   * Referenced by: '<Root>/Insert Text'
   */
  uint16_T InsertText_GlyXAdvances[256];

  /* Computed Parameter: InsertText_StrArray
   * Referenced by: '<Root>/Insert Text'
   */
  uint8_T InsertText_StrArray[6];

  /* Computed Parameter: InsertText_GlyData
   * Referenced by: '<Root>/Insert Text'
   */
  uint8_T InsertText_GlyData[1200];
} ConstP_Houghline_real_fast_2_T;

/* Parameters (auto storage) */
struct P_Houghline_real_fast_2_T_ {
  real_T FindLocalMaxima_threshold;    /* Mask Parameter: FindLocalMaxima_threshold
                                        * Referenced by: '<S5>/Find Local Maxima'
                                        */
  real32_T InsertText_textColor[3];    /* Mask Parameter: InsertText_textColor
                                        * Referenced by: '<Root>/Insert Text'
                                        */
  real32_T InsertText_textOpacity;     /* Mask Parameter: InsertText_textOpacity
                                        * Referenced by: '<Root>/Insert Text'
                                        */
  int32_T DrawShapes_lineWidth;        /* Mask Parameter: DrawShapes_lineWidth
                                        * Referenced by: '<S2>/Draw Shapes'
                                        */
  int32_T DrawShapes1_lineWidth;       /* Mask Parameter: DrawShapes1_lineWidth
                                        * Referenced by: '<S2>/Draw Shapes1'
                                        */
  int32_T DrawShapes3_lineWidth;       /* Mask Parameter: DrawShapes3_lineWidth
                                        * Referenced by: '<S2>/Draw Shapes3'
                                        */
  int32_T InsertText_textLoc[2];       /* Mask Parameter: InsertText_textLoc
                                        * Referenced by: '<Root>/Insert Text'
                                        */
  real_T Startidxcrop_Value;           /* Expression: H_start
                                        * Referenced by: '<Root>/Start idx crop'
                                        */
  real_T blurmatrix_Value[25];         /* Expression: [0.04 0.04 0.04 0.04 0.04;0.04 0.04 0.04 0.04 0.04;0.04 0.04 0.04 0.04 0.04;0.04 0.04 0.04 0.04 0.04;0.04 0.04 0.04 0.04 0.04]
                                        * Referenced by: '<Root>/blur matrix'
                                        */
  real_T sobelverticalmatrix_Value[9]; /* Expression: [-2 0 2;-4 0 4;-2 0 2]
                                        * Referenced by: '<Root>/sobel vertical matrix'
                                        */
  real_T removeboundary_Value;         /* Expression: 10
                                        * Referenced by: '<S1>/remove boundary'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Constant1_Value[2];           /* Expression: [0 -50]
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: imagesize(2)/2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T DrawShapes_RTP_FILLCOLOR[3];/* Computed Parameter: DrawShapes_RTP_FILLCOLOR
                                        * Referenced by: '<S2>/Draw Shapes'
                                        */
  real32_T DrawShapes1_RTP_FILLCOLOR[3];/* Computed Parameter: DrawShapes1_RTP_FILLCOLOR
                                         * Referenced by: '<S2>/Draw Shapes1'
                                         */
  real32_T DrawShapes3_RTP_FILLCOLOR[3];/* Computed Parameter: DrawShapes3_RTP_FILLCOLOR
                                         * Referenced by: '<S2>/Draw Shapes3'
                                         */
  real32_T DrawShapes2_RTP_FILLCOLOR[3];/* Computed Parameter: DrawShapes2_RTP_FILLCOLOR
                                         * Referenced by: '<S2>/Draw Shapes2'
                                         */
  real32_T DrawShapes2_RTP_OPACITY;    /* Computed Parameter: DrawShapes2_RTP_OPACITY
                                        * Referenced by: '<S2>/Draw Shapes2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Houghline_real_fast_2_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

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

/* Block parameters (auto storage) */
extern P_Houghline_real_fast_2_T Houghline_real_fast_2_P;

/* Block signals (auto storage) */
extern B_Houghline_real_fast_2_T Houghline_real_fast_2_B;

/* Block states (auto storage) */
extern DW_Houghline_real_fast_2_T Houghline_real_fast_2_DW;

/* Constant parameters (auto storage) */
extern const ConstP_Houghline_real_fast_2_T Houghline_real_fast_2_ConstP;

/* Model entry point functions */
extern void Houghline_real_fast_2_initialize(void);
extern void Houghline_real_fast_2_step(void);
extern void Houghline_real_fast_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Houghline_real_fast__T *const Houghline_real_fast_2_M;

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
 * '<Root>' : 'Houghline_real_fast_2'
 * '<S1>'   : 'Houghline_real_fast_2/Crop & Filter'
 * '<S2>'   : 'Houghline_real_fast_2/Draw Graphic'
 * '<S3>'   : 'Houghline_real_fast_2/Lane Detection'
 * '<S4>'   : 'Houghline_real_fast_2/Lane Detection/Edge Detection'
 * '<S5>'   : 'Houghline_real_fast_2/Lane Detection/Hough Line'
 * '<S6>'   : 'Houghline_real_fast_2/Lane Detection/Hough Line/Theta_selector'
 */
#endif                                 /* RTW_HEADER_Houghline_real_fast_2_h_ */
