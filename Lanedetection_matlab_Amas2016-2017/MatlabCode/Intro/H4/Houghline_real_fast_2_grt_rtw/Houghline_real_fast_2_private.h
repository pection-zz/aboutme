/*
 * Houghline_real_fast_2_private.h
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

#ifndef RTW_HEADER_Houghline_real_fast_2_private_h_
#define RTW_HEADER_Houghline_real_fast_2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real_T PadBConst_uD(const real_T u[], const int32_T uStride[], const
  int32_T idx[], const int32_T uStart[], const int32_T uEnd[], const int32_T
  sNumPreEdges, const int32_T sPreEdges[], const int32_T sNumPostEdges, const
  int32_T sPostEdges[], real_T padValue);
extern void Conv_M_IBConst_uD_hD_yD(const real_T h[], const int32_T hLoc[],
  const int32_T hDims[], const real_T u[], const int32_T uDims[], real_T y[],
  const int32_T yDims[], const int32_T yOrigin[], real_T padValue);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 /* RTW_HEADER_Houghline_real_fast_2_private_h_ */
