/*
 * savefile_types.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "savefile".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sat Mar 31 14:27:06 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_savefile_types_h_
#define RTW_HEADER_savefile_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_linux_blocks_SDLV_T
#define typedef_codertarget_linux_blocks_SDLV_T

typedef struct {
  int32_T isInitialized;
  int32_T PixelFormatEnum;
} codertarget_linux_blocks_SDLV_T;

#endif                                 /*typedef_codertarget_linux_blocks_SDLV_T*/

#ifndef typedef_struct_T_savefile_T
#define typedef_struct_T_savefile_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
  real_T f3[2];
} struct_T_savefile_T;

#endif                                 /*typedef_struct_T_savefile_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_savefile_T RT_MODEL_savefile_T;

#endif                                 /* RTW_HEADER_savefile_types_h_ */
