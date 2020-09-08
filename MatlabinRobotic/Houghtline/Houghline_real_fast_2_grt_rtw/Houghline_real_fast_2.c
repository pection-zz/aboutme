/*
 * Houghline_real_fast_2.c
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

#include "Houghline_real_fast_2.h"
#include "Houghline_real_fast_2_private.h"

/* Block signals (auto storage) */
B_Houghline_real_fast_2_T Houghline_real_fast_2_B;

/* Block states (auto storage) */
DW_Houghline_real_fast_2_T Houghline_real_fast_2_DW;

/* Real-time model */
RT_MODEL_Houghline_real_fast__T Houghline_real_fast_2_M_;
RT_MODEL_Houghline_real_fast__T *const Houghline_real_fast_2_M =
  &Houghline_real_fast_2_M_;
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

real_T PadBConst_uD(const real_T u[], const int32_T uStride[], const int32_T
                    idx[], const int32_T uStart[], const int32_T uEnd[], const
                    int32_T sNumPreEdges, const int32_T sPreEdges[], const
                    int32_T sNumPostEdges, const int32_T sPostEdges[], real_T
                    padValue)
{
  real_T uOut;
  int32_T edgeNum;
  boolean_T isOutside;

  /* S-Function (svip2dconv): '<S1>/Blur Filter' */
  /* For boundary sectors: */
  /* -check if index is outside of input bounds ... */
  /*   -if so then return pad extended value */
  /*   -else fetch input data at the index */
  isOutside = false;
  for (edgeNum = 0; edgeNum < sNumPreEdges; edgeNum++) {
    isOutside = (isOutside || (idx[sPreEdges[edgeNum]] <
      uStart[sPreEdges[edgeNum]]));
  }

  for (edgeNum = 0; edgeNum < sNumPostEdges; edgeNum++) {
    isOutside = (isOutside || (idx[sPostEdges[edgeNum]] >
      uEnd[sPostEdges[edgeNum]]));
  }

  if (isOutside) {
    /* return pad value */
    uOut = padValue;
  } else {
    /* linearize index and return input data */
    uOut = u[idx[0U] * uStride[0U] + idx[1U] * uStride[1U]];
  }

  /* End of S-Function (svip2dconv): '<S1>/Blur Filter' */
  return uOut;
}

void Conv_M_IBConst_uD_hD_yD(const real_T h[], const int32_T hLoc[], const
  int32_T hDims[], const real_T u[], const int32_T uDims[], real_T y[], const
  int32_T yDims[], const int32_T yOrigin[], real_T padValue)
{
  real_T acc;
  int32_T uOrigin[2];
  int32_T uEnd[2];
  int32_T uStride[2];
  int32_T hEnd[2];
  int32_T yEnd[2];
  int32_T mLoc[10];
  int32_T mWidth[10];
  int32_T hLoc_0;
  int32_T hEnd_0;
  int32_T uOrigin_0;
  int32_T uEnd_0;
  int32_T yPost;
  int32_T hPost;
  int32_T bPreEnd;
  int32_T bPostEnd;
  boolean_T isSEmpty;
  int32_T sStart[2];
  int32_T sEnd[2];
  int32_T offset[2];
  int32_T idxB[2];
  int32_T idxALin[2];
  int32_T idxBLin[2];
  int32_T hIdxA[2];
  int32_T sStart_0[2];
  int32_T sEnd_0[2];
  int32_T sPreEdges[2];
  int32_T sPostEdges[2];
  int32_T c[2];
  int8_T o[5];
  boolean_T isEnd;
  boolean_T dimIsPre;
  int32_T offset_0[2];
  int32_T idxA[2];
  int32_T idxB_0[2];
  int32_T idxBLin_0[2];
  int32_T hIdxA_0[2];
  int32_T hIdxB[2];
  int32_T idxHLin;
  real_T uI;

  /* S-Function (svip2dconv): '<S1>/Blur Filter' */
  uOrigin[0U] = 0;
  uEnd[0U] = uDims[0U] - 1;
  uStride[0U] = 1;
  uOrigin[1U] = 0;
  uEnd[1U] = uDims[1U] - 1;
  uStride[1U] = uDims[0U];
  hEnd[0U] = hDims[0U] - 1;
  hEnd[1U] = hDims[1U] - 1;
  yEnd[0U] = yDims[0U] - 1;
  yEnd[1U] = yDims[1U] - 1;

  /*  COMPUTE MARGINS BETWEEN INPUT AND OUTPUT       */
  /* =============================================== */
  /*      _________________________________________  */
  /*     |u                                        | */
  /*     |                                         | */
  /*     |         ______________________          | */
  /*     |        |y                     |         | */
  /*     |        |                      |         | */
  /*     |<-yPre->|                      |<-yPost->| */
  /*     |        |                      |         | */
  /*  */
  /*  KERNEL MARIGINS                               */
  /* ============================================== */
  /*      ____________________  */
  /*     |h                   | */
  /*     |        |<--hPost-->| */
  /*     |        |           | */
  /*     |        x(hCenter)  | */
  /*     |<-hPre->|           | */
  /*     |        |           | */
  /*  */
  /*  MARGINS (Valid, Boundary and Outside) definitions: */
  /*  Valid Margin: Processing region where entire kernel stays inside input boundaries. All input data thus considered is 'valid' data */
  /*  Boundary Margin: Processing region where part of kernel stays inside the input boundaries and part of it goes outside input boundaries. */
  /*  Outside Margin: Processing region where entire kernel stays outside the input boundaries and never touches input data. In most situations this region does not need to be processed. Instead output pad values are filled in */
  /* =========================================================== */
  /*   y |        |        |               |         |         | */
  /*     |<-oPre->|<-bPre->|<----valid---->|<-bPost->|<-oPost->| */
  /*     |        |        |               |         |         | */
  /*  */
  /*  All margin locations are stored relative to the output origin */
  /* margins between y and u */
  uOrigin_0 = -yOrigin[0];
  yPost = (yOrigin[0] + yEnd[0]) - uEnd[0];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[0] + hEnd[0];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  uEnd_0 = uOrigin_0 - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hEnd_0 = yPost + hLoc[0];
  uOrigin_0 -= hLoc[0];
  hPost += yPost;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (uEnd_0 < 0) {
    hLoc_0 = 0;
  } else if (uEnd_0 > yDims[0]) {
    hLoc_0 = yDims[0];
  } else {
    hLoc_0 = uEnd_0;
  }

  /* boundary Pre */
  /* saturate */
  if (uOrigin_0 < 0) {
    uOrigin_0 = 0;
  } else {
    if (uOrigin_0 > yDims[0]) {
      uOrigin_0 = yDims[0];
    }
  }

  if (uEnd_0 < 0) {
    uEnd_0 = 0;
  } else {
    if (uEnd_0 > yDims[0]) {
      uEnd_0 = yDims[0];
    }
  }

  uEnd_0 = uOrigin_0 - uEnd_0;
  uOrigin_0 = yOrigin[0] + hLoc_0;

  /* outer Post */
  /* saturate */
  if (hEnd_0 < 0) {
    yPost = 0;
  } else if (hEnd_0 > yDims[0]) {
    yPost = yDims[0];
  } else {
    yPost = hEnd_0;
  }

  idxHLin = ((yOrigin[0] + yEnd[0]) - yPost) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[0]) {
      hPost = yDims[0];
    }
  }

  if (hEnd_0 < 0) {
    hEnd_0 = 0;
  } else {
    if (hEnd_0 > yDims[0]) {
      hEnd_0 = yDims[0];
    }
  }

  hEnd_0 = hPost - hEnd_0;
  hPost = idxHLin - hEnd_0;
  bPreEnd = uOrigin_0 + uEnd_0;
  bPostEnd = hPost + hEnd_0;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd_0 = hPost - uOrigin_0;
    hPost = bPreEnd;
    hEnd_0 = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  mLoc[0] = uOrigin_0 + uEnd_0;
  mWidth[0] = (((yDims[0] - hLoc_0) - yPost) - uEnd_0) - hEnd_0;
  mLoc[2] = uOrigin_0;
  mWidth[2] = uEnd_0;
  mLoc[4] = hPost;
  mWidth[4] = hEnd_0;
  mLoc[6] = yOrigin[0];
  mWidth[6] = hLoc_0;
  mLoc[8] = idxHLin;
  mWidth[8] = yPost;

  /* margins between y and u */
  uOrigin_0 = -yOrigin[1];
  yPost = (yOrigin[1] + yEnd[1]) - uEnd[1];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[1] + hEnd[1];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  uEnd_0 = uOrigin_0 - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hEnd_0 = yPost + hLoc[1];
  uOrigin_0 -= hLoc[1];
  hPost += yPost;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (uEnd_0 < 0) {
    hLoc_0 = 0;
  } else if (uEnd_0 > yDims[1]) {
    hLoc_0 = yDims[1];
  } else {
    hLoc_0 = uEnd_0;
  }

  /* boundary Pre */
  /* saturate */
  if (uOrigin_0 < 0) {
    uOrigin_0 = 0;
  } else {
    if (uOrigin_0 > yDims[1]) {
      uOrigin_0 = yDims[1];
    }
  }

  if (uEnd_0 < 0) {
    uEnd_0 = 0;
  } else {
    if (uEnd_0 > yDims[1]) {
      uEnd_0 = yDims[1];
    }
  }

  uEnd_0 = uOrigin_0 - uEnd_0;
  uOrigin_0 = yOrigin[1] + hLoc_0;

  /* outer Post */
  /* saturate */
  if (hEnd_0 < 0) {
    yPost = 0;
  } else if (hEnd_0 > yDims[1]) {
    yPost = yDims[1];
  } else {
    yPost = hEnd_0;
  }

  idxHLin = ((yOrigin[1] + yEnd[1]) - yPost) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[1]) {
      hPost = yDims[1];
    }
  }

  if (hEnd_0 < 0) {
    hEnd_0 = 0;
  } else {
    if (hEnd_0 > yDims[1]) {
      hEnd_0 = yDims[1];
    }
  }

  hEnd_0 = hPost - hEnd_0;
  hPost = idxHLin - hEnd_0;
  bPreEnd = uOrigin_0 + uEnd_0;
  bPostEnd = hPost + hEnd_0;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd_0 = hPost - uOrigin_0;
    hPost = bPreEnd;
    hEnd_0 = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  mLoc[1] = uOrigin_0 + uEnd_0;
  mWidth[1] = (((yDims[1] - hLoc_0) - yPost) - uEnd_0) - hEnd_0;
  mLoc[3] = uOrigin_0;
  mWidth[3] = uEnd_0;
  mLoc[5] = hPost;
  mWidth[5] = hEnd_0;
  mLoc[7] = yOrigin[1];
  mWidth[7] = hLoc_0;
  mLoc[9] = idxHLin;
  mWidth[9] = yPost;

  /*  ////////////////////////////////////////// */
  /*  COMPUTE INSIDE SECTOR                      */
  /*  ////////////////////////////////////////// */
  /*  ========================================== */
  /*  Original arrangement of sectors            */
  /*  ========================================== */
  /*   |   3   |   1   |   0   |   2   |   4   | */
  /*   | OutPre| BndPre| Inside|BndPost|OutPost| */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,3) | (3,1) | (3,0) | (3,2) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,3) | (1,1) | (1,0) | (1,2) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*   |       |       | VALID |       |       | */
  /*  0| (0,3) | (0,1) | (0,0) | (0,2) | (0,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,3) | (2,1) | (2,0) | (2,2) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,3) | (4,1) | (4,0) | (4,2) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /*  Sectors rearranged in order from 0 to 4 */
  /*  ========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |///////|       |       |       |       | */
  /*   |/VALID/|       |       |       |       | */
  /*  0|/(0,0)/| (0,1) | (0,2) | (0,3) | (0,4) | */
  /*   |///////|       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,0) | (1,1) | (1,2) | (1,3) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,0) | (2,1) | (2,2) | (2,3) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /* setup counter for valid sector, that is 0 in all dims */
  /* compute inside sector */
  /* compute sector if not empty */
  if (!((mWidth[0] <= 0) || (mWidth[1] <= 0))) {
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* setup indices for the loops */
    /* Origin stores the origin of Y with respect to U */
    /*  where the origin of Y is at its top left corner */
    /* Compute offset between origin of Y and origin of U(0,0) */
    offset[0U] = -yOrigin[0U];
    offset[1U] = -yOrigin[1U];

    /* sector start and end were computed relative to U */
    /* make them relative to Y by adding offset */
    sStart[0U] = mLoc[0] + offset[0U];
    sEnd[0U] = ((mLoc[0] + mWidth[0]) + offset[0U]) - 1;
    sStart[1U] = mLoc[1] + offset[1U];
    sEnd[1U] = ((mLoc[1] + mWidth[1]) + offset[1U]) - 1;

    /* adjust offset for kernel center */
    offset[0U] -= hLoc[0U];
    offset[1U] -= hLoc[1U];
    uOrigin_0 = (hEnd[0U] + 1) * (hEnd[1U] + 1);

    /* loop kernel over data */
    idxB[1U] = sStart[1U];
    while (idxB[1U] <= sEnd[1U]) {
      idxALin[1U] = (idxB[1U] - offset[1U]) * uDims[0U];
      idxBLin[1U] = yDims[0U] * idxB[1U];
      idxB[0U] = sStart[0U];
      while (idxB[0U] <= sEnd[0U]) {
        idxALin[0U] = (idxB[0U] - offset[0U]) + idxALin[1U];
        idxBLin[0U] = idxBLin[1U] + idxB[0U];
        yPost = idxALin[0U];

        /* loop over kernel and compute conv/corr */
        idxHLin = uOrigin_0 - 1;
        acc = 0.0;

        /* loop over kernel */
        hIdxA[1U] = 0;
        while (hIdxA[1U] <= hEnd[1U]) {
          hIdxA[0U] = 0;
          while (hIdxA[0U] <= hEnd[0U]) {
            acc += u[yPost] * h[idxHLin];
            yPost++;
            idxHLin--;
            hIdxA[0U]++;
          }

          yPost = (yPost + uDims[0U]) - hDims[0U];
          hIdxA[1U]++;
        }

        if (idxBLin[0U] >= 0) {
          y[idxBLin[0U]] = acc;
        }

        idxB[0U]++;
      }

      idxB[1U]++;
    }
  }

  /*  ////////////////////////////////////////// */
  /*  COMPUTE ON-BOUNDARY SECTORS                */
  /*  ////////////////////////////////////////// */
  /* =========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |       |///////|///////|       |       | */
  /*   | VALID |///////|///////|       |       | */
  /*  0| (0,0) |/(0,1)/|/(0,2)/| (0,3) | (0,4) | */
  /*   |       |///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  1|/(1,0)/|/(1,1)/|/(1,2)/| (1,3) | (1,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  2|/(2,0)/|/(2,1)/|/(2,2)/| (2,3) | (2,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  o[0U] = 0;
  o[1U] = 1;
  o[2U] = 2;
  o[3U] = 3;
  o[4U] = 4;
  isEnd = false;
  c[1U] = 0;

  /* if hDims < uDims then the all INSIDE sector will not be pushed into the boundary sectors... hence the counter needs to skip the all INSIDEs sector and start from one sector down. */
  c[0U] = 1;
  while (!isEnd) {
    yPost = 0;
    hPost = 0;

    /* compute on-boundary sector */
    /* compute sector if not empty */
    if (!((mWidth[o[c[0U]] << 1] <= 0) || (mWidth[(o[c[1U]] << 1) + 1] <= 0))) {
      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (o[c[0]] == 0);
      dimIsPre = ((o[c[0]] == 3) || (o[c[0]] == 1));
      if (dimIsPre || isSEmpty) {
        sPreEdges[0] = 0;
        yPost = 1;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        sPostEdges[0] = 0;
        hPost = 1;
      }

      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (o[c[1]] == 0);
      dimIsPre = ((o[c[1]] == 3) || (o[c[1]] == 1));
      if (dimIsPre || isSEmpty) {
        sPreEdges[yPost] = 1;
        yPost++;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        sPostEdges[hPost] = 1;
        hPost++;
      }

      /* setup indices for the loops */
      /* Origin stores the origin of Y with respect to U */
      /*  where the origin of Y is at its top left corner */
      /* Compute offset between origin of Y and origin of U(0,0) */
      offset_0[0U] = -yOrigin[0U];
      offset_0[1U] = -yOrigin[1U];

      /* sector start and end were computed relative to U */
      /* make them relative to Y by adding offset */
      sStart_0[0U] = mLoc[o[c[0]] << 1] + offset_0[0U];
      sEnd_0[0U] = ((mLoc[o[c[0]] << 1] + mWidth[o[c[0]] << 1]) + offset_0[0U])
        - 1;
      sStart_0[1U] = mLoc[(o[c[1]] << 1) + 1] + offset_0[1U];
      sEnd_0[1U] = ((mLoc[(o[c[1]] << 1) + 1] + mWidth[(o[c[1]] << 1) + 1]) +
                    offset_0[1U]) - 1;

      /* adjust offset for kernel center */
      offset_0[0U] -= hLoc[0U];
      offset_0[1U] -= hLoc[1U];
      uOrigin_0 = (hEnd[0U] + 1) * (hEnd[1U] + 1);

      /* loop kernel over data */
      idxB_0[1U] = sStart_0[1U];
      while (idxB_0[1U] <= sEnd_0[1U]) {
        idxA[1U] = idxB_0[1U] - offset_0[1U];
        idxBLin_0[1U] = yDims[0U] * idxB_0[1U];
        idxB_0[0U] = sStart_0[0U];
        while (idxB_0[0U] <= sEnd_0[0U]) {
          idxA[0U] = idxB_0[0U] - offset_0[0U];
          idxBLin_0[0U] = idxBLin_0[1U] + idxB_0[0U];

          /* loop over kernel and compute conv/corr */
          idxHLin = uOrigin_0 - 1;
          acc = 0.0;

          /* loop over kernel */
          hIdxA_0[1U] = 0;
          while (hIdxA_0[1U] <= hEnd[1U]) {
            hIdxB[1U] = idxA[1U] + hIdxA_0[1U];
            hIdxA_0[0U] = 0;
            while (hIdxA_0[0U] <= hEnd[0U]) {
              hIdxB[0U] = idxA[0U] + hIdxA_0[0U];
              uI = PadBConst_uD(&u[0U], &uStride[0U], &hIdxB[0U], &uOrigin[0U],
                                &uEnd[0U], yPost, &sPreEdges[0U], hPost,
                                &sPostEdges[0U], padValue);
              acc += uI * h[idxHLin];
              idxHLin--;
              hIdxA_0[0U]++;
            }

            hIdxA_0[1U]++;
          }

          if (idxBLin_0[0U] >= 0) {
            y[idxBLin_0[0U]] = acc;
          }

          idxB_0[0U]++;
        }

        idxB_0[1U]++;
      }
    }

    /* advance sector counter */
    uOrigin_0 = 0;
    while (uOrigin_0 < 2) {
      c[uOrigin_0]++;
      if (c[uOrigin_0] <= 2) {
        isEnd = false;
        uOrigin_0 = 2;
      } else {
        c[uOrigin_0] = 0;
        isEnd = true;
      }

      uOrigin_0++;
    }
  }

  /* End of S-Function (svip2dconv): '<S1>/Blur Filter' */
}

/* Model step function */
void Houghline_real_fast_2_step(void)
{
  /* local block i/o variables */
  real_T rtb_Selector_n;
  char_T *sErr;
  void *source_R;
  int32_T u1Dims[2];
  int32_T u2Dims[2];
  int32_T yDims[2];
  int32_T hLoc[2];
  int32_T yOrigin[2];
  int32_T u1Dims_0[2];
  int32_T u2Dims_0[2];
  int32_T yDims_0[2];
  int32_T hLoc_0[2];
  int32_T yOrigin_0[2];
  int32_T tmpOutRC[4];
  int32_T firstRow;
  boolean_T isMore;
  int32_T activeCol;
  int32_T parallelTo_XorYaxis2;
  int32_T idxRow2;
  int32_T idxTmp;
  int32_T idxEdgePre;
  int32_T numEdge;
  boolean_T prevEdgeIsVertical;
  int32_T loopEndIdx;
  int8_T idxTmpArray[2];
  int32_T loc;
  int32_T loc_0;
  int32_T idxOld;
  int32_T idxNew;
  int32_T numActiveEdge;
  boolean_T countTwice;
  int32_T edgeTmp;
  int32_T isPureFill;
  int32_T tmpOutRC_0[4];
  int8_T idxTmpArray_0[2];
  int8_T idxTmpArray_1[2];
  real_T Theta_out;
  uint8_T DrawShapes2_DW_PixCount[1280];
  real_T Autothreshold_P_DW[256];
  real_T Autothreshold_MU_DW[256];
  real_T scale;
  real_T cnt;
  int32_T idxMaxVal;
  int32_T ku;
  int32_T inIdx;
  int32_T outIdx;
  int32_T col;
  int32_T imgIdxLR;
  real_T accumThree;
  real_T accumFour;
  boolean_T done;
  int32_T q2;
  int32_T jRowsIn;
  real_T rtb_Sum1_i[4];
  real_T rtb_Sum[4];
  real_T rtb_Rho_ref;
  real_T DrawShapes_DW_Points[8];
  int32_T DrawShapes_DW_Polygon[36];
  real_T rtb_Rho_out;
  int32_T DrawShapes1_DW_Points[8];
  int32_T DrawShapes1_DW_Polygon[36];
  int32_T DrawShapes3_DW_Points[8];
  int32_T DrawShapes3_DW_Polygon[36];
  int32_T DrawShapes2_DW_Polygon[36];
  real_T rtb_Sum1;
  uint32_T rtb_FindLocalMaxima_o1[30];
  real_T rtb_TmpSignalConversionAtDrawSh[4];
  real32_T acc4_idx_0;
  real32_T acc1_idx_0;
  real32_T acc1_idx_2;
  int32_T line_idx_1;
  real32_T acc1_idx_1;
  real32_T acc1_idx_5;
  real32_T v;
  boolean_T exitg1;

  /* S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&Houghline_real_fast_2_B.FromMultimediaFile[0U];
  LibOutputs_FromMMFile(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U],
                        GetNullPointer(), GetNullPointer(), source_R,
                        GetNullPointer(), GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus(Houghline_real_fast_2_M, sErr);
    rtmSetStopRequested(Houghline_real_fast_2_M, 1);
  }

  /* End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  for (imgIdxLR = 0; imgIdxLR < 921600; imgIdxLR++) {
    Houghline_real_fast_2_B.ColorSpaceConversion[imgIdxLR] =
      (Houghline_real_fast_2_B.FromMultimediaFile[921600 + imgIdxLR] * 0.587F +
       Houghline_real_fast_2_B.FromMultimediaFile[imgIdxLR] * 0.299F) +
      Houghline_real_fast_2_B.FromMultimediaFile[1843200 + imgIdxLR] * 0.114F;
    if (Houghline_real_fast_2_B.ColorSpaceConversion[imgIdxLR] > 1.0F) {
      Houghline_real_fast_2_B.ColorSpaceConversion[imgIdxLR] = 1.0F;
    } else {
      if (Houghline_real_fast_2_B.ColorSpaceConversion[imgIdxLR] < 0.0F) {
        Houghline_real_fast_2_B.ColorSpaceConversion[imgIdxLR] = 0.0F;
      }
    }
  }

  /* End of S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */

  /* Selector: '<S1>/Selector' incorporates:
   *  Constant: '<Root>/Start idx crop'
   */
  imgIdxLR = (int32_T)Houghline_real_fast_2_P.Startidxcrop_Value;
  for (jRowsIn = 0; jRowsIn < 640; jRowsIn++) {
    memcpy(&Houghline_real_fast_2_B.Selector[jRowsIn * 240],
           &Houghline_real_fast_2_B.ColorSpaceConversion[(jRowsIn * 720 +
            imgIdxLR) + -721], 240U * sizeof(real32_T));
  }

  /* End of Selector: '<S1>/Selector' */

  /* S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' */
  for (imgIdxLR = 0; imgIdxLR < 153600; imgIdxLR++) {
    if (Houghline_real_fast_2_B.Selector[imgIdxLR] > 1.0F) {
      Houghline_real_fast_2_B.ImageDataTypeConversion[imgIdxLR] = 1.0;
    } else if (Houghline_real_fast_2_B.Selector[imgIdxLR] < 0.0F) {
      Houghline_real_fast_2_B.ImageDataTypeConversion[imgIdxLR] = 0.0;
    } else {
      Houghline_real_fast_2_B.ImageDataTypeConversion[imgIdxLR] =
        Houghline_real_fast_2_B.Selector[imgIdxLR];
    }
  }

  /* End of S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' */

  /* S-Function (svip2dconv): '<S1>/Blur Filter' incorporates:
   *  Constant: '<Root>/blur matrix'
   */
  u1Dims[0U] = 240;
  u1Dims[1U] = 640;
  u2Dims[0U] = 5;
  u2Dims[1U] = 5;

  /* set up kernel related coordinates */
  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc[0U] = -2;

  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc[1U] = -2;

  /* Region of Support (ROS) definition: A selected region that restricts the input space for processing. */
  /* ====================================================== */
  /*                       ---------------------            */
  /*                      |ROI                  |           */
  /*                      |                     |           */
  /*  ----------------------------------------------------  */
  /* | INPUT(u)           |                     |         | */
  /* |                    |                     |         | */
  /* |   ---------------------------------------------    | */
  /* |  | ROS             |OUTPUT(y)////////////|     |   | */
  /* |  |                 |/////////////////////|     |   | */
  /* |  |                  ---------------------      |   | */
  /* |  |                                             |   | */
  /* The user's output mode choices of 'Valid', 'Same as input' and 'Full' map onto correspending definitions of a rectangular ROS. */
  /* Output range support is computed as an intersection of ROS with Region of Interest (ROI) */
  /* ///////////////////// */
  /* begin ROS computation */
  /* compute ROS based on u, h and output mode */
  /* ROS is FULL - as far around input as the filter extends while touching the input */
  /* end ROS computation */
  /* /////////////////// */
  /* ///////////////////////// */
  /* begin y sizes computation */
  /* we need to compute yOrigin and yEnd */
  /* yOrigin definition: Location of center of reference (origin) of output (y) coordintate system with respect to input (u) coordinate system */
  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin[0U] = -2;
  yDims[0U] = 244;

  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin[1U] = -2;
  yDims[1U] = 644;

  /* make yOrigin same as roiLoc when y is empty */
  /* end y sizes computation */
  /* /////////////////////// */
  Conv_M_IBConst_uD_hD_yD(&Houghline_real_fast_2_P.blurmatrix_Value[0U], &hLoc
    [0U], &u2Dims[0U], &Houghline_real_fast_2_B.ImageDataTypeConversion[0U],
    &u1Dims[0U], &Houghline_real_fast_2_B.BlurFilter[0U], &yDims[0U], &yOrigin
    [0U], 0.0);

  /* S-Function (svip2dconv): '<S1>/Sobel Filter' incorporates:
   *  Constant: '<Root>/sobel vertical matrix'
   */
  /* check if any input is empty
   */
  u1Dims_0[0U] = 244;
  u1Dims_0[1U] = 644;
  u2Dims_0[0U] = 3;
  u2Dims_0[1U] = 3;

  /* set up kernel related coordinates */
  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc_0[0U] = -1;

  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc_0[1U] = -1;

  /* Region of Support (ROS) definition: A selected region that restricts the input space for processing. */
  /* ====================================================== */
  /*                       ---------------------            */
  /*                      |ROI                  |           */
  /*                      |                     |           */
  /*  ----------------------------------------------------  */
  /* | INPUT(u)           |                     |         | */
  /* |                    |                     |         | */
  /* |   ---------------------------------------------    | */
  /* |  | ROS             |OUTPUT(y)////////////|     |   | */
  /* |  |                 |/////////////////////|     |   | */
  /* |  |                  ---------------------      |   | */
  /* |  |                                             |   | */
  /* The user's output mode choices of 'Valid', 'Same as input' and 'Full' map onto correspending definitions of a rectangular ROS. */
  /* Output range support is computed as an intersection of ROS with Region of Interest (ROI) */
  /* ///////////////////// */
  /* begin ROS computation */
  /* compute ROS based on u, h and output mode */
  /* ROS is FULL - as far around input as the filter extends while touching the input */
  /* end ROS computation */
  /* /////////////////// */
  /* ///////////////////////// */
  /* begin y sizes computation */
  /* we need to compute yOrigin and yEnd */
  /* yOrigin definition: Location of center of reference (origin) of output (y) coordintate system with respect to input (u) coordinate system */
  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin_0[0U] = -1;
  yDims_0[0U] = 246;

  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin_0[1U] = -1;
  yDims_0[1U] = 646;

  /* make yOrigin same as roiLoc when y is empty */
  /* end y sizes computation */
  /* /////////////////////// */
  Conv_M_IBConst_uD_hD_yD(&Houghline_real_fast_2_P.sobelverticalmatrix_Value[0U],
    &hLoc_0[0U], &u2Dims_0[0U], &Houghline_real_fast_2_B.BlurFilter[0U],
    &u1Dims_0[0U], &Houghline_real_fast_2_B.SobelFilter[0U], &yDims_0[0U],
    &yOrigin_0[0U], 0.0);

  /* Selector: '<S1>/Selector1' incorporates:
   *  Constant: '<S1>/remove boundary'
   */
  /* check if any input is empty
   */
  imgIdxLR = (int32_T)Houghline_real_fast_2_P.removeboundary_Value;
  jRowsIn = (int32_T)Houghline_real_fast_2_P.removeboundary_Value;
  for (ku = 0; ku < 630; ku++) {
    memcpy(&Houghline_real_fast_2_B.reducenoise1[ku * 230],
           &Houghline_real_fast_2_B.SobelFilter[(ku * 246 + (jRowsIn * 246 +
             imgIdxLR)) + -247], 230U * sizeof(real_T));
  }

  /* End of Selector: '<S1>/Selector1' */

  /* S-Function (svipgraythresh): '<S1>/Autothreshold' */
  memset(&Autothreshold_P_DW[0], 0, sizeof(real_T) << 8U);
  memset(&Autothreshold_MU_DW[0], 0, sizeof(real_T) << 8U);
  for (imgIdxLR = 0; imgIdxLR < 144900; imgIdxLR++) {
    if (Houghline_real_fast_2_B.reducenoise1[imgIdxLR] < 0.0) {
      Autothreshold_P_DW[0]++;
    } else if (Houghline_real_fast_2_B.reducenoise1[imgIdxLR] > 1.0) {
      Autothreshold_P_DW[255]++;
    } else {
      Autothreshold_P_DW[(uint8_T)(Houghline_real_fast_2_B.reducenoise1[imgIdxLR]
        * 255.0 + 0.5)]++;
    }
  }

  for (imgIdxLR = 0; imgIdxLR < 256; imgIdxLR++) {
    Autothreshold_P_DW[imgIdxLR] /= 144900.0;
  }

  Autothreshold_MU_DW[0] = Autothreshold_P_DW[0];
  cnt = 2.0;
  for (imgIdxLR = 0; imgIdxLR < 255; imgIdxLR++) {
    Autothreshold_MU_DW[imgIdxLR + 1] = Autothreshold_P_DW[imgIdxLR + 1] * cnt +
      Autothreshold_MU_DW[imgIdxLR];
    cnt++;
    Autothreshold_P_DW[imgIdxLR + 1] += Autothreshold_P_DW[imgIdxLR];
  }

  idxMaxVal = 0;
  cnt = 0.0;
  for (imgIdxLR = 0; imgIdxLR < 256; imgIdxLR++) {
    scale = Autothreshold_P_DW[imgIdxLR] * Autothreshold_MU_DW[255] -
      Autothreshold_MU_DW[imgIdxLR];
    scale *= scale;
    scale /= (1.0 - Autothreshold_P_DW[imgIdxLR]) * Autothreshold_P_DW[imgIdxLR];
    if (scale > cnt) {
      cnt = scale;
      idxMaxVal = imgIdxLR;
    }
  }

  scale = (real_T)idxMaxVal / 255.0;
  for (imgIdxLR = 0; imgIdxLR < 144900; imgIdxLR++) {
    Houghline_real_fast_2_B.Autothreshold[imgIdxLR] =
      (Houghline_real_fast_2_B.reducenoise1[imgIdxLR] > scale);

    /* S-Function (svipscalenconvert): '<S3>/Image Data Type Conversion' */
    Houghline_real_fast_2_B.ImageDataTypeConversion_i[imgIdxLR] =
      Houghline_real_fast_2_B.Autothreshold[imgIdxLR];
  }

  /* End of S-Function (svipgraythresh): '<S1>/Autothreshold' */

  /* S-Function (svipmorphop): '<S4>/reduce noise 1' */
  idxMaxVal = 0;
  ku = 0;
  for (imgIdxLR = 0; imgIdxLR < 630; imgIdxLR++) {
    memcpy(&Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[idxMaxVal],
           &Houghline_real_fast_2_B.ImageDataTypeConversion_i[ku], 230U * sizeof
           (real_T));
    ku += 230;
    Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[idxMaxVal + 230] =
      (rtInf);
    idxMaxVal += 231;
  }

  Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[idxMaxVal] = (rtInf);
  idxMaxVal++;
  for (line_idx_1 = 0; line_idx_1 < 230; line_idx_1++) {
    Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[idxMaxVal] = (rtInf);
    idxMaxVal++;
  }

  inIdx = 0;
  outIdx = 0;
  if (Houghline_real_fast_2_DW.reducenoise1_STREL_DW == 0) {
    for (col = 0; col < 630; col++) {
      for (firstRow = 0; firstRow < 230; firstRow++) {
        scale = Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[inIdx +
          Houghline_real_fast_2_DW.reducenoise1_ERODE_OFF_DW];
        for (imgIdxLR = 1; imgIdxLR <
             Houghline_real_fast_2_DW.reducenoise1_NUMNONZ_DW; imgIdxLR++) {
          if (Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[inIdx +
              Houghline_real_fast_2_DW.reducenoise1_ERODE_OFF_DW] < scale) {
            scale = Houghline_real_fast_2_DW.reducenoise1_ONE_PAD_IMG_DW[inIdx +
              Houghline_real_fast_2_DW.reducenoise1_ERODE_OFF_DW];
          }
        }

        Houghline_real_fast_2_B.reducenoise1[outIdx] = scale;
        inIdx++;
        outIdx++;
      }

      inIdx++;
    }
  }

  /* End of S-Function (svipmorphop): '<S4>/reduce noise 1' */

  /* S-Function (svipedge): '<S4>/Edge Detection' */
  for (inIdx = 0; inIdx < 628; inIdx++) {
    for (outIdx = 0; outIdx < 228; outIdx++) {
      scale = 0.0;
      cnt = 0.0;
      q2 = ((inIdx + 1) * 230 + outIdx) + 1;
      for (ku = 0; ku < 6; ku++) {
        scale += Houghline_real_fast_2_B.reducenoise1[q2 +
          Houghline_real_fast_2_DW.EdgeDetection_VO_DW[ku]] *
          Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
        cnt += Houghline_real_fast_2_B.reducenoise1[q2 +
          Houghline_real_fast_2_DW.EdgeDetection_HO_DW[ku]] *
          Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
      }

      Houghline_real_fast_2_B.EdgeDetection_o1[q2] = scale;
      Houghline_real_fast_2_B.EdgeDetection_o2[q2] = cnt;
    }
  }

  for (inIdx = 0; inIdx < 628; inIdx++) {
    scale = 0.0;
    cnt = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    outIdx = (inIdx + 1) * 230;
    q2 = (inIdx + 1) * 230 + 229;
    for (ku = 0; ku < 6; ku++) {
      scale += Houghline_real_fast_2_B.reducenoise1[outIdx +
        Houghline_real_fast_2_DW.EdgeDetection_HOU_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
      cnt += Houghline_real_fast_2_B.reducenoise1[q2 +
        Houghline_real_fast_2_DW.EdgeDetection_HOD_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
      accumThree += Houghline_real_fast_2_B.reducenoise1[outIdx +
        Houghline_real_fast_2_DW.EdgeDetection_VOU_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
      accumFour += Houghline_real_fast_2_B.reducenoise1[q2 +
        Houghline_real_fast_2_DW.EdgeDetection_VOD_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
    }

    Houghline_real_fast_2_B.EdgeDetection_o1[outIdx] = accumThree;
    Houghline_real_fast_2_B.EdgeDetection_o2[outIdx] = scale;
    Houghline_real_fast_2_B.EdgeDetection_o1[q2] = accumFour;
    Houghline_real_fast_2_B.EdgeDetection_o2[q2] = cnt;
  }

  for (outIdx = 0; outIdx < 228; outIdx++) {
    scale = 0.0;
    cnt = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    inIdx = outIdx + 144671;
    for (ku = 0; ku < 6; ku++) {
      scale += Houghline_real_fast_2_B.reducenoise1[(outIdx +
        Houghline_real_fast_2_DW.EdgeDetection_VOL_DW[ku]) + 1] *
        Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
      cnt += Houghline_real_fast_2_B.reducenoise1[inIdx +
        Houghline_real_fast_2_DW.EdgeDetection_VOR_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
      accumThree += Houghline_real_fast_2_B.reducenoise1[(outIdx +
        Houghline_real_fast_2_DW.EdgeDetection_HOL_DW[ku]) + 1] *
        Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
      accumFour += Houghline_real_fast_2_B.reducenoise1[inIdx +
        Houghline_real_fast_2_DW.EdgeDetection_HOR_DW[ku]] *
        Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
    }

    Houghline_real_fast_2_B.EdgeDetection_o1[outIdx + 1] = scale;
    Houghline_real_fast_2_B.EdgeDetection_o2[outIdx + 1] = accumThree;
    Houghline_real_fast_2_B.EdgeDetection_o1[inIdx] = cnt;
    Houghline_real_fast_2_B.EdgeDetection_o2[inIdx] = accumFour;
  }

  scale = 0.0;
  cnt = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (ku = 0; ku < 6; ku++) {
    scale +=
      Houghline_real_fast_2_B.reducenoise1[Houghline_real_fast_2_DW.EdgeDetection_VOUL_DW
      [ku]] * Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
    cnt +=
      Houghline_real_fast_2_B.reducenoise1[Houghline_real_fast_2_DW.EdgeDetection_HOUL_DW
      [ku]] * Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
    accumThree += Houghline_real_fast_2_B.reducenoise1[229 +
      Houghline_real_fast_2_DW.EdgeDetection_VOLL_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
    accumFour += Houghline_real_fast_2_B.reducenoise1[229 +
      Houghline_real_fast_2_DW.EdgeDetection_HOLL_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
  }

  Houghline_real_fast_2_B.EdgeDetection_o1[0] = scale;
  Houghline_real_fast_2_B.EdgeDetection_o2[0] = cnt;
  Houghline_real_fast_2_B.EdgeDetection_o1[229] = accumThree;
  Houghline_real_fast_2_B.EdgeDetection_o2[229] = accumFour;
  scale = 0.0;
  cnt = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (ku = 0; ku < 6; ku++) {
    scale += Houghline_real_fast_2_B.reducenoise1[144670 +
      Houghline_real_fast_2_DW.EdgeDetection_VOUR_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
    cnt += Houghline_real_fast_2_B.reducenoise1[144670 +
      Houghline_real_fast_2_DW.EdgeDetection_HOUR_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
    accumThree += Houghline_real_fast_2_B.reducenoise1[144899 +
      Houghline_real_fast_2_DW.EdgeDetection_VOLR_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_VC_RTP[ku];
    accumFour += Houghline_real_fast_2_B.reducenoise1[144899 +
      Houghline_real_fast_2_DW.EdgeDetection_HOLR_DW[ku]] *
      Houghline_real_fast_2_ConstP.EdgeDetection_HC_RTP[ku];
  }

  Houghline_real_fast_2_B.EdgeDetection_o1[144670] = scale;
  Houghline_real_fast_2_B.EdgeDetection_o2[144670] = cnt;
  Houghline_real_fast_2_B.EdgeDetection_o1[144899] = accumThree;
  Houghline_real_fast_2_B.EdgeDetection_o2[144899] = accumFour;

  /* End of S-Function (svipedge): '<S4>/Edge Detection' */
  for (imgIdxLR = 0; imgIdxLR < 144900; imgIdxLR++) {
    /* Saturate: '<S4>/Saturation2' */
    if (Houghline_real_fast_2_B.EdgeDetection_o1[imgIdxLR] >
        Houghline_real_fast_2_P.Saturation2_UpperSat) {
      Houghline_real_fast_2_B.Saturation2[imgIdxLR] =
        Houghline_real_fast_2_P.Saturation2_UpperSat;
    } else if (Houghline_real_fast_2_B.EdgeDetection_o1[imgIdxLR] <
               Houghline_real_fast_2_P.Saturation2_LowerSat) {
      Houghline_real_fast_2_B.Saturation2[imgIdxLR] =
        Houghline_real_fast_2_P.Saturation2_LowerSat;
    } else {
      Houghline_real_fast_2_B.Saturation2[imgIdxLR] =
        Houghline_real_fast_2_B.EdgeDetection_o1[imgIdxLR];
    }

    /* End of Saturate: '<S4>/Saturation2' */

    /* S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion2' */
    Houghline_real_fast_2_B.ImageDataTypeConversion2[imgIdxLR] =
      !(Houghline_real_fast_2_B.Saturation2[imgIdxLR] == 0.0);
  }

  /* S-Function (svipmorphop): '<S4>/reduce noise ' */
  idxMaxVal = 0;
  ku = 0;
  for (imgIdxLR = 0; imgIdxLR < 630; imgIdxLR++) {
    memcpy(&Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[idxMaxVal],
           &Houghline_real_fast_2_B.ImageDataTypeConversion2[ku], 230U * sizeof
           (boolean_T));
    ku += 230;
    Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[idxMaxVal + 230] = true;
    idxMaxVal += 231;
  }

  Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[idxMaxVal] = true;
  idxMaxVal++;
  for (line_idx_1 = 0; line_idx_1 < 230; line_idx_1++) {
    Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[idxMaxVal] = true;
    idxMaxVal++;
  }

  inIdx = 0;
  outIdx = 0;
  for (idxMaxVal = 0; idxMaxVal < 630; idxMaxVal++) {
    for (ku = 0; ku < 230; ku++) {
      Houghline_real_fast_2_B.reducenoise[outIdx] = true;
      imgIdxLR = 0;
      while (imgIdxLR < Houghline_real_fast_2_DW.reducenoise_NUMNONZ_DW) {
        if (!Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[inIdx +
            Houghline_real_fast_2_DW.reducenoise_ERODE_OFF_DW]) {
          Houghline_real_fast_2_B.reducenoise[outIdx] = false;
          imgIdxLR = Houghline_real_fast_2_DW.reducenoise_NUMNONZ_DW;
        }

        imgIdxLR++;
      }

      inIdx++;
      outIdx++;
    }

    inIdx++;
  }

  /* End of S-Function (svipmorphop): '<S4>/reduce noise ' */

  /* S-Function (svipmorphop): '<S4>/Dilation' */
  memset(&Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[0], 0, 145761U *
         sizeof(boolean_T));
  for (inIdx = 0; inIdx < 144900; inIdx++) {
    if (Houghline_real_fast_2_B.reducenoise[inIdx]) {
      idxMaxVal = inIdx / 230;
      outIdx = (inIdx - idxMaxVal * 230) + idxMaxVal * 231;
      for (imgIdxLR = 0; imgIdxLR < Houghline_real_fast_2_DW.Dilation_NUMNONZ_DW;
           imgIdxLR++) {
        Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[outIdx +
          Houghline_real_fast_2_DW.Dilation_DILATE_OFF_DW] = true;
      }
    }
  }

  inIdx = 0;
  outIdx = 0;
  for (idxMaxVal = 0; idxMaxVal < 630; idxMaxVal++) {
    for (ku = 0; ku < 230; ku++) {
      Houghline_real_fast_2_B.Dilation[outIdx] =
        Houghline_real_fast_2_DW.reducenoise_ONE_PAD_IMG_DW[inIdx];
      outIdx++;
      inIdx++;
    }

    inIdx++;
  }

  /* End of S-Function (svipmorphop): '<S4>/Dilation' */

  /* S-Function (sviphough): '<S5>/Hough Transform' */
  MWVIP_Hough_D(&Houghline_real_fast_2_B.Dilation[0],
                &Houghline_real_fast_2_B.HoughTransform_o1[0],
                &Houghline_real_fast_2_ConstP.HoughTransform_SINE_TABLE_RTP[0],
                &Houghline_real_fast_2_ConstP.HoughTransform_FIRSTRHO_RTP, 230,
                630, 1341, 181);

  /* S-Function (svipfindlocalmax): '<S5>/Find Local Maxima' */
  ku = 0;
  done = false;
  for (imgIdxLR = 0; imgIdxLR < 482760; imgIdxLR++) {
    Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[imgIdxLR] =
      Houghline_real_fast_2_B.HoughTransform_o1[imgIdxLR];
  }

  memset(&rtb_FindLocalMaxima_o1[0], 0, 30U * sizeof(uint32_T));
  while (!done) {
    inIdx = 0;
    scale = Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (imgIdxLR = 0; imgIdxLR < 482760; imgIdxLR++) {
      if (Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[imgIdxLR] >
          scale) {
        inIdx = imgIdxLR;
        scale = Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[imgIdxLR];
      }
    }

    outIdx = inIdx % 1341;
    imgIdxLR = inIdx / 1341;
    if (Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[inIdx] >=
        Houghline_real_fast_2_P.FindLocalMaxima_threshold) {
      rtb_FindLocalMaxima_o1[ku] = (uint32_T)(1 + imgIdxLR);
      rtb_FindLocalMaxima_o1[15U + ku] = (uint32_T)(1 + outIdx);
      ku++;
      if (ku == 15) {
        done = true;
      }

      inIdx = outIdx - 2;
      if (!(inIdx > 0)) {
        inIdx = 0;
      }

      outIdx += 2;
      if (!(outIdx < 1340)) {
        outIdx = 1340;
      }

      q2 = imgIdxLR + 3;
      if (!(q2 < 359)) {
        q2 = 359;
      }

      line_idx_1 = imgIdxLR - 3;
      if (!(line_idx_1 > 0)) {
        line_idx_1 = 0;
      }

      while (line_idx_1 <= q2) {
        jRowsIn = line_idx_1 * 1341;
        for (imgIdxLR = inIdx; imgIdxLR <= outIdx; imgIdxLR++) {
          Houghline_real_fast_2_DW.FindLocalMaxima_TEMP_IN_DWORKS[imgIdxLR +
            jRowsIn] = 0.0;
        }

        line_idx_1++;
      }
    } else {
      done = true;
    }
  }

  /* MATLAB Function: '<S5>/Theta_selector' incorporates:
   *  S-Function (svipfindlocalmax): '<S5>/Find Local Maxima'
   */
  /* MATLAB Function 'Lane Detection/Hough Line/Theta_selector': '<S6>:1' */
  /* '<S6>:1:3' */
  /*  */
  if ((uint32_T)ku > 1U) {
    /* '<S6>:1:5' */
    /* '<S6>:1:6' */
    idxMaxVal = 0;
    exitg1 = false;
    while ((!exitg1) && (idxMaxVal < 15)) {
      /* '<S6>:1:6' */
      if (Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1] > 0.0) {
        /* '<S6>:1:7' */
        /* '<S6>:1:8' */
        rtb_Sum1 = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1];

        /* '<S6>:1:9' */
        rtb_Rho_ref = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
          rtb_FindLocalMaxima_o1[15 + idxMaxVal] - 1];
        exitg1 = true;
      } else {
        /* '<S6>:1:12' */
        rtb_Sum1 = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1];

        /* '<S6>:1:13' */
        rtb_Rho_ref = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
          rtb_FindLocalMaxima_o1[15 + idxMaxVal] - 1];
        idxMaxVal++;
      }
    }

    /* '<S6>:1:17' */
    idxMaxVal = 0;
    exitg1 = false;
    while ((!exitg1) && (idxMaxVal < 15)) {
      /* '<S6>:1:17' */
      if (Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1] < 0.0) {
        /* '<S6>:1:18' */
        /* '<S6>:1:19' */
        Theta_out = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1];

        /* '<S6>:1:20' */
        rtb_Rho_out = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
          rtb_FindLocalMaxima_o1[15 + idxMaxVal] - 1];
        exitg1 = true;
      } else {
        /* '<S6>:1:23' */
        Theta_out = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
          rtb_FindLocalMaxima_o1[idxMaxVal] - 1];

        /* '<S6>:1:24' */
        rtb_Rho_out = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
          rtb_FindLocalMaxima_o1[15 + idxMaxVal] - 1];
        idxMaxVal++;
      }
    }

    /*  error */
  } else {
    /* '<S6>:1:36' */
    rtb_Sum1 = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
      rtb_FindLocalMaxima_o1[0] - 1];

    /* '<S6>:1:37' */
    rtb_Rho_ref = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
      rtb_FindLocalMaxima_o1[15] - 1];

    /* '<S6>:1:38' */
    Theta_out = Houghline_real_fast_2_B.HoughTransform_o2[(int32_T)
      rtb_FindLocalMaxima_o1[0] - 1];

    /* '<S6>:1:39' */
    rtb_Rho_out = Houghline_real_fast_2_B.HoughTransform_o3[(int32_T)
      rtb_FindLocalMaxima_o1[15] - 1];
  }

  /* S-Function (sviphoughlines): '<S5>/Hough Lines' incorporates:
   *  MATLAB Function: '<S5>/Theta_selector'
   */
  idxMaxVal = 0;
  scale = (rtb_Rho_ref + 2.2204460492503131E-16) / (cos(rtb_Sum1) +
    2.2204460492503131E-16);

  /* part-1: top horizontal axis */
  cnt = floor(scale + 0.5);
  if ((cnt >= 0.0) && (cnt <= 629.0)) {
    tmpOutRC[0U] = 0;
    if (cnt >= 0.5) {
      tmpOutRC[1U] = (int32_T)floor(cnt + 0.5);
    } else {
      tmpOutRC[1U] = 0;
    }

    idxMaxVal = 1;
  }

  accumThree = (rtb_Rho_ref + 2.2204460492503131E-16) / (sin(rtb_Sum1) +
    2.2204460492503131E-16);

  /* part-2: left vertical axis */
  cnt = floor(accumThree + 0.5);
  if ((cnt >= 0.0) && (cnt <= 229.0)) {
    if (cnt >= 0.5) {
      tmpOutRC[idxMaxVal << 1] = (int32_T)floor(cnt + 0.5);
    } else {
      tmpOutRC[idxMaxVal << 1] = 0;
    }

    tmpOutRC[1 + (idxMaxVal << 1)] = 0;
    idxMaxVal++;
  }

  /* part-3: Right vertical axis */
  if (idxMaxVal < 2) {
    cnt = floor((scale - 629.0) * (accumThree / scale) + 0.5);
    if ((cnt >= 0.0) && (cnt <= 229.0)) {
      if (cnt >= 0.5) {
        tmpOutRC[idxMaxVal << 1] = (int32_T)floor(cnt + 0.5);
      } else {
        tmpOutRC[idxMaxVal << 1] = 0;
      }

      tmpOutRC[1 + (idxMaxVal << 1)] = 629;
      idxMaxVal++;
    }
  }

  /* part-4: bottom horizontal axis */
  if (idxMaxVal < 2) {
    cnt = floor((scale - scale / accumThree * 229.0) + 0.5);
    if ((cnt >= 0.0) && (cnt <= 629.0)) {
      tmpOutRC[idxMaxVal << 1] = 229;
      if (cnt >= 0.5) {
        tmpOutRC[1 + (idxMaxVal << 1)] = (int32_T)floor(cnt + 0.5);
      } else {
        tmpOutRC[1 + (idxMaxVal << 1)] = 0;
      }

      idxMaxVal++;
    }
  }

  if (idxMaxVal < 2) {
    tmpOutRC[0U] = -1;
    tmpOutRC[1U] = -1;
    tmpOutRC[2U] = -1;
    tmpOutRC[3U] = -1;
  }

  Houghline_real_fast_2_B.HoughLines[0] = tmpOutRC[1] + 1;
  Houghline_real_fast_2_B.HoughLines[1] = tmpOutRC[0] + 1;
  Houghline_real_fast_2_B.HoughLines[2] = tmpOutRC[3] + 1;
  Houghline_real_fast_2_B.HoughLines[3] = tmpOutRC[2] + 1;

  /* End of S-Function (sviphoughlines): '<S5>/Hough Lines' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<Root>/Start idx crop'
   *  Constant: '<S1>/remove boundary'
   */
  rtb_Selector_n = Houghline_real_fast_2_P.removeboundary_Value +
    Houghline_real_fast_2_P.Startidxcrop_Value;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S1>/remove boundary'
   */
  rtb_Sum[0] = (real_T)Houghline_real_fast_2_B.HoughLines[0] +
    Houghline_real_fast_2_P.removeboundary_Value;
  rtb_Sum[1] = (real_T)Houghline_real_fast_2_B.HoughLines[1] + rtb_Selector_n;
  rtb_Sum[2] = (real_T)Houghline_real_fast_2_B.HoughLines[2] +
    Houghline_real_fast_2_P.removeboundary_Value;
  rtb_Sum[3] = (real_T)Houghline_real_fast_2_B.HoughLines[3] + rtb_Selector_n;

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes' */
  if (Houghline_real_fast_2_P.DrawShapes_lineWidth == 1) {
    /* Compute output for unity line width
     */
    /* Copy the image from input to output. */
    memcpy(&Houghline_real_fast_2_B.Switch[0],
           &Houghline_real_fast_2_B.FromMultimediaFile[0], 2764800U * sizeof
           (real32_T));

    /* Update view port. */
    cnt = fabs(rtb_Sum[1]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum[1] + 0.5);
      } else {
        cnt = rtb_Sum[1] * 0.0;
      }
    } else {
      cnt = rtb_Sum[1];
    }

    numEdge = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum[0]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum[0] + 0.5);
      } else {
        cnt = rtb_Sum[0] * 0.0;
      }
    } else {
      cnt = rtb_Sum[0];
    }

    idxMaxVal = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum[3]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum[3] + 0.5);
      } else {
        cnt = rtb_Sum[3] * 0.0;
      }
    } else {
      cnt = rtb_Sum[3];
    }

    q2 = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum[2]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum[2] + 0.5);
      } else {
        cnt = rtb_Sum[2] * 0.0;
      }
    } else {
      cnt = rtb_Sum[2];
    }

    outIdx = (int32_T)cnt - 1;
    if ((numEdge != q2) || (idxMaxVal != outIdx)) {
      isMore = false;

      /* Find the visible portion of a line. */
      countTwice = false;
      prevEdgeIsVertical = false;
      done = false;
      ku = numEdge;
      line_idx_1 = idxMaxVal;
      inIdx = q2;
      idxEdgePre = outIdx;
      while (!done) {
        isPureFill = 0;
        col = 0;

        /* Determine viewport violations. */
        if (ku < 0) {
          isPureFill = 4;
        } else {
          if (ku > 719) {
            isPureFill = 8;
          }
        }

        if (inIdx < 0) {
          col = 4;
        } else {
          if (inIdx > 719) {
            col = 8;
          }
        }

        if (line_idx_1 < 0) {
          isPureFill |= 1U;
        } else {
          if (line_idx_1 > 1279) {
            isPureFill |= 2U;
          }
        }

        if (idxEdgePre < 0) {
          col |= 1U;
        } else {
          if (idxEdgePre > 1279) {
            col |= 2U;
          }
        }

        if (!(((uint32_T)isPureFill | col) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isMore = true;
        } else if (((uint32_T)isPureFill & col) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isMore = false;
        } else if ((uint32_T)isPureFill != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (countTwice) {
            ku = numEdge;
            line_idx_1 = idxMaxVal;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            countTwice = true;
          } else if ((isPureFill & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -ku * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 0;
            countTwice = true;
          } else if ((isPureFill & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - ku) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 719;
            countTwice = true;
          } else if ((isPureFill & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -line_idx_1 * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 0;
            countTwice = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - line_idx_1) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 1279;
            countTwice = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (prevEdgeIsVertical) {
            inIdx = q2;
            idxEdgePre = outIdx;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            prevEdgeIsVertical = true;
          } else if ((col & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -inIdx * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 0;
            prevEdgeIsVertical = true;
          } else if ((col & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - inIdx) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 719;
            prevEdgeIsVertical = true;
          } else if ((col & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -idxEdgePre * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 0;
            prevEdgeIsVertical = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - idxEdgePre) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 1279;
            prevEdgeIsVertical = true;
          }
        }
      }

      if (isMore) {
        /* Draw a line using Bresenham algorithm. */
        /* Initialize the Bresenham algorithm. */
        if (inIdx >= ku) {
          q2 = inIdx - ku;
        } else {
          q2 = ku - inIdx;
        }

        if (idxEdgePre >= line_idx_1) {
          outIdx = idxEdgePre - line_idx_1;
        } else {
          outIdx = line_idx_1 - idxEdgePre;
        }

        if (q2 > outIdx) {
          imgIdxLR = 1;
          numEdge = 720;
        } else {
          imgIdxLR = 720;
          numEdge = 1;
          jRowsIn = ku;
          ku = line_idx_1;
          line_idx_1 = jRowsIn;
          jRowsIn = inIdx;
          inIdx = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        if (ku > inIdx) {
          jRowsIn = ku;
          ku = inIdx;
          inIdx = jRowsIn;
          jRowsIn = line_idx_1;
          line_idx_1 = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        jRowsIn = inIdx - ku;
        if (line_idx_1 <= idxEdgePre) {
          idxMaxVal = 1;
          isPureFill = idxEdgePre - line_idx_1;
        } else {
          idxMaxVal = -1;
          isPureFill = line_idx_1 - idxEdgePre;
        }

        loopEndIdx = -((jRowsIn + 1) >> 1);
        idxEdgePre = ku * imgIdxLR + line_idx_1 * numEdge;
        idxMaxVal = idxMaxVal * numEdge + imgIdxLR;
        done = (ku <= inIdx);
        while (done) {
          Houghline_real_fast_2_B.Switch[idxEdgePre] =
            Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[0];
          line_idx_1 = idxEdgePre + 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[1];
          line_idx_1 += 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[2];

          /* Compute the next location using Bresenham algorithm. */
          /* Move to the next pixel location. */
          loopEndIdx += isPureFill;
          if (loopEndIdx >= 0) {
            loopEndIdx -= jRowsIn;
            idxEdgePre += idxMaxVal;
          } else {
            idxEdgePre += imgIdxLR;
          }

          ku++;
          done = (ku <= inIdx);
        }
      }
    }
  } else {
    /* Compute output for non-unity line width
     */
    /* Copy the image from input to output. */
    memcpy(&Houghline_real_fast_2_B.Switch[0],
           &Houghline_real_fast_2_B.FromMultimediaFile[0], 2764800U * sizeof
           (real32_T));

    /* Update view port. */
    /* ProcessStep-start-1
     */
    if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
      /* convertLinePts2PolygonPts
       */
      cnt = fabs(rtb_Sum[0]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum[0] + 0.5);
        } else {
          cnt = rtb_Sum[0] * 0.0;
        }
      } else {
        cnt = rtb_Sum[0];
      }

      outIdx = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum[1]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum[1] + 0.5);
        } else {
          cnt = rtb_Sum[1] * 0.0;
        }
      } else {
        cnt = rtb_Sum[1];
      }

      jRowsIn = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum[2]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum[2] + 0.5);
        } else {
          cnt = rtb_Sum[2] * 0.0;
        }
      } else {
        cnt = rtb_Sum[2];
      }

      isPureFill = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum[3]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum[3] + 0.5);
        } else {
          cnt = rtb_Sum[3] * 0.0;
        }
      } else {
        cnt = rtb_Sum[3];
      }

      numEdge = (int32_T)cnt - 1;
      ku = Houghline_real_fast_2_P.DrawShapes_lineWidth >> 1;

      /* getLineParams-1
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)jRowsIn;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)outIdx;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)outIdx / acc1_idx_0 + (real32_T)jRowsIn;
      }

      /* findPointOfIntersectionNormal-1
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes_DW_Points[0] = firstRow;
      DrawShapes_DW_Points[1] = idxRow2;

      /* findPointOfIntersectionNormal-2
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes_DW_Points[7] = loc;
      DrawShapes_DW_Points[6] = idxTmp;

      /* getLineParams-2
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)numEdge;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)isPureFill;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)isPureFill / acc1_idx_0 + (real32_T)numEdge;
      }

      /* findPointOfIntersectionNormal-3
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes_DW_Points[2] = firstRow;
      DrawShapes_DW_Points[3] = idxRow2;

      /* findPointOfIntersectionNormal-4
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes_DW_Points[5] = loc;
      DrawShapes_DW_Points[4] = idxTmp;
    }

    /* ProcessStep-after poly points-1
     */
    jRowsIn = 2;

    /* just before call for cgpolygon
     */
    if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
      /* just before call for cgpolygon-2
       */
      jRowsIn = 4;
    }

    /* Reset scanline states. */
    inIdx = 0;
    outIdx = 0;
    isMore = true;
    while (isMore) {
      /* Initialize the scanline. */
      /* Convert polygon vertices to boundaries. */
      done = false;
      numEdge = 0;
      idxEdgePre = inIdx;
      idxMaxVal = inIdx;
      idxTmpArray[0U] = (int8_T)(jRowsIn - 1);
      q2 = 0;
      while (q2 < 1) {
        /* start for loop
         */
        activeCol = ((idxTmpArray[0] << 1) + outIdx) + 1;
        parallelTo_XorYaxis2 = (idxTmpArray[0] << 1) + outIdx;
        idxTmp = idxTmpArray[0];
        col = ((idxTmpArray[0] - 1) << 1) + outIdx;
        firstRow = jRowsIn;
        if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] -
              0.5);
          } else {
            isPureFill = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] +
              0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes_DW_Points[col] < 0.0) {
            loc = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum[col] < 0.0) {
            loc = (int32_T)(rtb_Sum[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum[col] + 0.5);
          }
        }

        imgIdxLR = loc;
        while ((col >= 0) && (isPureFill - 1 == imgIdxLR - 1)) {
          idxTmp--;
          col = ((idxTmp - 1) << 1) + outIdx;
          firstRow--;
          if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes_DW_Points[col] < 0.0) {
              loc = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
            } else {
              loc = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_Sum[col] < 0.0) {
              loc = (int32_T)(rtb_Sum[col] - 0.5);
            } else {
              loc = (int32_T)(rtb_Sum[col] + 0.5);
            }
          }

          imgIdxLR = loc;
        }

        if (col < 0) {
          col = 0;
        }

        if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] -
              0.5);
          } else {
            isPureFill = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] +
              0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes_DW_Points[col] < 0.0) {
            loc = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum[col] < 0.0) {
            loc = (int32_T)(rtb_Sum[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum[col] + 0.5);
          }
        }

        isMore = (loc - 1 > isPureFill - 1);
        idxRow2 = outIdx + 1;
        col = outIdx;
        prevEdgeIsVertical = false;
        if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes_DW_Points[outIdx] < 0.0) {
            isPureFill = (int32_T)(DrawShapes_DW_Points[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)(DrawShapes_DW_Points[outIdx] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
            loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum[outIdx] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum[outIdx] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
            loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
          }
        }

        done = (loc - 1 == isPureFill - 1);
        for (imgIdxLR = 0; imgIdxLR < firstRow; imgIdxLR++) {
          if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes_DW_Points[col] < 0.0) {
              isPureFill = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
            } else {
              isPureFill = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
            }

            /* getLoc-1
             */
            if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
              loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
            } else {
              loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_Sum[col] < 0.0) {
              isPureFill = (int32_T)(rtb_Sum[col] - 0.5);
            } else {
              isPureFill = (int32_T)(rtb_Sum[col] + 0.5);
            }

            /* getLoc-2
             */
            if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
              loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
            } else {
              loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
            }
          }

          if (loc - 1 != isPureFill - 1) {
            if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes_DW_Points[col] < 0.0) {
                isPureFill = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
                loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_Sum[col] < 0.0) {
                isPureFill = (int32_T)(rtb_Sum[col] - 0.5);
              } else {
                isPureFill = (int32_T)(rtb_Sum[col] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
                loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
              }
            }

            if (loc - 1 < isPureFill - 1) {
              countTwice = false;
            } else {
              countTwice = true;
              idxTmp = activeCol;
              activeCol = idxRow2;
              idxRow2 = idxTmp;
              idxTmp = parallelTo_XorYaxis2;
              parallelTo_XorYaxis2 = col;
              col = idxTmp;
            }

            if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes_DW_Points[col] < 0.0) {
                isPureFill = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes_DW_Points[idxRow2] < 0.0) {
                loc = (int32_T)(DrawShapes_DW_Points[idxRow2] - 0.5);
              } else {
                loc = (int32_T)(DrawShapes_DW_Points[idxRow2] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
                loc_0 = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] -
                                  0.5);
              } else {
                loc_0 = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] +
                                  0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes_DW_Points[activeCol] < 0.0) {
                line_idx_1 = (int32_T)(DrawShapes_DW_Points[activeCol] - 0.5);
              } else {
                line_idx_1 = (int32_T)(DrawShapes_DW_Points[activeCol] + 0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_Sum[col] < 0.0) {
                isPureFill = (int32_T)(rtb_Sum[col] - 0.5);
              } else {
                isPureFill = (int32_T)(rtb_Sum[col] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum[idxRow2] < 0.0) {
                loc = (int32_T)(rtb_Sum[idxRow2] - 0.5);
              } else {
                loc = (int32_T)(rtb_Sum[idxRow2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum[parallelTo_XorYaxis2] < 0.0) {
                loc_0 = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc_0 = (int32_T)(rtb_Sum[parallelTo_XorYaxis2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum[activeCol] < 0.0) {
                line_idx_1 = (int32_T)(rtb_Sum[activeCol] - 0.5);
              } else {
                line_idx_1 = (int32_T)(rtb_Sum[activeCol] + 0.5);
              }
            }

            /* Initialize a Bresenham line. */
            idxTmp = isPureFill - loc_0;
            DrawShapes_DW_Polygon[idxMaxVal] = 0;
            DrawShapes_DW_Polygon[idxMaxVal + 1] = line_idx_1 - 1;
            DrawShapes_DW_Polygon[idxMaxVal + 2] = loc_0 - 1;
            DrawShapes_DW_Polygon[idxMaxVal + 3] = isPureFill - 1;
            DrawShapes_DW_Polygon[idxMaxVal + 6] = 0;
            if (loc - 1 >= line_idx_1 - 1) {
              DrawShapes_DW_Polygon[idxMaxVal + 8] = loc - line_idx_1;
            } else {
              DrawShapes_DW_Polygon[idxMaxVal + 8] = line_idx_1 - loc;
            }

            while (DrawShapes_DW_Polygon[idxMaxVal + 8] >= 0) {
              DrawShapes_DW_Polygon[idxMaxVal + 6]++;
              DrawShapes_DW_Polygon[idxMaxVal + 8] -= idxTmp;
            }

            DrawShapes_DW_Polygon[idxMaxVal + 5] =
              DrawShapes_DW_Polygon[idxMaxVal + 6] - 1;
            DrawShapes_DW_Polygon[idxMaxVal + 7] =
              DrawShapes_DW_Polygon[idxMaxVal + 8] + idxTmp;
            DrawShapes_DW_Polygon[idxMaxVal + 4] = idxTmp -
              (DrawShapes_DW_Polygon[idxMaxVal + 7] << 1);
            if (line_idx_1 - 1 > loc - 1) {
              DrawShapes_DW_Polygon[idxMaxVal + 5] =
                -DrawShapes_DW_Polygon[idxMaxVal + 5];
              DrawShapes_DW_Polygon[idxMaxVal + 6] =
                -DrawShapes_DW_Polygon[idxMaxVal + 6];
            }

            if ((!isMore) && (!countTwice)) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes_DW_Polygon[idxMaxVal + 2]++;
              if ((DrawShapes_DW_Polygon[idxMaxVal] << 1) >
                  DrawShapes_DW_Polygon[idxMaxVal + 4]) {
                DrawShapes_DW_Polygon[idxMaxVal] +=
                  DrawShapes_DW_Polygon[idxMaxVal + 8];
                DrawShapes_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes_DW_Polygon[idxMaxVal + 6];
              } else {
                DrawShapes_DW_Polygon[idxMaxVal] +=
                  DrawShapes_DW_Polygon[idxMaxVal + 7];
                DrawShapes_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes_DW_Polygon[idxMaxVal + 5];
              }
            } else {
              if (isMore && countTwice) {
                DrawShapes_DW_Polygon[idxMaxVal + 3]--;
              }
            }

            isMore = countTwice;
            if (!prevEdgeIsVertical) {
              /* Merge two Bresenham lines. */
              if ((idxEdgePre != idxMaxVal) &&
                  ((DrawShapes_DW_Polygon[idxEdgePre + 5] ==
                    DrawShapes_DW_Polygon[idxMaxVal + 5]) &&
                   (DrawShapes_DW_Polygon[idxEdgePre + 6] ==
                    DrawShapes_DW_Polygon[idxMaxVal + 6]) &&
                   (DrawShapes_DW_Polygon[idxEdgePre + 7] ==
                    DrawShapes_DW_Polygon[idxMaxVal + 7]) &&
                   (DrawShapes_DW_Polygon[idxEdgePre + 8] ==
                    DrawShapes_DW_Polygon[idxMaxVal + 8]))) {
                if (DrawShapes_DW_Polygon[idxEdgePre + 3] + 1 ==
                    DrawShapes_DW_Polygon[idxMaxVal + 2]) {
                  DrawShapes_DW_Polygon[idxEdgePre + 3] =
                    DrawShapes_DW_Polygon[idxMaxVal + 3];
                  prevEdgeIsVertical = true;
                } else {
                  if (DrawShapes_DW_Polygon[idxMaxVal + 3] + 1 ==
                      DrawShapes_DW_Polygon[idxEdgePre + 2]) {
                    DrawShapes_DW_Polygon[idxEdgePre + 1] =
                      DrawShapes_DW_Polygon[idxMaxVal + 1];
                    DrawShapes_DW_Polygon[idxEdgePre + 2] =
                      DrawShapes_DW_Polygon[idxMaxVal + 2];
                    prevEdgeIsVertical = true;
                  }
                }
              }

              if (!prevEdgeIsVertical) {
                idxEdgePre = idxMaxVal;
                numEdge++;
              }
            } else {
              idxEdgePre = idxMaxVal;
              numEdge++;
            }

            idxMaxVal = idxEdgePre + 9;
            if (!countTwice) {
              activeCol = idxRow2;
              parallelTo_XorYaxis2 = col;
            }

            idxRow2 = activeCol + 2;
            col = parallelTo_XorYaxis2 + 2;
            prevEdgeIsVertical = false;
          } else {
            prevEdgeIsVertical = true;
            activeCol = idxRow2;
            parallelTo_XorYaxis2 = col;
            idxRow2 += 2;
            col += 2;
          }
        }

        q2 = 1;
      }

      if (!done) {
        /* Merge two Bresenham lines. */
        if ((inIdx != idxEdgePre) && ((DrawShapes_DW_Polygon[inIdx + 5] ==
              DrawShapes_DW_Polygon[idxEdgePre + 5]) &&
             (DrawShapes_DW_Polygon[inIdx + 6] ==
              DrawShapes_DW_Polygon[idxEdgePre + 6]) &&
             (DrawShapes_DW_Polygon[inIdx + 7] ==
              DrawShapes_DW_Polygon[idxEdgePre + 7]) &&
             (DrawShapes_DW_Polygon[inIdx + 8] ==
              DrawShapes_DW_Polygon[idxEdgePre + 8]))) {
          if (DrawShapes_DW_Polygon[inIdx + 3] + 1 ==
              DrawShapes_DW_Polygon[idxEdgePre + 2]) {
            DrawShapes_DW_Polygon[inIdx + 3] = DrawShapes_DW_Polygon[idxEdgePre
              + 3];
            done = true;
          } else {
            if (DrawShapes_DW_Polygon[idxEdgePre + 3] + 1 ==
                DrawShapes_DW_Polygon[inIdx + 2]) {
              DrawShapes_DW_Polygon[inIdx + 1] =
                DrawShapes_DW_Polygon[idxEdgePre + 1];
              DrawShapes_DW_Polygon[inIdx + 2] =
                DrawShapes_DW_Polygon[idxEdgePre + 2];
              done = true;
            }
          }
        }

        if (done) {
          numEdge--;
          idxMaxVal -= 9;
        }
      }

      /* Set all other edges to invalid. */
      for (imgIdxLR = numEdge; imgIdxLR < jRowsIn; imgIdxLR++) {
        DrawShapes_DW_Polygon[idxMaxVal + 2] = 1;
        DrawShapes_DW_Polygon[idxMaxVal + 3] = 0;
        idxMaxVal += 9;
      }

      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
          if (DrawShapes_DW_Polygon[idxNew + 2] > DrawShapes_DW_Polygon[idxOld +
              2]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes_DW_Polygon[idxNew + line_idx_1];
              DrawShapes_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes_DW_Polygon[idxOld + line_idx_1];
              DrawShapes_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      /* Find out the last column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 3;
      q2 = DrawShapes_DW_Polygon[inIdx + 3];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 < DrawShapes_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      ku = q2;
      if (q2 > 1279) {
        ku = 1279;
      }

      /* Find out the first column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 2;
      q2 = DrawShapes_DW_Polygon[inIdx + 2];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 > DrawShapes_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      if (q2 < 0) {
        q2 = 0;
      }

      /* Move to the next column and find out boundaries of the polygon at this column. */
      idxNew = inIdx;
      idxOld = inIdx;
      loopEndIdx = inIdx;
      idxEdgePre = 0;
      numActiveEdge = 0;
      for (imgIdxLR = 0; imgIdxLR < numEdge; imgIdxLR++) {
        /* Find out the valid boundaries and bring them to the latest column. */
        if (DrawShapes_DW_Polygon[idxOld + 3] >= q2) {
          if (DrawShapes_DW_Polygon[idxOld + 2] <= q2) {
            while (DrawShapes_DW_Polygon[idxOld + 2] < q2) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes_DW_Polygon[idxOld + 2]++;
              if ((DrawShapes_DW_Polygon[idxOld] << 1) >
                  DrawShapes_DW_Polygon[idxOld + 4]) {
                DrawShapes_DW_Polygon[idxOld] += DrawShapes_DW_Polygon[idxOld +
                  8];
                DrawShapes_DW_Polygon[idxOld + 1] +=
                  DrawShapes_DW_Polygon[idxOld + 6];
              } else {
                DrawShapes_DW_Polygon[idxOld] += DrawShapes_DW_Polygon[idxOld +
                  7];
                DrawShapes_DW_Polygon[idxOld + 1] +=
                  DrawShapes_DW_Polygon[idxOld + 5];
              }
            }

            loopEndIdx += 9;
            numActiveEdge++;
          }

          if (idxOld != idxNew) {
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              DrawShapes_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes_DW_Polygon[idxOld + line_idx_1];
            }
          }

          idxNew += 9;
          idxEdgePre++;
        }

        idxOld += 9;
      }

      /* Sort the boundaries of the polygon according to row values. */
      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
          if (DrawShapes_DW_Polygon[idxNew + 1] > DrawShapes_DW_Polygon[idxOld +
              1]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes_DW_Polygon[idxNew + line_idx_1];
              DrawShapes_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes_DW_Polygon[idxOld + line_idx_1];
              DrawShapes_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      numActiveEdge = inIdx;
      idxMaxVal = q2 + 1;
      activeCol = 0;
      idxNew = 0;
      idxOld = -1;
      isMore = (0 <= ku);
      while (isMore) {
        /* Get a string of pixels */
        countTwice = false;
        done = (idxNew != 0);
        col = activeCol;
        if ((activeCol >= q2) && (activeCol <= ku)) {
          if (numActiveEdge < loopEndIdx) {
            imgIdxLR = DrawShapes_DW_Polygon[numActiveEdge + 1];
            numActiveEdge += 9;
            if ((imgIdxLR == idxOld) && (numActiveEdge < loopEndIdx)) {
              numEdge = DrawShapes_DW_Polygon[numActiveEdge + 1];
              isMore = (numActiveEdge < loopEndIdx);
              while (isMore && (imgIdxLR == numEdge)) {
                countTwice = true;
                imgIdxLR = DrawShapes_DW_Polygon[numActiveEdge + 1];
                numActiveEdge += 9;
                isMore = (numActiveEdge < loopEndIdx);
                if (isMore) {
                  numEdge = DrawShapes_DW_Polygon[numActiveEdge + 1];
                }
              }

              if (!isMore) {
                countTwice = false;
              }
            }

            if (idxNew != 0) {
              firstRow = idxOld;
              if (imgIdxLR <= 719) {
                parallelTo_XorYaxis2 = imgIdxLR;
                idxOld = imgIdxLR;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 719;
              }
            } else {
              firstRow = idxOld + 1;
              if ((imgIdxLR > 0) && (imgIdxLR <= 719)) {
                parallelTo_XorYaxis2 = imgIdxLR - 1;
                idxOld = imgIdxLR;
              } else if (imgIdxLR <= 0) {
                parallelTo_XorYaxis2 = -1;
                idxOld = 0;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 720;
              }
            }

            if (!countTwice) {
              idxNew = !(idxNew != 0);
            }
          } else {
            /* Reset states and move to the next column. */
            done = false;
            firstRow = idxOld + 1;
            parallelTo_XorYaxis2 = 719;

            /* Move to the next column and find out boundaries of the polygon at this column. */
            idxNew = inIdx;
            idxOld = inIdx;
            loopEndIdx = inIdx;
            numEdge = 0;
            numActiveEdge = 0;
            for (imgIdxLR = 0; imgIdxLR < idxEdgePre; imgIdxLR++) {
              /* Find out the valid boundaries and bring them to the latest column. */
              if (DrawShapes_DW_Polygon[idxOld + 3] >= idxMaxVal) {
                if (DrawShapes_DW_Polygon[idxOld + 2] <= idxMaxVal) {
                  while (DrawShapes_DW_Polygon[idxOld + 2] < idxMaxVal) {
                    /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                    DrawShapes_DW_Polygon[idxOld + 2]++;
                    if ((DrawShapes_DW_Polygon[idxOld] << 1) >
                        DrawShapes_DW_Polygon[idxOld + 4]) {
                      DrawShapes_DW_Polygon[idxOld] +=
                        DrawShapes_DW_Polygon[idxOld + 8];
                      DrawShapes_DW_Polygon[idxOld + 1] +=
                        DrawShapes_DW_Polygon[idxOld + 6];
                    } else {
                      DrawShapes_DW_Polygon[idxOld] +=
                        DrawShapes_DW_Polygon[idxOld + 7];
                      DrawShapes_DW_Polygon[idxOld + 1] +=
                        DrawShapes_DW_Polygon[idxOld + 5];
                    }
                  }

                  loopEndIdx += 9;
                  numActiveEdge++;
                }

                if (idxOld != idxNew) {
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    DrawShapes_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes_DW_Polygon[idxOld + line_idx_1];
                  }
                }

                idxNew += 9;
                numEdge++;
              }

              idxOld += 9;
            }

            idxEdgePre = numEdge;

            /* Sort the boundaries of the polygon according to row values. */
            /* Sort the boundaries of the polygon. */
            while (isMore) {
              idxNew = inIdx;
              idxOld = inIdx + 9;
              isMore = false;
              for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
                if (DrawShapes_DW_Polygon[idxNew + 1] >
                    DrawShapes_DW_Polygon[idxOld + 1]) {
                  isMore = true;
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    edgeTmp = DrawShapes_DW_Polygon[idxNew + line_idx_1];
                    DrawShapes_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes_DW_Polygon[idxOld + line_idx_1];
                    DrawShapes_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
                  }
                }

                idxNew = idxOld;
                idxOld += 9;
              }
            }

            numActiveEdge = inIdx;
            idxMaxVal++;
            idxNew = 0;
            idxOld = -1;
            activeCol++;
          }
        } else {
          firstRow = 0;
          parallelTo_XorYaxis2 = 719;
          activeCol++;
        }

        if (firstRow < 0) {
          firstRow = 0;
        }

        if (parallelTo_XorYaxis2 < firstRow) {
          parallelTo_XorYaxis2 = firstRow - 1;
        }

        if (done) {
          edgeTmp = col * 720 + firstRow;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[0];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[0];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[1];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[1];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[2];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes_RTP_FILLCOLOR[2];
            }

            line_idx_1++;
          }
        }

        isMore = (activeCol <= ku);
      }

      /* Move to the next polygon. */
      inIdx += jRowsIn * 9;
      if (outIdx >= div_s32_floor(jRowsIn, jRowsIn) - 1) {
        outIdx = 0;
      } else {
        outIdx++;
      }

      isMore = (inIdx < jRowsIn * 9);
    }
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes' */

  /* S-Function (sviphoughlines): '<S5>/Hough Lines1' incorporates:
   *  MATLAB Function: '<S5>/Theta_selector'
   */
  idxMaxVal = 0;
  scale = (rtb_Rho_out + 2.2204460492503131E-16) / (cos(Theta_out) +
    2.2204460492503131E-16);

  /* part-1: top horizontal axis */
  cnt = floor(scale + 0.5);
  if ((cnt >= 0.0) && (cnt <= 629.0)) {
    tmpOutRC_0[0U] = 0;
    if (cnt >= 0.5) {
      tmpOutRC_0[1U] = (int32_T)floor(cnt + 0.5);
    } else {
      tmpOutRC_0[1U] = 0;
    }

    idxMaxVal = 1;
  }

  accumThree = (rtb_Rho_out + 2.2204460492503131E-16) / (sin(Theta_out) +
    2.2204460492503131E-16);

  /* part-2: left vertical axis */
  cnt = floor(accumThree + 0.5);
  if ((cnt >= 0.0) && (cnt <= 229.0)) {
    if (cnt >= 0.5) {
      tmpOutRC_0[idxMaxVal << 1] = (int32_T)floor(cnt + 0.5);
    } else {
      tmpOutRC_0[idxMaxVal << 1] = 0;
    }

    tmpOutRC_0[1 + (idxMaxVal << 1)] = 0;
    idxMaxVal++;
  }

  /* part-3: Right vertical axis */
  if (idxMaxVal < 2) {
    cnt = floor((scale - 629.0) * (accumThree / scale) + 0.5);
    if ((cnt >= 0.0) && (cnt <= 229.0)) {
      if (cnt >= 0.5) {
        tmpOutRC_0[idxMaxVal << 1] = (int32_T)floor(cnt + 0.5);
      } else {
        tmpOutRC_0[idxMaxVal << 1] = 0;
      }

      tmpOutRC_0[1 + (idxMaxVal << 1)] = 629;
      idxMaxVal++;
    }
  }

  /* part-4: bottom horizontal axis */
  if (idxMaxVal < 2) {
    cnt = floor((scale - scale / accumThree * 229.0) + 0.5);
    if ((cnt >= 0.0) && (cnt <= 629.0)) {
      tmpOutRC_0[idxMaxVal << 1] = 229;
      if (cnt >= 0.5) {
        tmpOutRC_0[1 + (idxMaxVal << 1)] = (int32_T)floor(cnt + 0.5);
      } else {
        tmpOutRC_0[1 + (idxMaxVal << 1)] = 0;
      }

      idxMaxVal++;
    }
  }

  if (idxMaxVal < 2) {
    tmpOutRC_0[0U] = -1;
    tmpOutRC_0[1U] = -1;
    tmpOutRC_0[2U] = -1;
    tmpOutRC_0[3U] = -1;
  }

  Houghline_real_fast_2_B.HoughLines1[0] = tmpOutRC_0[1] + 1;
  Houghline_real_fast_2_B.HoughLines1[1] = tmpOutRC_0[0] + 1;
  Houghline_real_fast_2_B.HoughLines1[2] = tmpOutRC_0[3] + 1;
  Houghline_real_fast_2_B.HoughLines1[3] = tmpOutRC_0[2] + 1;

  /* End of S-Function (sviphoughlines): '<S5>/Hough Lines1' */

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S1>/remove boundary'
   */
  rtb_Sum1_i[0] = Houghline_real_fast_2_P.removeboundary_Value + (real_T)
    Houghline_real_fast_2_B.HoughLines1[0];
  rtb_Sum1_i[1] = rtb_Selector_n + (real_T)Houghline_real_fast_2_B.HoughLines1[1];
  rtb_Sum1_i[2] = Houghline_real_fast_2_P.removeboundary_Value + (real_T)
    Houghline_real_fast_2_B.HoughLines1[2];
  rtb_Sum1_i[3] = rtb_Selector_n + (real_T)Houghline_real_fast_2_B.HoughLines1[3];

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes1' */
  if (Houghline_real_fast_2_P.DrawShapes1_lineWidth == 1) {
    /* Compute output for unity line width
     */
    /* Update view port. */
    cnt = fabs(rtb_Sum1_i[1]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum1_i[1] + 0.5);
      } else {
        cnt = rtb_Sum1_i[1] * 0.0;
      }
    } else {
      cnt = rtb_Sum1_i[1];
    }

    numEdge = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum1_i[0]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum1_i[0] + 0.5);
      } else {
        cnt = rtb_Sum1_i[0] * 0.0;
      }
    } else {
      cnt = rtb_Sum1_i[0];
    }

    idxMaxVal = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum1_i[3]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum1_i[3] + 0.5);
      } else {
        cnt = rtb_Sum1_i[3] * 0.0;
      }
    } else {
      cnt = rtb_Sum1_i[3];
    }

    q2 = (int32_T)cnt - 1;
    cnt = fabs(rtb_Sum1_i[2]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_Sum1_i[2] + 0.5);
      } else {
        cnt = rtb_Sum1_i[2] * 0.0;
      }
    } else {
      cnt = rtb_Sum1_i[2];
    }

    outIdx = (int32_T)cnt - 1;
    if ((numEdge != q2) || (idxMaxVal != outIdx)) {
      isMore = false;

      /* Find the visible portion of a line. */
      countTwice = false;
      prevEdgeIsVertical = false;
      done = false;
      ku = numEdge;
      line_idx_1 = idxMaxVal;
      inIdx = q2;
      idxEdgePre = outIdx;
      while (!done) {
        isPureFill = 0;
        col = 0;

        /* Determine viewport violations. */
        if (ku < 0) {
          isPureFill = 4;
        } else {
          if (ku > 719) {
            isPureFill = 8;
          }
        }

        if (inIdx < 0) {
          col = 4;
        } else {
          if (inIdx > 719) {
            col = 8;
          }
        }

        if (line_idx_1 < 0) {
          isPureFill |= 1U;
        } else {
          if (line_idx_1 > 1279) {
            isPureFill |= 2U;
          }
        }

        if (idxEdgePre < 0) {
          col |= 1U;
        } else {
          if (idxEdgePre > 1279) {
            col |= 2U;
          }
        }

        if (!(((uint32_T)isPureFill | col) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isMore = true;
        } else if (((uint32_T)isPureFill & col) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isMore = false;
        } else if ((uint32_T)isPureFill != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (countTwice) {
            ku = numEdge;
            line_idx_1 = idxMaxVal;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            countTwice = true;
          } else if ((isPureFill & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -ku * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 0;
            countTwice = true;
          } else if ((isPureFill & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - ku) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 719;
            countTwice = true;
          } else if ((isPureFill & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -line_idx_1 * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 0;
            countTwice = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - line_idx_1) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 1279;
            countTwice = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (prevEdgeIsVertical) {
            inIdx = q2;
            idxEdgePre = outIdx;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            prevEdgeIsVertical = true;
          } else if ((col & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -inIdx * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 0;
            prevEdgeIsVertical = true;
          } else if ((col & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - inIdx) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 719;
            prevEdgeIsVertical = true;
          } else if ((col & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -idxEdgePre * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 0;
            prevEdgeIsVertical = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - idxEdgePre) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 1279;
            prevEdgeIsVertical = true;
          }
        }
      }

      if (isMore) {
        /* Draw a line using Bresenham algorithm. */
        /* Initialize the Bresenham algorithm. */
        if (inIdx >= ku) {
          q2 = inIdx - ku;
        } else {
          q2 = ku - inIdx;
        }

        if (idxEdgePre >= line_idx_1) {
          outIdx = idxEdgePre - line_idx_1;
        } else {
          outIdx = line_idx_1 - idxEdgePre;
        }

        if (q2 > outIdx) {
          imgIdxLR = 1;
          numEdge = 720;
        } else {
          imgIdxLR = 720;
          numEdge = 1;
          jRowsIn = ku;
          ku = line_idx_1;
          line_idx_1 = jRowsIn;
          jRowsIn = inIdx;
          inIdx = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        if (ku > inIdx) {
          jRowsIn = ku;
          ku = inIdx;
          inIdx = jRowsIn;
          jRowsIn = line_idx_1;
          line_idx_1 = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        jRowsIn = inIdx - ku;
        if (line_idx_1 <= idxEdgePre) {
          idxMaxVal = 1;
          isPureFill = idxEdgePre - line_idx_1;
        } else {
          idxMaxVal = -1;
          isPureFill = line_idx_1 - idxEdgePre;
        }

        loopEndIdx = -((jRowsIn + 1) >> 1);
        idxEdgePre = ku * imgIdxLR + line_idx_1 * numEdge;
        idxMaxVal = idxMaxVal * numEdge + imgIdxLR;
        done = (ku <= inIdx);
        while (done) {
          Houghline_real_fast_2_B.Switch[idxEdgePre] =
            Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[0];
          line_idx_1 = idxEdgePre + 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[1];
          line_idx_1 += 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[2];

          /* Compute the next location using Bresenham algorithm. */
          /* Move to the next pixel location. */
          loopEndIdx += isPureFill;
          if (loopEndIdx >= 0) {
            loopEndIdx -= jRowsIn;
            idxEdgePre += idxMaxVal;
          } else {
            idxEdgePre += imgIdxLR;
          }

          ku++;
          done = (ku <= inIdx);
        }
      }
    }
  } else {
    /* Compute output for non-unity line width
     */
    /* Update view port. */
    /* ProcessStep-start-1
     */
    if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
      /* convertLinePts2PolygonPts
       */
      cnt = fabs(rtb_Sum1_i[0]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum1_i[0] + 0.5);
        } else {
          cnt = rtb_Sum1_i[0] * 0.0;
        }
      } else {
        cnt = rtb_Sum1_i[0];
      }

      outIdx = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum1_i[1]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum1_i[1] + 0.5);
        } else {
          cnt = rtb_Sum1_i[1] * 0.0;
        }
      } else {
        cnt = rtb_Sum1_i[1];
      }

      jRowsIn = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum1_i[2]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum1_i[2] + 0.5);
        } else {
          cnt = rtb_Sum1_i[2] * 0.0;
        }
      } else {
        cnt = rtb_Sum1_i[2];
      }

      isPureFill = (int32_T)cnt - 1;
      cnt = fabs(rtb_Sum1_i[3]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_Sum1_i[3] + 0.5);
        } else {
          cnt = rtb_Sum1_i[3] * 0.0;
        }
      } else {
        cnt = rtb_Sum1_i[3];
      }

      numEdge = (int32_T)cnt - 1;
      ku = Houghline_real_fast_2_P.DrawShapes1_lineWidth >> 1;

      /* getLineParams-1
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)jRowsIn;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)outIdx;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)outIdx / acc1_idx_0 + (real32_T)jRowsIn;
      }

      /* findPointOfIntersectionNormal-1
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes1_DW_Points[0] = firstRow;
      DrawShapes1_DW_Points[1] = idxRow2;

      /* findPointOfIntersectionNormal-2
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes1_DW_Points[7] = loc;
      DrawShapes1_DW_Points[6] = idxTmp;

      /* getLineParams-2
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)numEdge;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)isPureFill;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)isPureFill / acc1_idx_0 + (real32_T)numEdge;
      }

      /* findPointOfIntersectionNormal-3
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes1_DW_Points[2] = firstRow;
      DrawShapes1_DW_Points[3] = idxRow2;

      /* findPointOfIntersectionNormal-4
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes1_DW_Points[5] = loc;
      DrawShapes1_DW_Points[4] = idxTmp;
    }

    /* ProcessStep-after poly points-1
     */
    jRowsIn = 2;

    /* just before call for cgpolygon
     */
    if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
      /* just before call for cgpolygon-2
       */
      jRowsIn = 4;
    }

    /* Reset scanline states. */
    inIdx = 0;
    outIdx = 0;
    isMore = true;
    while (isMore) {
      /* Initialize the scanline. */
      /* Convert polygon vertices to boundaries. */
      done = false;
      numEdge = 0;
      idxEdgePre = inIdx;
      idxMaxVal = inIdx;
      idxTmpArray_0[0U] = (int8_T)(jRowsIn - 1);
      q2 = 0;
      while (q2 < 1) {
        /* start for loop
         */
        activeCol = ((idxTmpArray_0[0] << 1) + outIdx) + 1;
        parallelTo_XorYaxis2 = (idxTmpArray_0[0] << 1) + outIdx;
        idxTmp = idxTmpArray_0[0];
        col = ((idxTmpArray_0[0] - 1) << 1) + outIdx;
        firstRow = jRowsIn;
        if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
            isPureFill = (int32_T)((real_T)
              DrawShapes1_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)
              DrawShapes1_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[col] < 0) {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum1_i[col] < 0.0) {
            loc = (int32_T)(rtb_Sum1_i[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum1_i[col] + 0.5);
          }
        }

        imgIdxLR = loc;
        while ((col >= 0) && (isPureFill - 1 == imgIdxLR - 1)) {
          idxTmp--;
          col = ((idxTmp - 1) << 1) + outIdx;
          firstRow--;
          if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes1_DW_Points[col] < 0) {
              loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
            } else {
              loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_Sum1_i[col] < 0.0) {
              loc = (int32_T)(rtb_Sum1_i[col] - 0.5);
            } else {
              loc = (int32_T)(rtb_Sum1_i[col] + 0.5);
            }
          }

          imgIdxLR = loc;
        }

        if (col < 0) {
          col = 0;
        }

        if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
            isPureFill = (int32_T)((real_T)
              DrawShapes1_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)
              DrawShapes1_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[col] < 0) {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum1_i[col] < 0.0) {
            loc = (int32_T)(rtb_Sum1_i[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum1_i[col] + 0.5);
          }
        }

        isMore = (loc - 1 > isPureFill - 1);
        idxRow2 = outIdx + 1;
        col = outIdx;
        prevEdgeIsVertical = false;
        if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[outIdx] < 0) {
            isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[outIdx] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[parallelTo_XorYaxis2]
                            - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes1_DW_Points[parallelTo_XorYaxis2]
                            + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_Sum1_i[outIdx] < 0.0) {
            isPureFill = (int32_T)(rtb_Sum1_i[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_Sum1_i[outIdx] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
            loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
          } else {
            loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
          }
        }

        done = (loc - 1 == isPureFill - 1);
        for (imgIdxLR = 0; imgIdxLR < firstRow; imgIdxLR++) {
          if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes1_DW_Points[col] < 0) {
              isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
            } else {
              isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
            }

            /* getLoc-1
             */
            if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
              loc = (int32_T)((real_T)DrawShapes1_DW_Points[parallelTo_XorYaxis2]
                              - 0.5);
            } else {
              loc = (int32_T)((real_T)DrawShapes1_DW_Points[parallelTo_XorYaxis2]
                              + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_Sum1_i[col] < 0.0) {
              isPureFill = (int32_T)(rtb_Sum1_i[col] - 0.5);
            } else {
              isPureFill = (int32_T)(rtb_Sum1_i[col] + 0.5);
            }

            /* getLoc-2
             */
            if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
              loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
            } else {
              loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
            }
          }

          if (loc - 1 != isPureFill - 1) {
            if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[col] < 0) {
                isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
                loc = (int32_T)((real_T)
                                DrawShapes1_DW_Points[parallelTo_XorYaxis2] -
                                0.5);
              } else {
                loc = (int32_T)((real_T)
                                DrawShapes1_DW_Points[parallelTo_XorYaxis2] +
                                0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_Sum1_i[col] < 0.0) {
                isPureFill = (int32_T)(rtb_Sum1_i[col] - 0.5);
              } else {
                isPureFill = (int32_T)(rtb_Sum1_i[col] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
                loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
              }
            }

            if (loc - 1 < isPureFill - 1) {
              countTwice = false;
            } else {
              countTwice = true;
              idxTmp = activeCol;
              activeCol = idxRow2;
              idxRow2 = idxTmp;
              idxTmp = parallelTo_XorYaxis2;
              parallelTo_XorYaxis2 = col;
              col = idxTmp;
            }

            if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[col] < 0) {
                isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)((real_T)DrawShapes1_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[idxRow2] < 0) {
                loc = (int32_T)((real_T)DrawShapes1_DW_Points[idxRow2] - 0.5);
              } else {
                loc = (int32_T)((real_T)DrawShapes1_DW_Points[idxRow2] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[parallelTo_XorYaxis2] < 0) {
                loc_0 = (int32_T)((real_T)
                                  DrawShapes1_DW_Points[parallelTo_XorYaxis2] -
                                  0.5);
              } else {
                loc_0 = (int32_T)((real_T)
                                  DrawShapes1_DW_Points[parallelTo_XorYaxis2] +
                                  0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes1_DW_Points[activeCol] < 0) {
                line_idx_1 = (int32_T)((real_T)DrawShapes1_DW_Points[activeCol]
                  - 0.5);
              } else {
                line_idx_1 = (int32_T)((real_T)DrawShapes1_DW_Points[activeCol]
                  + 0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_Sum1_i[col] < 0.0) {
                isPureFill = (int32_T)(rtb_Sum1_i[col] - 0.5);
              } else {
                isPureFill = (int32_T)(rtb_Sum1_i[col] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum1_i[idxRow2] < 0.0) {
                loc = (int32_T)(rtb_Sum1_i[idxRow2] - 0.5);
              } else {
                loc = (int32_T)(rtb_Sum1_i[idxRow2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum1_i[parallelTo_XorYaxis2] < 0.0) {
                loc_0 = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc_0 = (int32_T)(rtb_Sum1_i[parallelTo_XorYaxis2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_Sum1_i[activeCol] < 0.0) {
                line_idx_1 = (int32_T)(rtb_Sum1_i[activeCol] - 0.5);
              } else {
                line_idx_1 = (int32_T)(rtb_Sum1_i[activeCol] + 0.5);
              }
            }

            /* Initialize a Bresenham line. */
            idxTmp = isPureFill - loc_0;
            DrawShapes1_DW_Polygon[idxMaxVal] = 0;
            DrawShapes1_DW_Polygon[idxMaxVal + 1] = line_idx_1 - 1;
            DrawShapes1_DW_Polygon[idxMaxVal + 2] = loc_0 - 1;
            DrawShapes1_DW_Polygon[idxMaxVal + 3] = isPureFill - 1;
            DrawShapes1_DW_Polygon[idxMaxVal + 6] = 0;
            if (loc - 1 >= line_idx_1 - 1) {
              DrawShapes1_DW_Polygon[idxMaxVal + 8] = loc - line_idx_1;
            } else {
              DrawShapes1_DW_Polygon[idxMaxVal + 8] = line_idx_1 - loc;
            }

            while (DrawShapes1_DW_Polygon[idxMaxVal + 8] >= 0) {
              DrawShapes1_DW_Polygon[idxMaxVal + 6]++;
              DrawShapes1_DW_Polygon[idxMaxVal + 8] -= idxTmp;
            }

            DrawShapes1_DW_Polygon[idxMaxVal + 5] =
              DrawShapes1_DW_Polygon[idxMaxVal + 6] - 1;
            DrawShapes1_DW_Polygon[idxMaxVal + 7] =
              DrawShapes1_DW_Polygon[idxMaxVal + 8] + idxTmp;
            DrawShapes1_DW_Polygon[idxMaxVal + 4] = idxTmp -
              (DrawShapes1_DW_Polygon[idxMaxVal + 7] << 1);
            if (line_idx_1 - 1 > loc - 1) {
              DrawShapes1_DW_Polygon[idxMaxVal + 5] =
                -DrawShapes1_DW_Polygon[idxMaxVal + 5];
              DrawShapes1_DW_Polygon[idxMaxVal + 6] =
                -DrawShapes1_DW_Polygon[idxMaxVal + 6];
            }

            if ((!isMore) && (!countTwice)) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes1_DW_Polygon[idxMaxVal + 2]++;
              if ((DrawShapes1_DW_Polygon[idxMaxVal] << 1) >
                  DrawShapes1_DW_Polygon[idxMaxVal + 4]) {
                DrawShapes1_DW_Polygon[idxMaxVal] +=
                  DrawShapes1_DW_Polygon[idxMaxVal + 8];
                DrawShapes1_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes1_DW_Polygon[idxMaxVal + 6];
              } else {
                DrawShapes1_DW_Polygon[idxMaxVal] +=
                  DrawShapes1_DW_Polygon[idxMaxVal + 7];
                DrawShapes1_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes1_DW_Polygon[idxMaxVal + 5];
              }
            } else {
              if (isMore && countTwice) {
                DrawShapes1_DW_Polygon[idxMaxVal + 3]--;
              }
            }

            isMore = countTwice;
            if (!prevEdgeIsVertical) {
              /* Merge two Bresenham lines. */
              if ((idxEdgePre != idxMaxVal) &&
                  ((DrawShapes1_DW_Polygon[idxEdgePre + 5] ==
                    DrawShapes1_DW_Polygon[idxMaxVal + 5]) &&
                   (DrawShapes1_DW_Polygon[idxEdgePre + 6] ==
                    DrawShapes1_DW_Polygon[idxMaxVal + 6]) &&
                   (DrawShapes1_DW_Polygon[idxEdgePre + 7] ==
                    DrawShapes1_DW_Polygon[idxMaxVal + 7]) &&
                   (DrawShapes1_DW_Polygon[idxEdgePre + 8] ==
                    DrawShapes1_DW_Polygon[idxMaxVal + 8]))) {
                if (DrawShapes1_DW_Polygon[idxEdgePre + 3] + 1 ==
                    DrawShapes1_DW_Polygon[idxMaxVal + 2]) {
                  DrawShapes1_DW_Polygon[idxEdgePre + 3] =
                    DrawShapes1_DW_Polygon[idxMaxVal + 3];
                  prevEdgeIsVertical = true;
                } else {
                  if (DrawShapes1_DW_Polygon[idxMaxVal + 3] + 1 ==
                      DrawShapes1_DW_Polygon[idxEdgePre + 2]) {
                    DrawShapes1_DW_Polygon[idxEdgePre + 1] =
                      DrawShapes1_DW_Polygon[idxMaxVal + 1];
                    DrawShapes1_DW_Polygon[idxEdgePre + 2] =
                      DrawShapes1_DW_Polygon[idxMaxVal + 2];
                    prevEdgeIsVertical = true;
                  }
                }
              }

              if (!prevEdgeIsVertical) {
                idxEdgePre = idxMaxVal;
                numEdge++;
              }
            } else {
              idxEdgePre = idxMaxVal;
              numEdge++;
            }

            idxMaxVal = idxEdgePre + 9;
            if (!countTwice) {
              activeCol = idxRow2;
              parallelTo_XorYaxis2 = col;
            }

            idxRow2 = activeCol + 2;
            col = parallelTo_XorYaxis2 + 2;
            prevEdgeIsVertical = false;
          } else {
            prevEdgeIsVertical = true;
            activeCol = idxRow2;
            parallelTo_XorYaxis2 = col;
            idxRow2 += 2;
            col += 2;
          }
        }

        q2 = 1;
      }

      if (!done) {
        /* Merge two Bresenham lines. */
        if ((inIdx != idxEdgePre) && ((DrawShapes1_DW_Polygon[inIdx + 5] ==
              DrawShapes1_DW_Polygon[idxEdgePre + 5]) &&
             (DrawShapes1_DW_Polygon[inIdx + 6] ==
              DrawShapes1_DW_Polygon[idxEdgePre + 6]) &&
             (DrawShapes1_DW_Polygon[inIdx + 7] ==
              DrawShapes1_DW_Polygon[idxEdgePre + 7]) &&
             (DrawShapes1_DW_Polygon[inIdx + 8] ==
              DrawShapes1_DW_Polygon[idxEdgePre + 8]))) {
          if (DrawShapes1_DW_Polygon[inIdx + 3] + 1 ==
              DrawShapes1_DW_Polygon[idxEdgePre + 2]) {
            DrawShapes1_DW_Polygon[inIdx + 3] =
              DrawShapes1_DW_Polygon[idxEdgePre + 3];
            done = true;
          } else {
            if (DrawShapes1_DW_Polygon[idxEdgePre + 3] + 1 ==
                DrawShapes1_DW_Polygon[inIdx + 2]) {
              DrawShapes1_DW_Polygon[inIdx + 1] =
                DrawShapes1_DW_Polygon[idxEdgePre + 1];
              DrawShapes1_DW_Polygon[inIdx + 2] =
                DrawShapes1_DW_Polygon[idxEdgePre + 2];
              done = true;
            }
          }
        }

        if (done) {
          numEdge--;
          idxMaxVal -= 9;
        }
      }

      /* Set all other edges to invalid. */
      for (imgIdxLR = numEdge; imgIdxLR < jRowsIn; imgIdxLR++) {
        DrawShapes1_DW_Polygon[idxMaxVal + 2] = 1;
        DrawShapes1_DW_Polygon[idxMaxVal + 3] = 0;
        idxMaxVal += 9;
      }

      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
          if (DrawShapes1_DW_Polygon[idxNew + 2] > DrawShapes1_DW_Polygon[idxOld
              + 2]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes1_DW_Polygon[idxNew + line_idx_1];
              DrawShapes1_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes1_DW_Polygon[idxOld + line_idx_1];
              DrawShapes1_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      /* Find out the last column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 3;
      q2 = DrawShapes1_DW_Polygon[inIdx + 3];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 < DrawShapes1_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes1_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      ku = q2;
      if (q2 > 1279) {
        ku = 1279;
      }

      /* Find out the first column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 2;
      q2 = DrawShapes1_DW_Polygon[inIdx + 2];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 > DrawShapes1_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes1_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      if (q2 < 0) {
        q2 = 0;
      }

      /* Move to the next column and find out boundaries of the polygon at this column. */
      idxNew = inIdx;
      idxOld = inIdx;
      loopEndIdx = inIdx;
      idxEdgePre = 0;
      numActiveEdge = 0;
      for (imgIdxLR = 0; imgIdxLR < numEdge; imgIdxLR++) {
        /* Find out the valid boundaries and bring them to the latest column. */
        if (DrawShapes1_DW_Polygon[idxOld + 3] >= q2) {
          if (DrawShapes1_DW_Polygon[idxOld + 2] <= q2) {
            while (DrawShapes1_DW_Polygon[idxOld + 2] < q2) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes1_DW_Polygon[idxOld + 2]++;
              if ((DrawShapes1_DW_Polygon[idxOld] << 1) >
                  DrawShapes1_DW_Polygon[idxOld + 4]) {
                DrawShapes1_DW_Polygon[idxOld] += DrawShapes1_DW_Polygon[idxOld
                  + 8];
                DrawShapes1_DW_Polygon[idxOld + 1] +=
                  DrawShapes1_DW_Polygon[idxOld + 6];
              } else {
                DrawShapes1_DW_Polygon[idxOld] += DrawShapes1_DW_Polygon[idxOld
                  + 7];
                DrawShapes1_DW_Polygon[idxOld + 1] +=
                  DrawShapes1_DW_Polygon[idxOld + 5];
              }
            }

            loopEndIdx += 9;
            numActiveEdge++;
          }

          if (idxOld != idxNew) {
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              DrawShapes1_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes1_DW_Polygon[idxOld + line_idx_1];
            }
          }

          idxNew += 9;
          idxEdgePre++;
        }

        idxOld += 9;
      }

      /* Sort the boundaries of the polygon according to row values. */
      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
          if (DrawShapes1_DW_Polygon[idxNew + 1] > DrawShapes1_DW_Polygon[idxOld
              + 1]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes1_DW_Polygon[idxNew + line_idx_1];
              DrawShapes1_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes1_DW_Polygon[idxOld + line_idx_1];
              DrawShapes1_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      numActiveEdge = inIdx;
      idxMaxVal = q2 + 1;
      activeCol = 0;
      idxNew = 0;
      idxOld = -1;
      isMore = (0 <= ku);
      while (isMore) {
        /* Get a string of pixels */
        countTwice = false;
        done = (idxNew != 0);
        col = activeCol;
        if ((activeCol >= q2) && (activeCol <= ku)) {
          if (numActiveEdge < loopEndIdx) {
            imgIdxLR = DrawShapes1_DW_Polygon[numActiveEdge + 1];
            numActiveEdge += 9;
            if ((imgIdxLR == idxOld) && (numActiveEdge < loopEndIdx)) {
              numEdge = DrawShapes1_DW_Polygon[numActiveEdge + 1];
              isMore = (numActiveEdge < loopEndIdx);
              while (isMore && (imgIdxLR == numEdge)) {
                countTwice = true;
                imgIdxLR = DrawShapes1_DW_Polygon[numActiveEdge + 1];
                numActiveEdge += 9;
                isMore = (numActiveEdge < loopEndIdx);
                if (isMore) {
                  numEdge = DrawShapes1_DW_Polygon[numActiveEdge + 1];
                }
              }

              if (!isMore) {
                countTwice = false;
              }
            }

            if (idxNew != 0) {
              firstRow = idxOld;
              if (imgIdxLR <= 719) {
                parallelTo_XorYaxis2 = imgIdxLR;
                idxOld = imgIdxLR;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 719;
              }
            } else {
              firstRow = idxOld + 1;
              if ((imgIdxLR > 0) && (imgIdxLR <= 719)) {
                parallelTo_XorYaxis2 = imgIdxLR - 1;
                idxOld = imgIdxLR;
              } else if (imgIdxLR <= 0) {
                parallelTo_XorYaxis2 = -1;
                idxOld = 0;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 720;
              }
            }

            if (!countTwice) {
              idxNew = !(idxNew != 0);
            }
          } else {
            /* Reset states and move to the next column. */
            done = false;
            firstRow = idxOld + 1;
            parallelTo_XorYaxis2 = 719;

            /* Move to the next column and find out boundaries of the polygon at this column. */
            idxNew = inIdx;
            idxOld = inIdx;
            loopEndIdx = inIdx;
            numEdge = 0;
            numActiveEdge = 0;
            for (imgIdxLR = 0; imgIdxLR < idxEdgePre; imgIdxLR++) {
              /* Find out the valid boundaries and bring them to the latest column. */
              if (DrawShapes1_DW_Polygon[idxOld + 3] >= idxMaxVal) {
                if (DrawShapes1_DW_Polygon[idxOld + 2] <= idxMaxVal) {
                  while (DrawShapes1_DW_Polygon[idxOld + 2] < idxMaxVal) {
                    /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                    DrawShapes1_DW_Polygon[idxOld + 2]++;
                    if ((DrawShapes1_DW_Polygon[idxOld] << 1) >
                        DrawShapes1_DW_Polygon[idxOld + 4]) {
                      DrawShapes1_DW_Polygon[idxOld] +=
                        DrawShapes1_DW_Polygon[idxOld + 8];
                      DrawShapes1_DW_Polygon[idxOld + 1] +=
                        DrawShapes1_DW_Polygon[idxOld + 6];
                    } else {
                      DrawShapes1_DW_Polygon[idxOld] +=
                        DrawShapes1_DW_Polygon[idxOld + 7];
                      DrawShapes1_DW_Polygon[idxOld + 1] +=
                        DrawShapes1_DW_Polygon[idxOld + 5];
                    }
                  }

                  loopEndIdx += 9;
                  numActiveEdge++;
                }

                if (idxOld != idxNew) {
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    DrawShapes1_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes1_DW_Polygon[idxOld + line_idx_1];
                  }
                }

                idxNew += 9;
                numEdge++;
              }

              idxOld += 9;
            }

            idxEdgePre = numEdge;

            /* Sort the boundaries of the polygon according to row values. */
            /* Sort the boundaries of the polygon. */
            while (isMore) {
              idxNew = inIdx;
              idxOld = inIdx + 9;
              isMore = false;
              for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
                if (DrawShapes1_DW_Polygon[idxNew + 1] >
                    DrawShapes1_DW_Polygon[idxOld + 1]) {
                  isMore = true;
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    edgeTmp = DrawShapes1_DW_Polygon[idxNew + line_idx_1];
                    DrawShapes1_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes1_DW_Polygon[idxOld + line_idx_1];
                    DrawShapes1_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
                  }
                }

                idxNew = idxOld;
                idxOld += 9;
              }
            }

            numActiveEdge = inIdx;
            idxMaxVal++;
            idxNew = 0;
            idxOld = -1;
            activeCol++;
          }
        } else {
          firstRow = 0;
          parallelTo_XorYaxis2 = 719;
          activeCol++;
        }

        if (firstRow < 0) {
          firstRow = 0;
        }

        if (parallelTo_XorYaxis2 < firstRow) {
          parallelTo_XorYaxis2 = firstRow - 1;
        }

        if (done) {
          edgeTmp = col * 720 + firstRow;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[0];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[0];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[1];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[1];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes1_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[2];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes1_RTP_FILLCOLOR[2];
            }

            line_idx_1++;
          }
        }

        isMore = (activeCol <= ku);
      }

      /* Move to the next polygon. */
      inIdx += jRowsIn * 9;
      if (outIdx >= div_s32_floor(jRowsIn, jRowsIn) - 1) {
        outIdx = 0;
      } else {
        outIdx++;
      }

      isMore = (inIdx < jRowsIn * 9);
    }
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes1' */

  /* Selector: '<S2>/Selector' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Product: '<S2>/Divide2'
   *  Sum: '<S2>/Sum3'
   */
  Theta_out = (rtb_Sum[2] + rtb_Sum1_i[2]) /
    Houghline_real_fast_2_P.Constant3_Value;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtDraw Shapes3Inport2' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  Product: '<S2>/Divide2'
   *  Selector: '<S2>/Selector'
   *  Sum: '<S2>/Sum2'
   *  Sum: '<S2>/Sum3'
   */
  rtb_TmpSignalConversionAtDrawSh[0] = Houghline_real_fast_2_P.Constant1_Value[0]
    + Theta_out;
  rtb_TmpSignalConversionAtDrawSh[2] = (rtb_Sum[2] + rtb_Sum1_i[2]) /
    Houghline_real_fast_2_P.Constant3_Value;
  rtb_TmpSignalConversionAtDrawSh[1] = (rtb_Sum[3] + rtb_Sum1_i[3]) /
    Houghline_real_fast_2_P.Constant3_Value +
    Houghline_real_fast_2_P.Constant1_Value[1];
  rtb_TmpSignalConversionAtDrawSh[3] = (rtb_Sum[3] + rtb_Sum1_i[3]) /
    Houghline_real_fast_2_P.Constant3_Value;

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes3' */
  if (Houghline_real_fast_2_P.DrawShapes3_lineWidth == 1) {
    /* Compute output for unity line width
     */
    /* Update view port. */
    cnt = fabs(rtb_TmpSignalConversionAtDrawSh[1]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_TmpSignalConversionAtDrawSh[1] + 0.5);
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[1] * 0.0;
      }
    } else {
      cnt = rtb_TmpSignalConversionAtDrawSh[1];
    }

    numEdge = (int32_T)cnt - 1;
    cnt = fabs(rtb_TmpSignalConversionAtDrawSh[0]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_TmpSignalConversionAtDrawSh[0] + 0.5);
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[0] * 0.0;
      }
    } else {
      cnt = rtb_TmpSignalConversionAtDrawSh[0];
    }

    idxMaxVal = (int32_T)cnt - 1;
    cnt = fabs(rtb_TmpSignalConversionAtDrawSh[3]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_TmpSignalConversionAtDrawSh[3] + 0.5);
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[3] * 0.0;
      }
    } else {
      cnt = rtb_TmpSignalConversionAtDrawSh[3];
    }

    q2 = (int32_T)cnt - 1;
    cnt = fabs(rtb_TmpSignalConversionAtDrawSh[2]);
    if (cnt < 4.503599627370496E+15) {
      if (cnt >= 0.5) {
        cnt = floor(rtb_TmpSignalConversionAtDrawSh[2] + 0.5);
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[2] * 0.0;
      }
    } else {
      cnt = rtb_TmpSignalConversionAtDrawSh[2];
    }

    outIdx = (int32_T)cnt - 1;
    if ((numEdge != q2) || (idxMaxVal != outIdx)) {
      isMore = false;

      /* Find the visible portion of a line. */
      countTwice = false;
      prevEdgeIsVertical = false;
      done = false;
      ku = numEdge;
      line_idx_1 = idxMaxVal;
      inIdx = q2;
      idxEdgePre = outIdx;
      while (!done) {
        isPureFill = 0;
        col = 0;

        /* Determine viewport violations. */
        if (ku < 0) {
          isPureFill = 4;
        } else {
          if (ku > 719) {
            isPureFill = 8;
          }
        }

        if (inIdx < 0) {
          col = 4;
        } else {
          if (inIdx > 719) {
            col = 8;
          }
        }

        if (line_idx_1 < 0) {
          isPureFill |= 1U;
        } else {
          if (line_idx_1 > 1279) {
            isPureFill |= 2U;
          }
        }

        if (idxEdgePre < 0) {
          col |= 1U;
        } else {
          if (idxEdgePre > 1279) {
            col |= 2U;
          }
        }

        if (!(((uint32_T)isPureFill | col) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isMore = true;
        } else if (((uint32_T)isPureFill & col) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isMore = false;
        } else if ((uint32_T)isPureFill != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (countTwice) {
            ku = numEdge;
            line_idx_1 = idxMaxVal;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            countTwice = true;
          } else if ((isPureFill & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -ku * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 0;
            countTwice = true;
          } else if ((isPureFill & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - ku) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              line_idx_1 += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              line_idx_1 -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            ku = 719;
            countTwice = true;
          } else if ((isPureFill & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -line_idx_1 * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 0;
            countTwice = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - line_idx_1) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              ku += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              ku -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            line_idx_1 = 1279;
            countTwice = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (prevEdgeIsVertical) {
            inIdx = q2;
            idxEdgePre = outIdx;
          }

          imgIdxLR = inIdx - ku;
          jRowsIn = idxEdgePre - line_idx_1;
          if ((imgIdxLR > 1073741824) || (imgIdxLR < -1073741824) || ((jRowsIn >
                1073741824) || (jRowsIn < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isMore = false;
            prevEdgeIsVertical = true;
          } else if ((col & 4U) != 0U) {
            /* Violated RMin. */
            isPureFill = -inIdx * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 0;
            prevEdgeIsVertical = true;
          } else if ((col & 8U) != 0U) {
            /* Violated RMax. */
            isPureFill = (719 - inIdx) * jRowsIn;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (imgIdxLR >= 0)) || ((isPureFill <
                         0) && (imgIdxLR < 0))) {
              idxEdgePre += (div_s32_floor(isPureFill << 1, imgIdxLR) + 1) >> 1;
            } else {
              idxEdgePre -= (div_s32_floor(-isPureFill << 1, imgIdxLR) + 1) >> 1;
            }

            inIdx = 719;
            prevEdgeIsVertical = true;
          } else if ((col & 1U) != 0U) {
            /* Violated CMin. */
            isPureFill = -idxEdgePre * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 0;
            prevEdgeIsVertical = true;
          } else {
            /* Violated CMax. */
            isPureFill = (1279 - idxEdgePre) * imgIdxLR;
            if ((isPureFill > 1073741824) || (isPureFill < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isMore = false;
            } else if (((isPureFill >= 0) && (jRowsIn >= 0)) || ((isPureFill < 0)
                        && (jRowsIn < 0))) {
              inIdx += (div_s32_floor(isPureFill << 1, jRowsIn) + 1) >> 1;
            } else {
              inIdx -= (div_s32_floor(-isPureFill << 1, jRowsIn) + 1) >> 1;
            }

            idxEdgePre = 1279;
            prevEdgeIsVertical = true;
          }
        }
      }

      if (isMore) {
        /* Draw a line using Bresenham algorithm. */
        /* Initialize the Bresenham algorithm. */
        if (inIdx >= ku) {
          q2 = inIdx - ku;
        } else {
          q2 = ku - inIdx;
        }

        if (idxEdgePre >= line_idx_1) {
          outIdx = idxEdgePre - line_idx_1;
        } else {
          outIdx = line_idx_1 - idxEdgePre;
        }

        if (q2 > outIdx) {
          imgIdxLR = 1;
          numEdge = 720;
        } else {
          imgIdxLR = 720;
          numEdge = 1;
          jRowsIn = ku;
          ku = line_idx_1;
          line_idx_1 = jRowsIn;
          jRowsIn = inIdx;
          inIdx = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        if (ku > inIdx) {
          jRowsIn = ku;
          ku = inIdx;
          inIdx = jRowsIn;
          jRowsIn = line_idx_1;
          line_idx_1 = idxEdgePre;
          idxEdgePre = jRowsIn;
        }

        jRowsIn = inIdx - ku;
        if (line_idx_1 <= idxEdgePre) {
          idxMaxVal = 1;
          isPureFill = idxEdgePre - line_idx_1;
        } else {
          idxMaxVal = -1;
          isPureFill = line_idx_1 - idxEdgePre;
        }

        loopEndIdx = -((jRowsIn + 1) >> 1);
        idxEdgePre = ku * imgIdxLR + line_idx_1 * numEdge;
        idxMaxVal = idxMaxVal * numEdge + imgIdxLR;
        done = (ku <= inIdx);
        while (done) {
          Houghline_real_fast_2_B.Switch[idxEdgePre] =
            Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[0];
          line_idx_1 = idxEdgePre + 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[1];
          line_idx_1 += 921600;
          Houghline_real_fast_2_B.Switch[line_idx_1] =
            Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[2];

          /* Compute the next location using Bresenham algorithm. */
          /* Move to the next pixel location. */
          loopEndIdx += isPureFill;
          if (loopEndIdx >= 0) {
            loopEndIdx -= jRowsIn;
            idxEdgePre += idxMaxVal;
          } else {
            idxEdgePre += imgIdxLR;
          }

          ku++;
          done = (ku <= inIdx);
        }
      }
    }
  } else {
    /* Compute output for non-unity line width
     */
    /* Update view port. */
    /* ProcessStep-start-1
     */
    if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
      /* convertLinePts2PolygonPts
       */
      cnt = fabs(rtb_TmpSignalConversionAtDrawSh[0]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_TmpSignalConversionAtDrawSh[0] + 0.5);
        } else {
          cnt = rtb_TmpSignalConversionAtDrawSh[0] * 0.0;
        }
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[0];
      }

      outIdx = (int32_T)cnt - 1;
      cnt = fabs(rtb_TmpSignalConversionAtDrawSh[1]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_TmpSignalConversionAtDrawSh[1] + 0.5);
        } else {
          cnt = rtb_TmpSignalConversionAtDrawSh[1] * 0.0;
        }
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[1];
      }

      jRowsIn = (int32_T)cnt - 1;
      cnt = fabs(rtb_TmpSignalConversionAtDrawSh[2]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_TmpSignalConversionAtDrawSh[2] + 0.5);
        } else {
          cnt = rtb_TmpSignalConversionAtDrawSh[2] * 0.0;
        }
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[2];
      }

      isPureFill = (int32_T)cnt - 1;
      cnt = fabs(rtb_TmpSignalConversionAtDrawSh[3]);
      if (cnt < 4.503599627370496E+15) {
        if (cnt >= 0.5) {
          cnt = floor(rtb_TmpSignalConversionAtDrawSh[3] + 0.5);
        } else {
          cnt = rtb_TmpSignalConversionAtDrawSh[3] * 0.0;
        }
      } else {
        cnt = rtb_TmpSignalConversionAtDrawSh[3];
      }

      numEdge = (int32_T)cnt - 1;
      ku = Houghline_real_fast_2_P.DrawShapes3_lineWidth >> 1;

      /* getLineParams-1
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)jRowsIn;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)outIdx;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)outIdx / acc1_idx_0 + (real32_T)jRowsIn;
      }

      /* findPointOfIntersectionNormal-1
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes3_DW_Points[0] = firstRow;
      DrawShapes3_DW_Points[1] = idxRow2;

      /* findPointOfIntersectionNormal-2
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes3_DW_Points[7] = loc;
      DrawShapes3_DW_Points[6] = idxTmp;

      /* getLineParams-2
       */
      /* getLineParams-main fcn
       */
      firstRow = jRowsIn - numEdge;
      idxRow2 = outIdx - isPureFill;
      if (idxRow2 == 0) {
        acc1_idx_0 = 0.0F;
        loopEndIdx = 1;
        acc1_idx_2 = (real32_T)(outIdx - ku);
        acc1_idx_1 = (real32_T)(outIdx + ku);
        acc4_idx_0 = (real32_T)numEdge;
      } else if (firstRow == 0) {
        loopEndIdx = 2;
        acc1_idx_0 = 0.0F;
        acc1_idx_2 = (real32_T)(jRowsIn - ku);
        acc1_idx_1 = (real32_T)(jRowsIn + ku);
        acc4_idx_0 = (real32_T)isPureFill;
      } else {
        loopEndIdx = 0;
        acc1_idx_0 = (real32_T)firstRow / (real32_T)idxRow2;
        acc1_idx_1 = (real32_T)jRowsIn - (real32_T)outIdx * acc1_idx_0;
        acc4_idx_0 = (real32_T)ku / ((real32_T)idxRow2 / (real32_T)sqrt
          ((real32_T)(firstRow * firstRow + idxRow2 * idxRow2)));
        acc1_idx_2 = acc1_idx_1 + acc4_idx_0;
        acc1_idx_1 -= acc4_idx_0;
        acc4_idx_0 = (real32_T)isPureFill / acc1_idx_0 + (real32_T)numEdge;
      }

      /* findPointOfIntersectionNormal-3
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_2;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            firstRow = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_2) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            firstRow = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            firstRow = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          firstRow = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 += acc1_idx_0 * acc1_idx_5;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxRow2 = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            idxRow2 = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          idxRow2 = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes3_DW_Points[2] = firstRow;
      DrawShapes3_DW_Points[3] = idxRow2;

      /* findPointOfIntersectionNormal-4
       */
      /* findPointOfIntersectionNormal- main fcn
       */
      if (loopEndIdx == 1) {
        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_1;
        }

        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            loc = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          loc = (int32_T)acc4_idx_0;
        }
      } else if (loopEndIdx == 2) {
        v = (real32_T)fabs(acc4_idx_0);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc4_idx_0 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc4_idx_0 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc4_idx_0;
        }

        v = (real32_T)fabs(acc1_idx_1);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_1 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_1 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_1;
        }
      } else {
        acc1_idx_5 = (acc4_idx_0 - acc1_idx_1) * acc1_idx_0 / (acc1_idx_0 *
          acc1_idx_0 + 1.0F);
        v = (real32_T)fabs(acc1_idx_5);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            idxTmp = (int32_T)(real32_T)floor(acc1_idx_5 + 0.5F);
          } else {
            idxTmp = (int32_T)(acc1_idx_5 * 0.0F);
          }
        } else {
          idxTmp = (int32_T)acc1_idx_5;
        }

        acc1_idx_2 = acc1_idx_0 * acc1_idx_5 + acc1_idx_1;
        v = (real32_T)fabs(acc1_idx_2);
        if (v < 8.388608E+6F) {
          if (v >= 0.5F) {
            loc = (int32_T)(real32_T)floor(acc1_idx_2 + 0.5F);
          } else {
            loc = (int32_T)(acc1_idx_2 * 0.0F);
          }
        } else {
          loc = (int32_T)acc1_idx_2;
        }
      }

      DrawShapes3_DW_Points[5] = loc;
      DrawShapes3_DW_Points[4] = idxTmp;
    }

    /* ProcessStep-after poly points-1
     */
    jRowsIn = 2;

    /* just before call for cgpolygon
     */
    if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
      /* just before call for cgpolygon-2
       */
      jRowsIn = 4;
    }

    /* Reset scanline states. */
    inIdx = 0;
    outIdx = 0;
    isMore = true;
    while (isMore) {
      /* Initialize the scanline. */
      /* Convert polygon vertices to boundaries. */
      done = false;
      numEdge = 0;
      idxEdgePre = inIdx;
      idxMaxVal = inIdx;
      idxTmpArray_1[0U] = (int8_T)(jRowsIn - 1);
      q2 = 0;
      while (q2 < 1) {
        /* start for loop
         */
        activeCol = ((idxTmpArray_1[0] << 1) + outIdx) + 1;
        parallelTo_XorYaxis2 = (idxTmpArray_1[0] << 1) + outIdx;
        idxTmp = idxTmpArray_1[0];
        col = ((idxTmpArray_1[0] - 1) << 1) + outIdx;
        firstRow = jRowsIn;
        if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
            isPureFill = (int32_T)((real_T)
              DrawShapes3_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)
              DrawShapes3_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[col] < 0) {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)
              (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)
              (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] + 0.5);
          }
        }

        imgIdxLR = loc;
        while ((col >= 0) && (isPureFill - 1 == imgIdxLR - 1)) {
          idxTmp--;
          col = ((idxTmp - 1) << 1) + outIdx;
          firstRow--;
          if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes3_DW_Points[col] < 0) {
              loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
            } else {
              loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
              loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] - 0.5);
            } else {
              loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] + 0.5);
            }
          }

          imgIdxLR = loc;
        }

        if (col < 0) {
          col = 0;
        }

        if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
            isPureFill = (int32_T)((real_T)
              DrawShapes3_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)
              DrawShapes3_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[col] < 0) {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
            isPureFill = (int32_T)
              (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] - 0.5);
          } else {
            isPureFill = (int32_T)
              (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] - 0.5);
          } else {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] + 0.5);
          }
        }

        isMore = (loc - 1 > isPureFill - 1);
        idxRow2 = outIdx + 1;
        col = outIdx;
        prevEdgeIsVertical = false;
        if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[outIdx] < 0) {
            isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[outIdx] + 0.5);
          }

          /* getLoc-1
           */
          if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[parallelTo_XorYaxis2]
                            - 0.5);
          } else {
            loc = (int32_T)((real_T)DrawShapes3_DW_Points[parallelTo_XorYaxis2]
                            + 0.5);
          }
        } else {
          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[outIdx] < 0.0) {
            isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[outIdx] - 0.5);
          } else {
            isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[outIdx] + 0.5);
          }

          /* getLoc-2
           */
          if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2]
                            - 0.5);
          } else {
            loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2]
                            + 0.5);
          }
        }

        done = (loc - 1 == isPureFill - 1);
        for (imgIdxLR = 0; imgIdxLR < firstRow; imgIdxLR++) {
          if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
            /* getLoc-1
             */
            if (DrawShapes3_DW_Points[col] < 0) {
              isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
            } else {
              isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
            }

            /* getLoc-1
             */
            if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
              loc = (int32_T)((real_T)DrawShapes3_DW_Points[parallelTo_XorYaxis2]
                              - 0.5);
            } else {
              loc = (int32_T)((real_T)DrawShapes3_DW_Points[parallelTo_XorYaxis2]
                              + 0.5);
            }
          } else {
            /* getLoc-2
             */
            if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
              isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] - 0.5);
            } else {
              isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] + 0.5);
            }

            /* getLoc-2
             */
            if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
              loc = (int32_T)
                (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] - 0.5);
            } else {
              loc = (int32_T)
                (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] + 0.5);
            }
          }

          if (loc - 1 != isPureFill - 1) {
            if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[col] < 0) {
                isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
                loc = (int32_T)((real_T)
                                DrawShapes3_DW_Points[parallelTo_XorYaxis2] -
                                0.5);
              } else {
                loc = (int32_T)((real_T)
                                DrawShapes3_DW_Points[parallelTo_XorYaxis2] +
                                0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
                isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] -
                  0.5);
              } else {
                isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] +
                  0.5);
              }

              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
                loc = (int32_T)
                  (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc = (int32_T)
                  (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] + 0.5);
              }
            }

            if (loc - 1 < isPureFill - 1) {
              countTwice = false;
            } else {
              countTwice = true;
              idxTmp = activeCol;
              activeCol = idxRow2;
              idxRow2 = idxTmp;
              idxTmp = parallelTo_XorYaxis2;
              parallelTo_XorYaxis2 = col;
              col = idxTmp;
            }

            if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[col] < 0) {
                isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] - 0.5);
              } else {
                isPureFill = (int32_T)((real_T)DrawShapes3_DW_Points[col] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[idxRow2] < 0) {
                loc = (int32_T)((real_T)DrawShapes3_DW_Points[idxRow2] - 0.5);
              } else {
                loc = (int32_T)((real_T)DrawShapes3_DW_Points[idxRow2] + 0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[parallelTo_XorYaxis2] < 0) {
                loc_0 = (int32_T)((real_T)
                                  DrawShapes3_DW_Points[parallelTo_XorYaxis2] -
                                  0.5);
              } else {
                loc_0 = (int32_T)((real_T)
                                  DrawShapes3_DW_Points[parallelTo_XorYaxis2] +
                                  0.5);
              }

              /* getLoc-1
               */
              if (DrawShapes3_DW_Points[activeCol] < 0) {
                line_idx_1 = (int32_T)((real_T)DrawShapes3_DW_Points[activeCol]
                  - 0.5);
              } else {
                line_idx_1 = (int32_T)((real_T)DrawShapes3_DW_Points[activeCol]
                  + 0.5);
              }
            } else {
              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[col] < 0.0) {
                isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] -
                  0.5);
              } else {
                isPureFill = (int32_T)(rtb_TmpSignalConversionAtDrawSh[col] +
                  0.5);
              }

              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[idxRow2] < 0.0) {
                loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[idxRow2] - 0.5);
              } else {
                loc = (int32_T)(rtb_TmpSignalConversionAtDrawSh[idxRow2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] < 0.0) {
                loc_0 = (int32_T)
                  (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] - 0.5);
              } else {
                loc_0 = (int32_T)
                  (rtb_TmpSignalConversionAtDrawSh[parallelTo_XorYaxis2] + 0.5);
              }

              /* getLoc-2
               */
              if (rtb_TmpSignalConversionAtDrawSh[activeCol] < 0.0) {
                line_idx_1 = (int32_T)(rtb_TmpSignalConversionAtDrawSh[activeCol]
                  - 0.5);
              } else {
                line_idx_1 = (int32_T)(rtb_TmpSignalConversionAtDrawSh[activeCol]
                  + 0.5);
              }
            }

            /* Initialize a Bresenham line. */
            idxTmp = isPureFill - loc_0;
            DrawShapes3_DW_Polygon[idxMaxVal] = 0;
            DrawShapes3_DW_Polygon[idxMaxVal + 1] = line_idx_1 - 1;
            DrawShapes3_DW_Polygon[idxMaxVal + 2] = loc_0 - 1;
            DrawShapes3_DW_Polygon[idxMaxVal + 3] = isPureFill - 1;
            DrawShapes3_DW_Polygon[idxMaxVal + 6] = 0;
            if (loc - 1 >= line_idx_1 - 1) {
              DrawShapes3_DW_Polygon[idxMaxVal + 8] = loc - line_idx_1;
            } else {
              DrawShapes3_DW_Polygon[idxMaxVal + 8] = line_idx_1 - loc;
            }

            while (DrawShapes3_DW_Polygon[idxMaxVal + 8] >= 0) {
              DrawShapes3_DW_Polygon[idxMaxVal + 6]++;
              DrawShapes3_DW_Polygon[idxMaxVal + 8] -= idxTmp;
            }

            DrawShapes3_DW_Polygon[idxMaxVal + 5] =
              DrawShapes3_DW_Polygon[idxMaxVal + 6] - 1;
            DrawShapes3_DW_Polygon[idxMaxVal + 7] =
              DrawShapes3_DW_Polygon[idxMaxVal + 8] + idxTmp;
            DrawShapes3_DW_Polygon[idxMaxVal + 4] = idxTmp -
              (DrawShapes3_DW_Polygon[idxMaxVal + 7] << 1);
            if (line_idx_1 - 1 > loc - 1) {
              DrawShapes3_DW_Polygon[idxMaxVal + 5] =
                -DrawShapes3_DW_Polygon[idxMaxVal + 5];
              DrawShapes3_DW_Polygon[idxMaxVal + 6] =
                -DrawShapes3_DW_Polygon[idxMaxVal + 6];
            }

            if ((!isMore) && (!countTwice)) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes3_DW_Polygon[idxMaxVal + 2]++;
              if ((DrawShapes3_DW_Polygon[idxMaxVal] << 1) >
                  DrawShapes3_DW_Polygon[idxMaxVal + 4]) {
                DrawShapes3_DW_Polygon[idxMaxVal] +=
                  DrawShapes3_DW_Polygon[idxMaxVal + 8];
                DrawShapes3_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes3_DW_Polygon[idxMaxVal + 6];
              } else {
                DrawShapes3_DW_Polygon[idxMaxVal] +=
                  DrawShapes3_DW_Polygon[idxMaxVal + 7];
                DrawShapes3_DW_Polygon[idxMaxVal + 1] +=
                  DrawShapes3_DW_Polygon[idxMaxVal + 5];
              }
            } else {
              if (isMore && countTwice) {
                DrawShapes3_DW_Polygon[idxMaxVal + 3]--;
              }
            }

            isMore = countTwice;
            if (!prevEdgeIsVertical) {
              /* Merge two Bresenham lines. */
              if ((idxEdgePre != idxMaxVal) &&
                  ((DrawShapes3_DW_Polygon[idxEdgePre + 5] ==
                    DrawShapes3_DW_Polygon[idxMaxVal + 5]) &&
                   (DrawShapes3_DW_Polygon[idxEdgePre + 6] ==
                    DrawShapes3_DW_Polygon[idxMaxVal + 6]) &&
                   (DrawShapes3_DW_Polygon[idxEdgePre + 7] ==
                    DrawShapes3_DW_Polygon[idxMaxVal + 7]) &&
                   (DrawShapes3_DW_Polygon[idxEdgePre + 8] ==
                    DrawShapes3_DW_Polygon[idxMaxVal + 8]))) {
                if (DrawShapes3_DW_Polygon[idxEdgePre + 3] + 1 ==
                    DrawShapes3_DW_Polygon[idxMaxVal + 2]) {
                  DrawShapes3_DW_Polygon[idxEdgePre + 3] =
                    DrawShapes3_DW_Polygon[idxMaxVal + 3];
                  prevEdgeIsVertical = true;
                } else {
                  if (DrawShapes3_DW_Polygon[idxMaxVal + 3] + 1 ==
                      DrawShapes3_DW_Polygon[idxEdgePre + 2]) {
                    DrawShapes3_DW_Polygon[idxEdgePre + 1] =
                      DrawShapes3_DW_Polygon[idxMaxVal + 1];
                    DrawShapes3_DW_Polygon[idxEdgePre + 2] =
                      DrawShapes3_DW_Polygon[idxMaxVal + 2];
                    prevEdgeIsVertical = true;
                  }
                }
              }

              if (!prevEdgeIsVertical) {
                idxEdgePre = idxMaxVal;
                numEdge++;
              }
            } else {
              idxEdgePre = idxMaxVal;
              numEdge++;
            }

            idxMaxVal = idxEdgePre + 9;
            if (!countTwice) {
              activeCol = idxRow2;
              parallelTo_XorYaxis2 = col;
            }

            idxRow2 = activeCol + 2;
            col = parallelTo_XorYaxis2 + 2;
            prevEdgeIsVertical = false;
          } else {
            prevEdgeIsVertical = true;
            activeCol = idxRow2;
            parallelTo_XorYaxis2 = col;
            idxRow2 += 2;
            col += 2;
          }
        }

        q2 = 1;
      }

      if (!done) {
        /* Merge two Bresenham lines. */
        if ((inIdx != idxEdgePre) && ((DrawShapes3_DW_Polygon[inIdx + 5] ==
              DrawShapes3_DW_Polygon[idxEdgePre + 5]) &&
             (DrawShapes3_DW_Polygon[inIdx + 6] ==
              DrawShapes3_DW_Polygon[idxEdgePre + 6]) &&
             (DrawShapes3_DW_Polygon[inIdx + 7] ==
              DrawShapes3_DW_Polygon[idxEdgePre + 7]) &&
             (DrawShapes3_DW_Polygon[inIdx + 8] ==
              DrawShapes3_DW_Polygon[idxEdgePre + 8]))) {
          if (DrawShapes3_DW_Polygon[inIdx + 3] + 1 ==
              DrawShapes3_DW_Polygon[idxEdgePre + 2]) {
            DrawShapes3_DW_Polygon[inIdx + 3] =
              DrawShapes3_DW_Polygon[idxEdgePre + 3];
            done = true;
          } else {
            if (DrawShapes3_DW_Polygon[idxEdgePre + 3] + 1 ==
                DrawShapes3_DW_Polygon[inIdx + 2]) {
              DrawShapes3_DW_Polygon[inIdx + 1] =
                DrawShapes3_DW_Polygon[idxEdgePre + 1];
              DrawShapes3_DW_Polygon[inIdx + 2] =
                DrawShapes3_DW_Polygon[idxEdgePre + 2];
              done = true;
            }
          }
        }

        if (done) {
          numEdge--;
          idxMaxVal -= 9;
        }
      }

      /* Set all other edges to invalid. */
      for (imgIdxLR = numEdge; imgIdxLR < jRowsIn; imgIdxLR++) {
        DrawShapes3_DW_Polygon[idxMaxVal + 2] = 1;
        DrawShapes3_DW_Polygon[idxMaxVal + 3] = 0;
        idxMaxVal += 9;
      }

      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
          if (DrawShapes3_DW_Polygon[idxNew + 2] > DrawShapes3_DW_Polygon[idxOld
              + 2]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes3_DW_Polygon[idxNew + line_idx_1];
              DrawShapes3_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes3_DW_Polygon[idxOld + line_idx_1];
              DrawShapes3_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      /* Find out the last column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 3;
      q2 = DrawShapes3_DW_Polygon[inIdx + 3];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 < DrawShapes3_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes3_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      ku = q2;
      if (q2 > 1279) {
        ku = 1279;
      }

      /* Find out the first column of the polygon. */
      parallelTo_XorYaxis2 = inIdx + 2;
      q2 = DrawShapes3_DW_Polygon[inIdx + 2];
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        parallelTo_XorYaxis2 += 9;
        if (q2 > DrawShapes3_DW_Polygon[parallelTo_XorYaxis2]) {
          q2 = DrawShapes3_DW_Polygon[parallelTo_XorYaxis2];
        }
      }

      if (q2 < 0) {
        q2 = 0;
      }

      /* Move to the next column and find out boundaries of the polygon at this column. */
      idxNew = inIdx;
      idxOld = inIdx;
      loopEndIdx = inIdx;
      idxEdgePre = 0;
      numActiveEdge = 0;
      for (imgIdxLR = 0; imgIdxLR < numEdge; imgIdxLR++) {
        /* Find out the valid boundaries and bring them to the latest column. */
        if (DrawShapes3_DW_Polygon[idxOld + 3] >= q2) {
          if (DrawShapes3_DW_Polygon[idxOld + 2] <= q2) {
            while (DrawShapes3_DW_Polygon[idxOld + 2] < q2) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              DrawShapes3_DW_Polygon[idxOld + 2]++;
              if ((DrawShapes3_DW_Polygon[idxOld] << 1) >
                  DrawShapes3_DW_Polygon[idxOld + 4]) {
                DrawShapes3_DW_Polygon[idxOld] += DrawShapes3_DW_Polygon[idxOld
                  + 8];
                DrawShapes3_DW_Polygon[idxOld + 1] +=
                  DrawShapes3_DW_Polygon[idxOld + 6];
              } else {
                DrawShapes3_DW_Polygon[idxOld] += DrawShapes3_DW_Polygon[idxOld
                  + 7];
                DrawShapes3_DW_Polygon[idxOld + 1] +=
                  DrawShapes3_DW_Polygon[idxOld + 5];
              }
            }

            loopEndIdx += 9;
            numActiveEdge++;
          }

          if (idxOld != idxNew) {
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              DrawShapes3_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes3_DW_Polygon[idxOld + line_idx_1];
            }
          }

          idxNew += 9;
          idxEdgePre++;
        }

        idxOld += 9;
      }

      /* Sort the boundaries of the polygon according to row values. */
      /* Sort the boundaries of the polygon. */
      isMore = true;
      while (isMore) {
        idxNew = inIdx;
        idxOld = inIdx + 9;
        isMore = false;
        for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
          if (DrawShapes3_DW_Polygon[idxNew + 1] > DrawShapes3_DW_Polygon[idxOld
              + 1]) {
            isMore = true;
            for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
              edgeTmp = DrawShapes3_DW_Polygon[idxNew + line_idx_1];
              DrawShapes3_DW_Polygon[idxNew + line_idx_1] =
                DrawShapes3_DW_Polygon[idxOld + line_idx_1];
              DrawShapes3_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
            }
          }

          idxNew = idxOld;
          idxOld += 9;
        }
      }

      numActiveEdge = inIdx;
      idxMaxVal = q2 + 1;
      activeCol = 0;
      idxNew = 0;
      idxOld = -1;
      isMore = (0 <= ku);
      while (isMore) {
        /* Get a string of pixels */
        countTwice = false;
        done = (idxNew != 0);
        col = activeCol;
        if ((activeCol >= q2) && (activeCol <= ku)) {
          if (numActiveEdge < loopEndIdx) {
            imgIdxLR = DrawShapes3_DW_Polygon[numActiveEdge + 1];
            numActiveEdge += 9;
            if ((imgIdxLR == idxOld) && (numActiveEdge < loopEndIdx)) {
              numEdge = DrawShapes3_DW_Polygon[numActiveEdge + 1];
              isMore = (numActiveEdge < loopEndIdx);
              while (isMore && (imgIdxLR == numEdge)) {
                countTwice = true;
                imgIdxLR = DrawShapes3_DW_Polygon[numActiveEdge + 1];
                numActiveEdge += 9;
                isMore = (numActiveEdge < loopEndIdx);
                if (isMore) {
                  numEdge = DrawShapes3_DW_Polygon[numActiveEdge + 1];
                }
              }

              if (!isMore) {
                countTwice = false;
              }
            }

            if (idxNew != 0) {
              firstRow = idxOld;
              if (imgIdxLR <= 719) {
                parallelTo_XorYaxis2 = imgIdxLR;
                idxOld = imgIdxLR;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 719;
              }
            } else {
              firstRow = idxOld + 1;
              if ((imgIdxLR > 0) && (imgIdxLR <= 719)) {
                parallelTo_XorYaxis2 = imgIdxLR - 1;
                idxOld = imgIdxLR;
              } else if (imgIdxLR <= 0) {
                parallelTo_XorYaxis2 = -1;
                idxOld = 0;
              } else {
                parallelTo_XorYaxis2 = 719;
                idxOld = 720;
              }
            }

            if (!countTwice) {
              idxNew = !(idxNew != 0);
            }
          } else {
            /* Reset states and move to the next column. */
            done = false;
            firstRow = idxOld + 1;
            parallelTo_XorYaxis2 = 719;

            /* Move to the next column and find out boundaries of the polygon at this column. */
            idxNew = inIdx;
            idxOld = inIdx;
            loopEndIdx = inIdx;
            numEdge = 0;
            numActiveEdge = 0;
            for (imgIdxLR = 0; imgIdxLR < idxEdgePre; imgIdxLR++) {
              /* Find out the valid boundaries and bring them to the latest column. */
              if (DrawShapes3_DW_Polygon[idxOld + 3] >= idxMaxVal) {
                if (DrawShapes3_DW_Polygon[idxOld + 2] <= idxMaxVal) {
                  while (DrawShapes3_DW_Polygon[idxOld + 2] < idxMaxVal) {
                    /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                    DrawShapes3_DW_Polygon[idxOld + 2]++;
                    if ((DrawShapes3_DW_Polygon[idxOld] << 1) >
                        DrawShapes3_DW_Polygon[idxOld + 4]) {
                      DrawShapes3_DW_Polygon[idxOld] +=
                        DrawShapes3_DW_Polygon[idxOld + 8];
                      DrawShapes3_DW_Polygon[idxOld + 1] +=
                        DrawShapes3_DW_Polygon[idxOld + 6];
                    } else {
                      DrawShapes3_DW_Polygon[idxOld] +=
                        DrawShapes3_DW_Polygon[idxOld + 7];
                      DrawShapes3_DW_Polygon[idxOld + 1] +=
                        DrawShapes3_DW_Polygon[idxOld + 5];
                    }
                  }

                  loopEndIdx += 9;
                  numActiveEdge++;
                }

                if (idxOld != idxNew) {
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    DrawShapes3_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes3_DW_Polygon[idxOld + line_idx_1];
                  }
                }

                idxNew += 9;
                numEdge++;
              }

              idxOld += 9;
            }

            idxEdgePre = numEdge;

            /* Sort the boundaries of the polygon according to row values. */
            /* Sort the boundaries of the polygon. */
            while (isMore) {
              idxNew = inIdx;
              idxOld = inIdx + 9;
              isMore = false;
              for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
                if (DrawShapes3_DW_Polygon[idxNew + 1] >
                    DrawShapes3_DW_Polygon[idxOld + 1]) {
                  isMore = true;
                  for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                    edgeTmp = DrawShapes3_DW_Polygon[idxNew + line_idx_1];
                    DrawShapes3_DW_Polygon[idxNew + line_idx_1] =
                      DrawShapes3_DW_Polygon[idxOld + line_idx_1];
                    DrawShapes3_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
                  }
                }

                idxNew = idxOld;
                idxOld += 9;
              }
            }

            numActiveEdge = inIdx;
            idxMaxVal++;
            idxNew = 0;
            idxOld = -1;
            activeCol++;
          }
        } else {
          firstRow = 0;
          parallelTo_XorYaxis2 = 719;
          activeCol++;
        }

        if (firstRow < 0) {
          firstRow = 0;
        }

        if (parallelTo_XorYaxis2 < firstRow) {
          parallelTo_XorYaxis2 = firstRow - 1;
        }

        if (done) {
          edgeTmp = col * 720 + firstRow;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[0];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[0];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[1];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[1];
            }

            line_idx_1++;
          }

          edgeTmp += 921600;
          isPureFill = 1;
          if (Houghline_real_fast_2_P.DrawShapes3_lineWidth > 1) {
            isPureFill = 0;
          }

          line_idx_1 = edgeTmp;
          for (imgIdxLR = firstRow; imgIdxLR <= parallelTo_XorYaxis2; imgIdxLR++)
          {
            if (isPureFill != 0) {
              Houghline_real_fast_2_B.Switch[line_idx_1] *=
                Houghline_real_fast_2_B.Switch[0];
              Houghline_real_fast_2_B.Switch[line_idx_1] +=
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[2];
            } else {
              Houghline_real_fast_2_B.Switch[line_idx_1] =
                Houghline_real_fast_2_P.DrawShapes3_RTP_FILLCOLOR[2];
            }

            line_idx_1++;
          }
        }

        isMore = (activeCol <= ku);
      }

      /* Move to the next polygon. */
      inIdx += jRowsIn * 9;
      if (outIdx >= div_s32_floor(jRowsIn, jRowsIn) - 1) {
        outIdx = 0;
      } else {
        outIdx++;
      }

      isMore = (inIdx < jRowsIn * 9);
    }
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes3' */

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate1In1' */
  DrawShapes_DW_Points[0] = rtb_Sum1_i[0];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate1In2' */
  DrawShapes_DW_Points[1] = rtb_Sum1_i[1];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate1In3' */
  DrawShapes_DW_Points[2] = rtb_Sum[0];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate1In4' */
  DrawShapes_DW_Points[3] = rtb_Sum[1];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate2In1' */
  DrawShapes_DW_Points[4] = rtb_Sum[2];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate2In2' */
  DrawShapes_DW_Points[5] = rtb_Sum[3];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate2In3' */
  DrawShapes_DW_Points[6] = rtb_Sum1_i[2];

  /* SignalConversion: '<S2>/ConcatBufferAtMatrix Concatenate2In4' */
  DrawShapes_DW_Points[7] = rtb_Sum1_i[3];

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes2' */
  /* Copy the image from input to output. */
  memcpy(&Houghline_real_fast_2_B.DrawShapes2[0],
         &Houghline_real_fast_2_B.Switch[0], 2764800U * sizeof(real32_T));

  /* Update view port. */
  /* ProcessStep-start-1
   */
  /* ProcessStep-after poly points-1
   */
  memset(&DrawShapes2_DW_PixCount[0], 0, 720U * sizeof(uint8_T));

  /* Reset scanline states. */
  inIdx = 0;
  isMore = true;
  while (isMore) {
    /* Initialize the scanline. */
    /* Convert polygon vertices to boundaries. */
    done = false;
    numEdge = 0;
    idxEdgePre = inIdx;
    idxMaxVal = inIdx;
    q2 = 0;
    while (q2 < 1) {
      /* start for loop
       */
      activeCol = 7;
      parallelTo_XorYaxis2 = 6;
      idxTmp = 3;
      col = 4;
      firstRow = 4;

      /* getLoc-3
       */
      if (DrawShapes_DW_Points[6] < 0.0) {
        idxRow2 = (int32_T)(DrawShapes_DW_Points[6] - 0.5);
      } else {
        idxRow2 = (int32_T)(DrawShapes_DW_Points[6] + 0.5);
      }

      /* getLoc-3
       */
      if (DrawShapes_DW_Points[4] < 0.0) {
        imgIdxLR = (int32_T)(DrawShapes_DW_Points[4] - 0.5);
      } else {
        imgIdxLR = (int32_T)(DrawShapes_DW_Points[4] + 0.5);
      }

      while ((col >= 0) && (idxRow2 - 1 == imgIdxLR - 1)) {
        idxTmp--;
        col = (idxTmp - 1) << 1;
        firstRow--;

        /* getLoc-3
         */
        if (DrawShapes_DW_Points[col] < 0.0) {
          imgIdxLR = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
        } else {
          imgIdxLR = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
        }
      }

      if (col < 0) {
        col = 0;
      }

      /* getLoc-3
       */
      if (DrawShapes_DW_Points[col] < 0.0) {
        jRowsIn = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
      } else {
        jRowsIn = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
      }

      if (DrawShapes_DW_Points[6] < 0.0) {
        ku = (int32_T)(DrawShapes_DW_Points[6] - 0.5);
      } else {
        ku = (int32_T)(DrawShapes_DW_Points[6] + 0.5);
      }

      isMore = (jRowsIn - 1 > ku - 1);
      idxRow2 = 1;
      col = 0;
      prevEdgeIsVertical = false;

      /* getLoc-3
       */
      if (DrawShapes_DW_Points[6] < 0.0) {
        jRowsIn = (int32_T)(DrawShapes_DW_Points[6] - 0.5);
      } else {
        jRowsIn = (int32_T)(DrawShapes_DW_Points[6] + 0.5);
      }

      if (DrawShapes_DW_Points[0] < 0.0) {
        ku = (int32_T)(DrawShapes_DW_Points[0] - 0.5);
      } else {
        ku = (int32_T)(DrawShapes_DW_Points[0] + 0.5);
      }

      done = (jRowsIn - 1 == ku - 1);
      for (imgIdxLR = 0; imgIdxLR < firstRow; imgIdxLR++) {
        /* getLoc-3
         */
        if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
          jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
        } else {
          jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
        }

        if (DrawShapes_DW_Points[col] < 0.0) {
          ku = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
        } else {
          ku = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
        }

        if (jRowsIn - 1 != ku - 1) {
          /* getLoc-3
           */
          if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          if (DrawShapes_DW_Points[col] < 0.0) {
            ku = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
          } else {
            ku = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
          }

          if (jRowsIn - 1 < ku - 1) {
            countTwice = false;
          } else {
            countTwice = true;
            idxTmp = activeCol;
            activeCol = idxRow2;
            idxRow2 = idxTmp;
            idxTmp = parallelTo_XorYaxis2;
            parallelTo_XorYaxis2 = col;
            col = idxTmp;
          }

          /* getLoc-3
           */
          /* Initialize a Bresenham line. */
          if (DrawShapes_DW_Points[activeCol] < 0.0) {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[activeCol] - 0.5);
          } else {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[activeCol] + 0.5);
          }

          loc = ((jRowsIn - 1) << 3) + 4;
          if (DrawShapes_DW_Points[parallelTo_XorYaxis2] < 0.0) {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] - 0.5);
          } else {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[parallelTo_XorYaxis2] + 0.5);
          }

          loc_0 = ((jRowsIn - 1) << 3) + 4;
          if (DrawShapes_DW_Points[idxRow2] < 0.0) {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[idxRow2] - 0.5);
          } else {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[idxRow2] + 0.5);
          }

          line_idx_1 = ((jRowsIn - 1) << 3) + 4;
          if (DrawShapes_DW_Points[col] < 0.0) {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[col] - 0.5);
          } else {
            jRowsIn = (int32_T)(DrawShapes_DW_Points[col] + 0.5);
          }

          numActiveEdge = ((jRowsIn - 1) << 3) + 4;
          idxTmp = numActiveEdge - loc_0;
          DrawShapes2_DW_Polygon[idxMaxVal] = 0;
          DrawShapes2_DW_Polygon[idxMaxVal + 1] = loc;
          DrawShapes2_DW_Polygon[idxMaxVal + 2] = loc_0;
          DrawShapes2_DW_Polygon[idxMaxVal + 3] = numActiveEdge;
          DrawShapes2_DW_Polygon[idxMaxVal + 6] = 0;
          if (line_idx_1 >= loc) {
            DrawShapes2_DW_Polygon[idxMaxVal + 8] = line_idx_1 - loc;
          } else {
            DrawShapes2_DW_Polygon[idxMaxVal + 8] = loc - line_idx_1;
          }

          while (DrawShapes2_DW_Polygon[idxMaxVal + 8] >= 0) {
            DrawShapes2_DW_Polygon[idxMaxVal + 6]++;
            DrawShapes2_DW_Polygon[idxMaxVal + 8] -= idxTmp;
          }

          DrawShapes2_DW_Polygon[idxMaxVal + 5] =
            DrawShapes2_DW_Polygon[idxMaxVal + 6] - 1;
          DrawShapes2_DW_Polygon[idxMaxVal + 7] =
            DrawShapes2_DW_Polygon[idxMaxVal + 8] + idxTmp;
          DrawShapes2_DW_Polygon[idxMaxVal + 4] = idxTmp -
            (DrawShapes2_DW_Polygon[idxMaxVal + 7] << 1);
          if (loc > line_idx_1) {
            DrawShapes2_DW_Polygon[idxMaxVal + 5] =
              -DrawShapes2_DW_Polygon[idxMaxVal + 5];
            DrawShapes2_DW_Polygon[idxMaxVal + 6] =
              -DrawShapes2_DW_Polygon[idxMaxVal + 6];
          }

          if ((!isMore) && (!countTwice)) {
            /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
            DrawShapes2_DW_Polygon[idxMaxVal + 2]++;
            if ((DrawShapes2_DW_Polygon[idxMaxVal] << 1) >
                DrawShapes2_DW_Polygon[idxMaxVal + 4]) {
              DrawShapes2_DW_Polygon[idxMaxVal] +=
                DrawShapes2_DW_Polygon[idxMaxVal + 8];
              DrawShapes2_DW_Polygon[idxMaxVal + 1] +=
                DrawShapes2_DW_Polygon[idxMaxVal + 6];
            } else {
              DrawShapes2_DW_Polygon[idxMaxVal] +=
                DrawShapes2_DW_Polygon[idxMaxVal + 7];
              DrawShapes2_DW_Polygon[idxMaxVal + 1] +=
                DrawShapes2_DW_Polygon[idxMaxVal + 5];
            }
          } else {
            if (isMore && countTwice) {
              DrawShapes2_DW_Polygon[idxMaxVal + 3]--;
            }
          }

          isMore = countTwice;
          if (!prevEdgeIsVertical) {
            /* Merge two Bresenham lines. */
            if ((idxEdgePre != idxMaxVal) && ((DrawShapes2_DW_Polygon[idxEdgePre
                  + 5] == DrawShapes2_DW_Polygon[idxMaxVal + 5]) &&
                 (DrawShapes2_DW_Polygon[idxEdgePre + 6] ==
                  DrawShapes2_DW_Polygon[idxMaxVal + 6]) &&
                 (DrawShapes2_DW_Polygon[idxEdgePre + 7] ==
                  DrawShapes2_DW_Polygon[idxMaxVal + 7]) &&
                 (DrawShapes2_DW_Polygon[idxEdgePre + 8] ==
                  DrawShapes2_DW_Polygon[idxMaxVal + 8]))) {
              if (DrawShapes2_DW_Polygon[idxEdgePre + 3] + 1 ==
                  DrawShapes2_DW_Polygon[idxMaxVal + 2]) {
                DrawShapes2_DW_Polygon[idxEdgePre + 3] =
                  DrawShapes2_DW_Polygon[idxMaxVal + 3];
                prevEdgeIsVertical = true;
              } else {
                if (DrawShapes2_DW_Polygon[idxMaxVal + 3] + 1 ==
                    DrawShapes2_DW_Polygon[idxEdgePre + 2]) {
                  DrawShapes2_DW_Polygon[idxEdgePre + 1] =
                    DrawShapes2_DW_Polygon[idxMaxVal + 1];
                  DrawShapes2_DW_Polygon[idxEdgePre + 2] =
                    DrawShapes2_DW_Polygon[idxMaxVal + 2];
                  prevEdgeIsVertical = true;
                }
              }
            }

            if (!prevEdgeIsVertical) {
              idxEdgePre = idxMaxVal;
              numEdge++;
            }
          } else {
            idxEdgePre = idxMaxVal;
            numEdge++;
          }

          idxMaxVal = idxEdgePre + 9;
          if (!countTwice) {
            activeCol = idxRow2;
            parallelTo_XorYaxis2 = col;
          }

          idxRow2 = activeCol + 2;
          col = parallelTo_XorYaxis2 + 2;
          prevEdgeIsVertical = false;
        } else {
          prevEdgeIsVertical = true;
          activeCol = idxRow2;
          parallelTo_XorYaxis2 = col;
          idxRow2 += 2;
          col += 2;
        }
      }

      q2 = 1;
    }

    if (!done) {
      /* Merge two Bresenham lines. */
      if ((inIdx != idxEdgePre) && ((DrawShapes2_DW_Polygon[inIdx + 5] ==
            DrawShapes2_DW_Polygon[idxEdgePre + 5]) &&
           (DrawShapes2_DW_Polygon[inIdx + 6] ==
            DrawShapes2_DW_Polygon[idxEdgePre + 6]) &&
           (DrawShapes2_DW_Polygon[inIdx + 7] ==
            DrawShapes2_DW_Polygon[idxEdgePre + 7]) &&
           (DrawShapes2_DW_Polygon[inIdx + 8] ==
            DrawShapes2_DW_Polygon[idxEdgePre + 8]))) {
        if (DrawShapes2_DW_Polygon[inIdx + 3] + 1 ==
            DrawShapes2_DW_Polygon[idxEdgePre + 2]) {
          DrawShapes2_DW_Polygon[inIdx + 3] = DrawShapes2_DW_Polygon[idxEdgePre
            + 3];
          done = true;
        } else {
          if (DrawShapes2_DW_Polygon[idxEdgePre + 3] + 1 ==
              DrawShapes2_DW_Polygon[inIdx + 2]) {
            DrawShapes2_DW_Polygon[inIdx + 1] =
              DrawShapes2_DW_Polygon[idxEdgePre + 1];
            DrawShapes2_DW_Polygon[inIdx + 2] =
              DrawShapes2_DW_Polygon[idxEdgePre + 2];
            done = true;
          }
        }
      }

      if (done) {
        numEdge--;
        idxMaxVal -= 9;
      }
    }

    /* Set all other edges to invalid. */
    for (imgIdxLR = numEdge; imgIdxLR < 4; imgIdxLR++) {
      DrawShapes2_DW_Polygon[idxMaxVal + 2] = 1;
      DrawShapes2_DW_Polygon[idxMaxVal + 3] = 0;
      idxMaxVal += 9;
    }

    /* Sort the boundaries of the polygon. */
    isMore = true;
    while (isMore) {
      idxNew = inIdx;
      idxOld = inIdx + 9;
      isMore = false;
      for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
        if (DrawShapes2_DW_Polygon[idxNew + 2] > DrawShapes2_DW_Polygon[idxOld +
            2]) {
          isMore = true;
          for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
            edgeTmp = DrawShapes2_DW_Polygon[idxNew + line_idx_1];
            DrawShapes2_DW_Polygon[idxNew + line_idx_1] =
              DrawShapes2_DW_Polygon[idxOld + line_idx_1];
            DrawShapes2_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
          }
        }

        idxNew = idxOld;
        idxOld += 9;
      }
    }

    /* Find out the last column of the polygon. */
    parallelTo_XorYaxis2 = inIdx + 3;
    q2 = DrawShapes2_DW_Polygon[inIdx + 3];
    for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
      parallelTo_XorYaxis2 += 9;
      if (q2 < DrawShapes2_DW_Polygon[parallelTo_XorYaxis2]) {
        q2 = DrawShapes2_DW_Polygon[parallelTo_XorYaxis2];
      }
    }

    ku = q2;
    if (q2 > 10239) {
      ku = 10239;
    }

    /* Find out the first column of the polygon. */
    parallelTo_XorYaxis2 = inIdx + 2;
    q2 = DrawShapes2_DW_Polygon[inIdx + 2];
    for (imgIdxLR = 1; imgIdxLR < numEdge; imgIdxLR++) {
      parallelTo_XorYaxis2 += 9;
      if (q2 > DrawShapes2_DW_Polygon[parallelTo_XorYaxis2]) {
        q2 = DrawShapes2_DW_Polygon[parallelTo_XorYaxis2];
      }
    }

    if (q2 < 0) {
      q2 = 0;
    }

    /* Move to the next column and find out boundaries of the polygon at this column. */
    idxNew = inIdx;
    idxOld = inIdx;
    loopEndIdx = inIdx;
    idxEdgePre = 0;
    numActiveEdge = 0;
    for (imgIdxLR = 0; imgIdxLR < numEdge; imgIdxLR++) {
      /* Find out the valid boundaries and bring them to the latest column. */
      if (DrawShapes2_DW_Polygon[idxOld + 3] >= q2) {
        if (DrawShapes2_DW_Polygon[idxOld + 2] <= q2) {
          while (DrawShapes2_DW_Polygon[idxOld + 2] < q2) {
            /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
            DrawShapes2_DW_Polygon[idxOld + 2]++;
            if ((DrawShapes2_DW_Polygon[idxOld] << 1) >
                DrawShapes2_DW_Polygon[idxOld + 4]) {
              DrawShapes2_DW_Polygon[idxOld] += DrawShapes2_DW_Polygon[idxOld +
                8];
              DrawShapes2_DW_Polygon[idxOld + 1] +=
                DrawShapes2_DW_Polygon[idxOld + 6];
            } else {
              DrawShapes2_DW_Polygon[idxOld] += DrawShapes2_DW_Polygon[idxOld +
                7];
              DrawShapes2_DW_Polygon[idxOld + 1] +=
                DrawShapes2_DW_Polygon[idxOld + 5];
            }
          }

          loopEndIdx += 9;
          numActiveEdge++;
        }

        if (idxOld != idxNew) {
          for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
            DrawShapes2_DW_Polygon[idxNew + line_idx_1] =
              DrawShapes2_DW_Polygon[idxOld + line_idx_1];
          }
        }

        idxNew += 9;
        idxEdgePre++;
      }

      idxOld += 9;
    }

    /* Sort the boundaries of the polygon according to row values. */
    /* Sort the boundaries of the polygon. */
    isMore = true;
    while (isMore) {
      idxNew = inIdx;
      idxOld = inIdx + 9;
      isMore = false;
      for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
        if (DrawShapes2_DW_Polygon[idxNew + 1] > DrawShapes2_DW_Polygon[idxOld +
            1]) {
          isMore = true;
          for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
            edgeTmp = DrawShapes2_DW_Polygon[idxNew + line_idx_1];
            DrawShapes2_DW_Polygon[idxNew + line_idx_1] =
              DrawShapes2_DW_Polygon[idxOld + line_idx_1];
            DrawShapes2_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
          }
        }

        idxNew = idxOld;
        idxOld += 9;
      }
    }

    numActiveEdge = inIdx;
    idxMaxVal = q2 + 1;
    activeCol = 0;
    idxNew = 0;
    idxOld = -1;
    idxRow2 = q2 >> 3;
    idxTmp = (idxRow2 + 1) << 3;
    loc = 720;
    loc_0 = 0;
    isMore = (0 <= ku);
    while (isMore) {
      /* Get a string of pixels */
      countTwice = false;
      done = (idxNew != 0);
      col = activeCol;
      if ((activeCol >= q2) && (activeCol <= ku)) {
        if (numActiveEdge < loopEndIdx) {
          imgIdxLR = DrawShapes2_DW_Polygon[numActiveEdge + 1];
          numActiveEdge += 9;
          if ((imgIdxLR == idxOld) && (numActiveEdge < loopEndIdx)) {
            numEdge = DrawShapes2_DW_Polygon[numActiveEdge + 1];
            isMore = (numActiveEdge < loopEndIdx);
            while (isMore && (imgIdxLR == numEdge)) {
              countTwice = true;
              imgIdxLR = DrawShapes2_DW_Polygon[numActiveEdge + 1];
              numActiveEdge += 9;
              isMore = (numActiveEdge < loopEndIdx);
              if (isMore) {
                numEdge = DrawShapes2_DW_Polygon[numActiveEdge + 1];
              }
            }

            if (!isMore) {
              countTwice = false;
            }
          }

          if (idxNew != 0) {
            firstRow = idxOld;
            if (imgIdxLR <= 5759) {
              parallelTo_XorYaxis2 = imgIdxLR;
              idxOld = imgIdxLR;
            } else {
              parallelTo_XorYaxis2 = 5759;
              idxOld = 5759;
            }
          } else {
            firstRow = idxOld + 1;
            if ((imgIdxLR > 0) && (imgIdxLR <= 5759)) {
              parallelTo_XorYaxis2 = imgIdxLR - 1;
              idxOld = imgIdxLR;
            } else if (imgIdxLR <= 0) {
              parallelTo_XorYaxis2 = -1;
              idxOld = 0;
            } else {
              parallelTo_XorYaxis2 = 5759;
              idxOld = 5760;
            }
          }

          if (!countTwice) {
            idxNew = !(idxNew != 0);
          }
        } else {
          /* Reset states and move to the next column. */
          done = false;
          firstRow = idxOld + 1;
          parallelTo_XorYaxis2 = 5759;

          /* Move to the next column and find out boundaries of the polygon at this column. */
          idxNew = inIdx;
          idxOld = inIdx;
          loopEndIdx = inIdx;
          numEdge = 0;
          numActiveEdge = 0;
          for (imgIdxLR = 0; imgIdxLR < idxEdgePre; imgIdxLR++) {
            /* Find out the valid boundaries and bring them to the latest column. */
            if (DrawShapes2_DW_Polygon[idxOld + 3] >= idxMaxVal) {
              if (DrawShapes2_DW_Polygon[idxOld + 2] <= idxMaxVal) {
                while (DrawShapes2_DW_Polygon[idxOld + 2] < idxMaxVal) {
                  /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                  DrawShapes2_DW_Polygon[idxOld + 2]++;
                  if ((DrawShapes2_DW_Polygon[idxOld] << 1) >
                      DrawShapes2_DW_Polygon[idxOld + 4]) {
                    DrawShapes2_DW_Polygon[idxOld] +=
                      DrawShapes2_DW_Polygon[idxOld + 8];
                    DrawShapes2_DW_Polygon[idxOld + 1] +=
                      DrawShapes2_DW_Polygon[idxOld + 6];
                  } else {
                    DrawShapes2_DW_Polygon[idxOld] +=
                      DrawShapes2_DW_Polygon[idxOld + 7];
                    DrawShapes2_DW_Polygon[idxOld + 1] +=
                      DrawShapes2_DW_Polygon[idxOld + 5];
                  }
                }

                loopEndIdx += 9;
                numActiveEdge++;
              }

              if (idxOld != idxNew) {
                for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                  DrawShapes2_DW_Polygon[idxNew + line_idx_1] =
                    DrawShapes2_DW_Polygon[idxOld + line_idx_1];
                }
              }

              idxNew += 9;
              numEdge++;
            }

            idxOld += 9;
          }

          idxEdgePre = numEdge;

          /* Sort the boundaries of the polygon according to row values. */
          /* Sort the boundaries of the polygon. */
          while (isMore) {
            idxNew = inIdx;
            idxOld = inIdx + 9;
            isMore = false;
            for (imgIdxLR = 1; imgIdxLR < numActiveEdge; imgIdxLR++) {
              if (DrawShapes2_DW_Polygon[idxNew + 1] >
                  DrawShapes2_DW_Polygon[idxOld + 1]) {
                isMore = true;
                for (line_idx_1 = 0; line_idx_1 < 9; line_idx_1++) {
                  edgeTmp = DrawShapes2_DW_Polygon[idxNew + line_idx_1];
                  DrawShapes2_DW_Polygon[idxNew + line_idx_1] =
                    DrawShapes2_DW_Polygon[idxOld + line_idx_1];
                  DrawShapes2_DW_Polygon[idxOld + line_idx_1] = edgeTmp;
                }
              }

              idxNew = idxOld;
              idxOld += 9;
            }
          }

          numActiveEdge = inIdx;
          idxMaxVal++;
          idxNew = 0;
          idxOld = -1;
          activeCol++;
        }
      } else {
        firstRow = 0;
        parallelTo_XorYaxis2 = 5759;
        activeCol++;
      }

      if (firstRow < 0) {
        firstRow = 0;
      }

      if (parallelTo_XorYaxis2 < firstRow) {
        parallelTo_XorYaxis2 = firstRow - 1;
      }

      if (done && ((parallelTo_XorYaxis2 > 0) && (firstRow < 5759))) {
        if (parallelTo_XorYaxis2 > 5759) {
          parallelTo_XorYaxis2 = 5759;
        }

        numEdge = firstRow >> 3;
        imgIdxLR = parallelTo_XorYaxis2 >> 3;
        if (loc > numEdge) {
          loc = numEdge;
        }

        if (loc_0 < imgIdxLR) {
          loc_0 = imgIdxLR;
        }

        if (imgIdxLR > numEdge) {
          DrawShapes2_DW_PixCount[numEdge] = (uint8_T)(((uint32_T)((numEdge + 1)
            << 3) + DrawShapes2_DW_PixCount[numEdge]) - firstRow);
          DrawShapes2_DW_PixCount[imgIdxLR] = (uint8_T)((((uint32_T)
            DrawShapes2_DW_PixCount[imgIdxLR] + parallelTo_XorYaxis2) -
            (imgIdxLR << 3)) + 1U);
          for (firstRow = numEdge + 1; firstRow < imgIdxLR; firstRow++) {
            DrawShapes2_DW_PixCount[firstRow] = (uint8_T)
              (DrawShapes2_DW_PixCount[firstRow] + 8U);
          }
        } else {
          if (imgIdxLR == numEdge) {
            DrawShapes2_DW_PixCount[numEdge] = (uint8_T)((((uint32_T)
              DrawShapes2_DW_PixCount[numEdge] + parallelTo_XorYaxis2) -
              firstRow) + 1U);
          }
        }
      }

      isMore = (activeCol <= ku);
      if (((idxTmp - 1 == col) || (!isMore)) && (parallelTo_XorYaxis2 >= 5759))
      {
        edgeTmp = idxRow2 * 720 + loc;
        line_idx_1 = edgeTmp;
        for (firstRow = loc; firstRow <= loc_0; firstRow++) {
          if (DrawShapes2_DW_PixCount[firstRow] == 64) {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[0] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY;
          } else {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[0] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY * (real32_T)
              DrawShapes2_DW_PixCount[firstRow] / 64.0F;
          }

          line_idx_1++;
        }

        edgeTmp += 921600;
        line_idx_1 = edgeTmp;
        for (firstRow = loc; firstRow <= loc_0; firstRow++) {
          if (DrawShapes2_DW_PixCount[firstRow] == 64) {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[1] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY;
          } else {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[1] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY * (real32_T)
              DrawShapes2_DW_PixCount[firstRow] / 64.0F;
          }

          line_idx_1++;
        }

        edgeTmp += 921600;
        line_idx_1 = edgeTmp;
        for (firstRow = loc; firstRow <= loc_0; firstRow++) {
          if (DrawShapes2_DW_PixCount[firstRow] == 64) {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[2] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY;
          } else {
            Houghline_real_fast_2_B.DrawShapes2[line_idx_1] +=
              (Houghline_real_fast_2_P.DrawShapes2_RTP_FILLCOLOR[2] -
               Houghline_real_fast_2_B.DrawShapes2[line_idx_1]) *
              Houghline_real_fast_2_P.DrawShapes2_RTP_OPACITY * (real32_T)
              DrawShapes2_DW_PixCount[firstRow] / 64.0F;
          }

          line_idx_1++;
        }

        while (loc <= loc_0) {
          DrawShapes2_DW_PixCount[loc] = 0U;
          loc++;
        }

        idxRow2++;
        idxTmp += 8;
        loc = 720;
        loc_0 = 0;
      }
    }

    /* Move to the next polygon. */
    inIdx += 36;
    isMore = (inIdx < 36);
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes2' */

  /* S-Function (sviptextrender): '<Root>/Insert Text' */
  /* put the pen at the beginning of the string */
  imgIdxLR = 1;

  /* copy input to output since Simulink isn't giving us in-place operation */
  memcpy(&Houghline_real_fast_2_B.InsertText[0],
         &Houghline_real_fast_2_B.DrawShapes2[0], 2764800U * sizeof(real32_T));
  while (imgIdxLR > 0) {
    done = true;
    if (Houghline_real_fast_2_P.InsertText_textOpacity == 0.0F) {
      done = false;
    }

    /* copy location to int32 container */
    inIdx = Houghline_real_fast_2_P.InsertText_textLoc[0] - 1;

    /* update the color/intensity */
    Houghline_real_fast_2_DW.InsertText_colorVectorDW[0] =
      Houghline_real_fast_2_P.InsertText_textColor[0];

    /* Saturate color values */
    if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[0] < 0.0F) {
      Houghline_real_fast_2_DW.InsertText_colorVectorDW[0] = 0.0F;
    } else {
      if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[0] > 1.0F) {
        Houghline_real_fast_2_DW.InsertText_colorVectorDW[0] = 1.0F;
      }
    }

    Houghline_real_fast_2_DW.InsertText_colorVectorDW[1] =
      Houghline_real_fast_2_P.InsertText_textColor[1];

    /* Saturate color values */
    if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[1] < 0.0F) {
      Houghline_real_fast_2_DW.InsertText_colorVectorDW[1] = 0.0F;
    } else {
      if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[1] > 1.0F) {
        Houghline_real_fast_2_DW.InsertText_colorVectorDW[1] = 1.0F;
      }
    }

    Houghline_real_fast_2_DW.InsertText_colorVectorDW[2] =
      Houghline_real_fast_2_P.InsertText_textColor[2];

    /* Saturate color values */
    if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[2] < 0.0F) {
      Houghline_real_fast_2_DW.InsertText_colorVectorDW[2] = 0.0F;
    } else {
      if (Houghline_real_fast_2_DW.InsertText_colorVectorDW[2] > 1.0F) {
        Houghline_real_fast_2_DW.InsertText_colorVectorDW[2] = 1.0F;
      }
    }

    q2 = MWVIP_strlen(&Houghline_real_fast_2_DW.InsertText_StringDataDW[0]);
    imgIdxLR = 0;
    if (done) {
      /* put the pen at the beginning of the string */
      jRowsIn = Houghline_real_fast_2_P.InsertText_textLoc[0] - 1;
      isPureFill = Houghline_real_fast_2_P.InsertText_textLoc[1];
      for (idxMaxVal = 0; idxMaxVal < q2; idxMaxVal++) {
        if (Houghline_real_fast_2_DW.InsertText_StringDataDW[idxMaxVal] == 10) {
          isPureFill += 37;
          jRowsIn = inIdx;
        } else {
          numEdge = Houghline_real_fast_2_DW.InsertText_StringDataDW[idxMaxVal];
          ku = (int32_T)
            Houghline_real_fast_2_ConstP.InsertText_GlyIndexes[numEdge];
          if (!((Houghline_real_fast_2_ConstP.InsertText_GlyWidths[numEdge] != 0)
                && (Houghline_real_fast_2_ConstP.InsertText_GlyHeights[numEdge]
                    != 0) &&
                (Houghline_real_fast_2_ConstP.InsertText_GlyXAdvances[numEdge]
                 != 0))) {
            numEdge = 32;
            ku = 0;
          }

          acc1_idx_0 = Houghline_real_fast_2_P.InsertText_textOpacity;
          MWVIP_DrawText_I_single_AA
            (&Houghline_real_fast_2_ConstP.InsertText_GlyData[ku], jRowsIn,
             isPureFill + 29,
             Houghline_real_fast_2_ConstP.InsertText_GlyLBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyTBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyWidths[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyHeights[numEdge], 1280U,
             720U, &Houghline_real_fast_2_B.InsertText[0],
             &Houghline_real_fast_2_DW.InsertText_colorVectorDW[0], &acc1_idx_0,
             false);
          MWVIP_DrawText_I_single_AA
            (&Houghline_real_fast_2_ConstP.InsertText_GlyData[ku], jRowsIn,
             isPureFill + 29,
             Houghline_real_fast_2_ConstP.InsertText_GlyLBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyTBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyWidths[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyHeights[numEdge], 1280U,
             720U, &Houghline_real_fast_2_B.InsertText[921600],
             &Houghline_real_fast_2_DW.InsertText_colorVectorDW[1], &acc1_idx_0,
             false);
          MWVIP_DrawText_I_single_AA
            (&Houghline_real_fast_2_ConstP.InsertText_GlyData[ku], jRowsIn,
             isPureFill + 29,
             Houghline_real_fast_2_ConstP.InsertText_GlyLBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyTBearings[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyWidths[numEdge],
             Houghline_real_fast_2_ConstP.InsertText_GlyHeights[numEdge], 1280U,
             720U, &Houghline_real_fast_2_B.InsertText[1843200],
             &Houghline_real_fast_2_DW.InsertText_colorVectorDW[2], &acc1_idx_0,
             false);
          jRowsIn +=
            Houghline_real_fast_2_ConstP.InsertText_GlyXAdvances[numEdge];
        }
      }
    }
  }

  /* End of S-Function (sviptextrender): '<Root>/Insert Text' */

  /* Selector: '<Root>/Selector' */
  rtb_Selector_n = Theta_out;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Houghline_real_fast_2_M->rtwLogInfo,
                      (&Houghline_real_fast_2_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
    if ((rtmGetTFinal(Houghline_real_fast_2_M)!=-1) &&
        !((rtmGetTFinal(Houghline_real_fast_2_M)-
           Houghline_real_fast_2_M->Timing.taskTime0) >
          Houghline_real_fast_2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Houghline_real_fast_2_M, "Simulation finished");
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
  if (!(++Houghline_real_fast_2_M->Timing.clockTick0)) {
    ++Houghline_real_fast_2_M->Timing.clockTickH0;
  }

  Houghline_real_fast_2_M->Timing.taskTime0 =
    Houghline_real_fast_2_M->Timing.clockTick0 *
    Houghline_real_fast_2_M->Timing.stepSize0 +
    Houghline_real_fast_2_M->Timing.clockTickH0 *
    Houghline_real_fast_2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Houghline_real_fast_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Houghline_real_fast_2_M, 0,
                sizeof(RT_MODEL_Houghline_real_fast__T));
  rtmSetTFinal(Houghline_real_fast_2_M, 100.0);
  Houghline_real_fast_2_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Houghline_real_fast_2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Houghline_real_fast_2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Houghline_real_fast_2_M->rtwLogInfo, (NULL));
    rtliSetLogT(Houghline_real_fast_2_M->rtwLogInfo, "tout");
    rtliSetLogX(Houghline_real_fast_2_M->rtwLogInfo, "");
    rtliSetLogXFinal(Houghline_real_fast_2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Houghline_real_fast_2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Houghline_real_fast_2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Houghline_real_fast_2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Houghline_real_fast_2_M->rtwLogInfo, 1);
    rtliSetLogY(Houghline_real_fast_2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Houghline_real_fast_2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Houghline_real_fast_2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Houghline_real_fast_2_B), 0,
                sizeof(B_Houghline_real_fast_2_T));

  {
    Houghline_real_fast_2_B.HoughTransform_o2[0] = -1.5707963267948966;
    Houghline_real_fast_2_B.HoughTransform_o2[1] = -1.562069680534925;
    Houghline_real_fast_2_B.HoughTransform_o2[2] = -1.5533430342749532;
    Houghline_real_fast_2_B.HoughTransform_o2[3] = -1.5446163880149817;
    Houghline_real_fast_2_B.HoughTransform_o2[4] = -1.53588974175501;
    Houghline_real_fast_2_B.HoughTransform_o2[5] = -1.5271630954950384;
    Houghline_real_fast_2_B.HoughTransform_o2[6] = -1.5184364492350666;
    Houghline_real_fast_2_B.HoughTransform_o2[7] = -1.509709802975095;
    Houghline_real_fast_2_B.HoughTransform_o2[8] = -1.5009831567151235;
    Houghline_real_fast_2_B.HoughTransform_o2[9] = -1.4922565104551517;
    Houghline_real_fast_2_B.HoughTransform_o2[10] = -1.4835298641951802;
    Houghline_real_fast_2_B.HoughTransform_o2[11] = -1.4748032179352084;
    Houghline_real_fast_2_B.HoughTransform_o2[12] = -1.4660765716752369;
    Houghline_real_fast_2_B.HoughTransform_o2[13] = -1.4573499254152651;
    Houghline_real_fast_2_B.HoughTransform_o2[14] = -1.4486232791552935;
    Houghline_real_fast_2_B.HoughTransform_o2[15] = -1.4398966328953218;
    Houghline_real_fast_2_B.HoughTransform_o2[16] = -1.4311699866353502;
    Houghline_real_fast_2_B.HoughTransform_o2[17] = -1.4224433403753787;
    Houghline_real_fast_2_B.HoughTransform_o2[18] = -1.4137166941154069;
    Houghline_real_fast_2_B.HoughTransform_o2[19] = -1.4049900478554354;
    Houghline_real_fast_2_B.HoughTransform_o2[20] = -1.3962634015954636;
    Houghline_real_fast_2_B.HoughTransform_o2[21] = -1.387536755335492;
    Houghline_real_fast_2_B.HoughTransform_o2[22] = -1.3788101090755203;
    Houghline_real_fast_2_B.HoughTransform_o2[23] = -1.3700834628155487;
    Houghline_real_fast_2_B.HoughTransform_o2[24] = -1.3613568165555769;
    Houghline_real_fast_2_B.HoughTransform_o2[25] = -1.3526301702956054;
    Houghline_real_fast_2_B.HoughTransform_o2[26] = -1.3439035240356338;
    Houghline_real_fast_2_B.HoughTransform_o2[27] = -1.3351768777756621;
    Houghline_real_fast_2_B.HoughTransform_o2[28] = -1.3264502315156905;
    Houghline_real_fast_2_B.HoughTransform_o2[29] = -1.3177235852557188;
    Houghline_real_fast_2_B.HoughTransform_o2[30] = -1.3089969389957472;
    Houghline_real_fast_2_B.HoughTransform_o2[31] = -1.3002702927357754;
    Houghline_real_fast_2_B.HoughTransform_o2[32] = -1.2915436464758039;
    Houghline_real_fast_2_B.HoughTransform_o2[33] = -1.2828170002158321;
    Houghline_real_fast_2_B.HoughTransform_o2[34] = -1.2740903539558606;
    Houghline_real_fast_2_B.HoughTransform_o2[35] = -1.265363707695889;
    Houghline_real_fast_2_B.HoughTransform_o2[36] = -1.2566370614359172;
    Houghline_real_fast_2_B.HoughTransform_o2[37] = -1.2479104151759457;
    Houghline_real_fast_2_B.HoughTransform_o2[38] = -1.2391837689159739;
    Houghline_real_fast_2_B.HoughTransform_o2[39] = -1.2304571226560024;
    Houghline_real_fast_2_B.HoughTransform_o2[40] = -1.2217304763960306;
    Houghline_real_fast_2_B.HoughTransform_o2[41] = -1.2130038301360591;
    Houghline_real_fast_2_B.HoughTransform_o2[42] = -1.2042771838760873;
    Houghline_real_fast_2_B.HoughTransform_o2[43] = -1.1955505376161157;
    Houghline_real_fast_2_B.HoughTransform_o2[44] = -1.1868238913561442;
    Houghline_real_fast_2_B.HoughTransform_o2[45] = -1.1780972450961724;
    Houghline_real_fast_2_B.HoughTransform_o2[46] = -1.1693705988362009;
    Houghline_real_fast_2_B.HoughTransform_o2[47] = -1.1606439525762291;
    Houghline_real_fast_2_B.HoughTransform_o2[48] = -1.1519173063162575;
    Houghline_real_fast_2_B.HoughTransform_o2[49] = -1.1431906600562858;
    Houghline_real_fast_2_B.HoughTransform_o2[50] = -1.1344640137963142;
    Houghline_real_fast_2_B.HoughTransform_o2[51] = -1.1257373675363425;
    Houghline_real_fast_2_B.HoughTransform_o2[52] = -1.1170107212763709;
    Houghline_real_fast_2_B.HoughTransform_o2[53] = -1.1082840750163994;
    Houghline_real_fast_2_B.HoughTransform_o2[54] = -1.0995574287564276;
    Houghline_real_fast_2_B.HoughTransform_o2[55] = -1.090830782496456;
    Houghline_real_fast_2_B.HoughTransform_o2[56] = -1.0821041362364843;
    Houghline_real_fast_2_B.HoughTransform_o2[57] = -1.0733774899765127;
    Houghline_real_fast_2_B.HoughTransform_o2[58] = -1.064650843716541;
    Houghline_real_fast_2_B.HoughTransform_o2[59] = -1.0559241974565694;
    Houghline_real_fast_2_B.HoughTransform_o2[60] = -1.0471975511965976;
    Houghline_real_fast_2_B.HoughTransform_o2[61] = -1.0384709049366261;
    Houghline_real_fast_2_B.HoughTransform_o2[62] = -1.0297442586766545;
    Houghline_real_fast_2_B.HoughTransform_o2[63] = -1.0210176124166828;
    Houghline_real_fast_2_B.HoughTransform_o2[64] = -1.0122909661567112;
    Houghline_real_fast_2_B.HoughTransform_o2[65] = -1.0035643198967394;
    Houghline_real_fast_2_B.HoughTransform_o2[66] = -0.99483767363676789;
    Houghline_real_fast_2_B.HoughTransform_o2[67] = -0.98611102737679623;
    Houghline_real_fast_2_B.HoughTransform_o2[68] = -0.97738438111682457;
    Houghline_real_fast_2_B.HoughTransform_o2[69] = -0.96865773485685291;
    Houghline_real_fast_2_B.HoughTransform_o2[70] = -0.95993108859688125;
    Houghline_real_fast_2_B.HoughTransform_o2[71] = -0.95120444233690959;
    Houghline_real_fast_2_B.HoughTransform_o2[72] = -0.94247779607693793;
    Houghline_real_fast_2_B.HoughTransform_o2[73] = -0.93375114981696627;
    Houghline_real_fast_2_B.HoughTransform_o2[74] = -0.92502450355699462;
    Houghline_real_fast_2_B.HoughTransform_o2[75] = -0.91629785729702307;
    Houghline_real_fast_2_B.HoughTransform_o2[76] = -0.90757121103705141;
    Houghline_real_fast_2_B.HoughTransform_o2[77] = -0.89884456477707975;
    Houghline_real_fast_2_B.HoughTransform_o2[78] = -0.89011791851710809;
    Houghline_real_fast_2_B.HoughTransform_o2[79] = -0.88139127225713643;
    Houghline_real_fast_2_B.HoughTransform_o2[80] = -0.87266462599716477;
    Houghline_real_fast_2_B.HoughTransform_o2[81] = -0.86393797973719311;
    Houghline_real_fast_2_B.HoughTransform_o2[82] = -0.85521133347722145;
    Houghline_real_fast_2_B.HoughTransform_o2[83] = -0.84648468721724979;
    Houghline_real_fast_2_B.HoughTransform_o2[84] = -0.83775804095727824;
    Houghline_real_fast_2_B.HoughTransform_o2[85] = -0.82903139469730658;
    Houghline_real_fast_2_B.HoughTransform_o2[86] = -0.82030474843733492;
    Houghline_real_fast_2_B.HoughTransform_o2[87] = -0.81157810217736326;
    Houghline_real_fast_2_B.HoughTransform_o2[88] = -0.8028514559173916;
    Houghline_real_fast_2_B.HoughTransform_o2[89] = -0.79412480965741994;
    Houghline_real_fast_2_B.HoughTransform_o2[90] = -0.78539816339744828;
    Houghline_real_fast_2_B.HoughTransform_o2[91] = -0.77667151713747662;
    Houghline_real_fast_2_B.HoughTransform_o2[92] = -0.767944870877505;
    Houghline_real_fast_2_B.HoughTransform_o2[93] = -0.7592182246175333;
    Houghline_real_fast_2_B.HoughTransform_o2[94] = -0.75049157835756175;
    Houghline_real_fast_2_B.HoughTransform_o2[95] = -0.74176493209759009;
    Houghline_real_fast_2_B.HoughTransform_o2[96] = -0.73303828583761843;
    Houghline_real_fast_2_B.HoughTransform_o2[97] = -0.72431163957764677;
    Houghline_real_fast_2_B.HoughTransform_o2[98] = -0.71558499331767511;
    Houghline_real_fast_2_B.HoughTransform_o2[99] = -0.70685834705770345;
    Houghline_real_fast_2_B.HoughTransform_o2[100] = -0.69813170079773179;
    Houghline_real_fast_2_B.HoughTransform_o2[101] = -0.68940505453776013;
    Houghline_real_fast_2_B.HoughTransform_o2[102] = -0.68067840827778847;
    Houghline_real_fast_2_B.HoughTransform_o2[103] = -0.67195176201781692;
    Houghline_real_fast_2_B.HoughTransform_o2[104] = -0.66322511575784526;
    Houghline_real_fast_2_B.HoughTransform_o2[105] = -0.6544984694978736;
    Houghline_real_fast_2_B.HoughTransform_o2[106] = -0.64577182323790194;
    Houghline_real_fast_2_B.HoughTransform_o2[107] = -0.63704517697793028;
    Houghline_real_fast_2_B.HoughTransform_o2[108] = -0.62831853071795862;
    Houghline_real_fast_2_B.HoughTransform_o2[109] = -0.619591884457987;
    Houghline_real_fast_2_B.HoughTransform_o2[110] = -0.6108652381980153;
    Houghline_real_fast_2_B.HoughTransform_o2[111] = -0.60213859193804364;
    Houghline_real_fast_2_B.HoughTransform_o2[112] = -0.59341194567807209;
    Houghline_real_fast_2_B.HoughTransform_o2[113] = -0.58468529941810043;
    Houghline_real_fast_2_B.HoughTransform_o2[114] = -0.57595865315812877;
    Houghline_real_fast_2_B.HoughTransform_o2[115] = -0.56723200689815712;
    Houghline_real_fast_2_B.HoughTransform_o2[116] = -0.55850536063818546;
    Houghline_real_fast_2_B.HoughTransform_o2[117] = -0.5497787143782138;
    Houghline_real_fast_2_B.HoughTransform_o2[118] = -0.54105206811824214;
    Houghline_real_fast_2_B.HoughTransform_o2[119] = -0.53232542185827048;
    Houghline_real_fast_2_B.HoughTransform_o2[120] = -0.52359877559829882;
    Houghline_real_fast_2_B.HoughTransform_o2[121] = -0.51487212933832727;
    Houghline_real_fast_2_B.HoughTransform_o2[122] = -0.50614548307835561;
    Houghline_real_fast_2_B.HoughTransform_o2[123] = -0.49741883681838395;
    Houghline_real_fast_2_B.HoughTransform_o2[124] = -0.48869219055841229;
    Houghline_real_fast_2_B.HoughTransform_o2[125] = -0.47996554429844063;
    Houghline_real_fast_2_B.HoughTransform_o2[126] = -0.47123889803846897;
    Houghline_real_fast_2_B.HoughTransform_o2[127] = -0.46251225177849731;
    Houghline_real_fast_2_B.HoughTransform_o2[128] = -0.4537856055185257;
    Houghline_real_fast_2_B.HoughTransform_o2[129] = -0.44505895925855404;
    Houghline_real_fast_2_B.HoughTransform_o2[130] = -0.43633231299858238;
    Houghline_real_fast_2_B.HoughTransform_o2[131] = -0.42760566673861072;
    Houghline_real_fast_2_B.HoughTransform_o2[132] = -0.41887902047863912;
    Houghline_real_fast_2_B.HoughTransform_o2[133] = -0.41015237421866746;
    Houghline_real_fast_2_B.HoughTransform_o2[134] = -0.4014257279586958;
    Houghline_real_fast_2_B.HoughTransform_o2[135] = -0.39269908169872414;
    Houghline_real_fast_2_B.HoughTransform_o2[136] = -0.38397243543875248;
    Houghline_real_fast_2_B.HoughTransform_o2[137] = -0.37524578917878088;
    Houghline_real_fast_2_B.HoughTransform_o2[138] = -0.36651914291880922;
    Houghline_real_fast_2_B.HoughTransform_o2[139] = -0.35779249665883756;
    Houghline_real_fast_2_B.HoughTransform_o2[140] = -0.3490658503988659;
    Houghline_real_fast_2_B.HoughTransform_o2[141] = -0.34033920413889424;
    Houghline_real_fast_2_B.HoughTransform_o2[142] = -0.33161255787892263;
    Houghline_real_fast_2_B.HoughTransform_o2[143] = -0.32288591161895097;
    Houghline_real_fast_2_B.HoughTransform_o2[144] = -0.31415926535897931;
    Houghline_real_fast_2_B.HoughTransform_o2[145] = -0.30543261909900765;
    Houghline_real_fast_2_B.HoughTransform_o2[146] = -0.29670597283903605;
    Houghline_real_fast_2_B.HoughTransform_o2[147] = -0.28797932657906439;
    Houghline_real_fast_2_B.HoughTransform_o2[148] = -0.27925268031909273;
    Houghline_real_fast_2_B.HoughTransform_o2[149] = -0.27052603405912107;
    Houghline_real_fast_2_B.HoughTransform_o2[150] = -0.26179938779914941;
    Houghline_real_fast_2_B.HoughTransform_o2[151] = -0.2530727415391778;
    Houghline_real_fast_2_B.HoughTransform_o2[152] = -0.24434609527920614;
    Houghline_real_fast_2_B.HoughTransform_o2[153] = -0.23561944901923448;
    Houghline_real_fast_2_B.HoughTransform_o2[154] = -0.22689280275926285;
    Houghline_real_fast_2_B.HoughTransform_o2[155] = -0.21816615649929119;
    Houghline_real_fast_2_B.HoughTransform_o2[156] = -0.20943951023931956;
    Houghline_real_fast_2_B.HoughTransform_o2[157] = -0.2007128639793479;
    Houghline_real_fast_2_B.HoughTransform_o2[158] = -0.19198621771937624;
    Houghline_real_fast_2_B.HoughTransform_o2[159] = -0.18325957145940461;
    Houghline_real_fast_2_B.HoughTransform_o2[160] = -0.17453292519943295;
    Houghline_real_fast_2_B.HoughTransform_o2[161] = -0.16580627893946132;
    Houghline_real_fast_2_B.HoughTransform_o2[162] = -0.15707963267948966;
    Houghline_real_fast_2_B.HoughTransform_o2[163] = -0.14835298641951802;
    Houghline_real_fast_2_B.HoughTransform_o2[164] = -0.13962634015954636;
    Houghline_real_fast_2_B.HoughTransform_o2[165] = -0.1308996938995747;
    Houghline_real_fast_2_B.HoughTransform_o2[166] = -0.12217304763960307;
    Houghline_real_fast_2_B.HoughTransform_o2[167] = -0.11344640137963143;
    Houghline_real_fast_2_B.HoughTransform_o2[168] = -0.10471975511965978;
    Houghline_real_fast_2_B.HoughTransform_o2[169] = -0.09599310885968812;
    Houghline_real_fast_2_B.HoughTransform_o2[170] = -0.087266462599716474;
    Houghline_real_fast_2_B.HoughTransform_o2[171] = -0.078539816339744828;
    Houghline_real_fast_2_B.HoughTransform_o2[172] = -0.069813170079773182;
    Houghline_real_fast_2_B.HoughTransform_o2[173] = -0.061086523819801536;
    Houghline_real_fast_2_B.HoughTransform_o2[174] = -0.05235987755982989;
    Houghline_real_fast_2_B.HoughTransform_o2[175] = -0.043633231299858237;
    Houghline_real_fast_2_B.HoughTransform_o2[176] = -0.034906585039886591;
    Houghline_real_fast_2_B.HoughTransform_o2[177] = -0.026179938779914945;
    Houghline_real_fast_2_B.HoughTransform_o2[178] = -0.017453292519943295;
    Houghline_real_fast_2_B.HoughTransform_o2[179] = -0.0087266462599716477;
    Houghline_real_fast_2_B.HoughTransform_o2[180] = 0.0;
    Houghline_real_fast_2_B.HoughTransform_o2[181] = 0.0087266462599716477;
    Houghline_real_fast_2_B.HoughTransform_o2[182] = 0.017453292519943295;
    Houghline_real_fast_2_B.HoughTransform_o2[183] = 0.026179938779914945;
    Houghline_real_fast_2_B.HoughTransform_o2[184] = 0.034906585039886591;
    Houghline_real_fast_2_B.HoughTransform_o2[185] = 0.043633231299858237;
    Houghline_real_fast_2_B.HoughTransform_o2[186] = 0.05235987755982989;
    Houghline_real_fast_2_B.HoughTransform_o2[187] = 0.061086523819801536;
    Houghline_real_fast_2_B.HoughTransform_o2[188] = 0.069813170079773182;
    Houghline_real_fast_2_B.HoughTransform_o2[189] = 0.078539816339744828;
    Houghline_real_fast_2_B.HoughTransform_o2[190] = 0.087266462599716474;
    Houghline_real_fast_2_B.HoughTransform_o2[191] = 0.09599310885968812;
    Houghline_real_fast_2_B.HoughTransform_o2[192] = 0.10471975511965978;
    Houghline_real_fast_2_B.HoughTransform_o2[193] = 0.11344640137963143;
    Houghline_real_fast_2_B.HoughTransform_o2[194] = 0.12217304763960307;
    Houghline_real_fast_2_B.HoughTransform_o2[195] = 0.1308996938995747;
    Houghline_real_fast_2_B.HoughTransform_o2[196] = 0.13962634015954636;
    Houghline_real_fast_2_B.HoughTransform_o2[197] = 0.14835298641951802;
    Houghline_real_fast_2_B.HoughTransform_o2[198] = 0.15707963267948966;
    Houghline_real_fast_2_B.HoughTransform_o2[199] = 0.16580627893946132;
    Houghline_real_fast_2_B.HoughTransform_o2[200] = 0.17453292519943295;
    Houghline_real_fast_2_B.HoughTransform_o2[201] = 0.18325957145940461;
    Houghline_real_fast_2_B.HoughTransform_o2[202] = 0.19198621771937624;
    Houghline_real_fast_2_B.HoughTransform_o2[203] = 0.2007128639793479;
    Houghline_real_fast_2_B.HoughTransform_o2[204] = 0.20943951023931956;
    Houghline_real_fast_2_B.HoughTransform_o2[205] = 0.21816615649929119;
    Houghline_real_fast_2_B.HoughTransform_o2[206] = 0.22689280275926285;
    Houghline_real_fast_2_B.HoughTransform_o2[207] = 0.23561944901923448;
    Houghline_real_fast_2_B.HoughTransform_o2[208] = 0.24434609527920614;
    Houghline_real_fast_2_B.HoughTransform_o2[209] = 0.2530727415391778;
    Houghline_real_fast_2_B.HoughTransform_o2[210] = 0.26179938779914941;
    Houghline_real_fast_2_B.HoughTransform_o2[211] = 0.27052603405912107;
    Houghline_real_fast_2_B.HoughTransform_o2[212] = 0.27925268031909273;
    Houghline_real_fast_2_B.HoughTransform_o2[213] = 0.28797932657906439;
    Houghline_real_fast_2_B.HoughTransform_o2[214] = 0.29670597283903605;
    Houghline_real_fast_2_B.HoughTransform_o2[215] = 0.30543261909900765;
    Houghline_real_fast_2_B.HoughTransform_o2[216] = 0.31415926535897931;
    Houghline_real_fast_2_B.HoughTransform_o2[217] = 0.32288591161895097;
    Houghline_real_fast_2_B.HoughTransform_o2[218] = 0.33161255787892263;
    Houghline_real_fast_2_B.HoughTransform_o2[219] = 0.34033920413889424;
    Houghline_real_fast_2_B.HoughTransform_o2[220] = 0.3490658503988659;
    Houghline_real_fast_2_B.HoughTransform_o2[221] = 0.35779249665883756;
    Houghline_real_fast_2_B.HoughTransform_o2[222] = 0.36651914291880922;
    Houghline_real_fast_2_B.HoughTransform_o2[223] = 0.37524578917878088;
    Houghline_real_fast_2_B.HoughTransform_o2[224] = 0.38397243543875248;
    Houghline_real_fast_2_B.HoughTransform_o2[225] = 0.39269908169872414;
    Houghline_real_fast_2_B.HoughTransform_o2[226] = 0.4014257279586958;
    Houghline_real_fast_2_B.HoughTransform_o2[227] = 0.41015237421866746;
    Houghline_real_fast_2_B.HoughTransform_o2[228] = 0.41887902047863912;
    Houghline_real_fast_2_B.HoughTransform_o2[229] = 0.42760566673861072;
    Houghline_real_fast_2_B.HoughTransform_o2[230] = 0.43633231299858238;
    Houghline_real_fast_2_B.HoughTransform_o2[231] = 0.44505895925855404;
    Houghline_real_fast_2_B.HoughTransform_o2[232] = 0.4537856055185257;
    Houghline_real_fast_2_B.HoughTransform_o2[233] = 0.46251225177849731;
    Houghline_real_fast_2_B.HoughTransform_o2[234] = 0.47123889803846897;
    Houghline_real_fast_2_B.HoughTransform_o2[235] = 0.47996554429844063;
    Houghline_real_fast_2_B.HoughTransform_o2[236] = 0.48869219055841229;
    Houghline_real_fast_2_B.HoughTransform_o2[237] = 0.49741883681838395;
    Houghline_real_fast_2_B.HoughTransform_o2[238] = 0.50614548307835561;
    Houghline_real_fast_2_B.HoughTransform_o2[239] = 0.51487212933832727;
    Houghline_real_fast_2_B.HoughTransform_o2[240] = 0.52359877559829882;
    Houghline_real_fast_2_B.HoughTransform_o2[241] = 0.53232542185827048;
    Houghline_real_fast_2_B.HoughTransform_o2[242] = 0.54105206811824214;
    Houghline_real_fast_2_B.HoughTransform_o2[243] = 0.5497787143782138;
    Houghline_real_fast_2_B.HoughTransform_o2[244] = 0.55850536063818546;
    Houghline_real_fast_2_B.HoughTransform_o2[245] = 0.56723200689815712;
    Houghline_real_fast_2_B.HoughTransform_o2[246] = 0.57595865315812877;
    Houghline_real_fast_2_B.HoughTransform_o2[247] = 0.58468529941810043;
    Houghline_real_fast_2_B.HoughTransform_o2[248] = 0.59341194567807209;
    Houghline_real_fast_2_B.HoughTransform_o2[249] = 0.60213859193804364;
    Houghline_real_fast_2_B.HoughTransform_o2[250] = 0.6108652381980153;
    Houghline_real_fast_2_B.HoughTransform_o2[251] = 0.619591884457987;
    Houghline_real_fast_2_B.HoughTransform_o2[252] = 0.62831853071795862;
    Houghline_real_fast_2_B.HoughTransform_o2[253] = 0.63704517697793028;
    Houghline_real_fast_2_B.HoughTransform_o2[254] = 0.64577182323790194;
    Houghline_real_fast_2_B.HoughTransform_o2[255] = 0.6544984694978736;
    Houghline_real_fast_2_B.HoughTransform_o2[256] = 0.66322511575784526;
    Houghline_real_fast_2_B.HoughTransform_o2[257] = 0.67195176201781692;
    Houghline_real_fast_2_B.HoughTransform_o2[258] = 0.68067840827778847;
    Houghline_real_fast_2_B.HoughTransform_o2[259] = 0.68940505453776013;
    Houghline_real_fast_2_B.HoughTransform_o2[260] = 0.69813170079773179;
    Houghline_real_fast_2_B.HoughTransform_o2[261] = 0.70685834705770345;
    Houghline_real_fast_2_B.HoughTransform_o2[262] = 0.71558499331767511;
    Houghline_real_fast_2_B.HoughTransform_o2[263] = 0.72431163957764677;
    Houghline_real_fast_2_B.HoughTransform_o2[264] = 0.73303828583761843;
    Houghline_real_fast_2_B.HoughTransform_o2[265] = 0.74176493209759009;
    Houghline_real_fast_2_B.HoughTransform_o2[266] = 0.75049157835756175;
    Houghline_real_fast_2_B.HoughTransform_o2[267] = 0.7592182246175333;
    Houghline_real_fast_2_B.HoughTransform_o2[268] = 0.767944870877505;
    Houghline_real_fast_2_B.HoughTransform_o2[269] = 0.77667151713747662;
    Houghline_real_fast_2_B.HoughTransform_o2[270] = 0.78539816339744828;
    Houghline_real_fast_2_B.HoughTransform_o2[271] = 0.79412480965741994;
    Houghline_real_fast_2_B.HoughTransform_o2[272] = 0.8028514559173916;
    Houghline_real_fast_2_B.HoughTransform_o2[273] = 0.81157810217736326;
    Houghline_real_fast_2_B.HoughTransform_o2[274] = 0.82030474843733492;
    Houghline_real_fast_2_B.HoughTransform_o2[275] = 0.82903139469730658;
    Houghline_real_fast_2_B.HoughTransform_o2[276] = 0.83775804095727824;
    Houghline_real_fast_2_B.HoughTransform_o2[277] = 0.84648468721724979;
    Houghline_real_fast_2_B.HoughTransform_o2[278] = 0.85521133347722145;
    Houghline_real_fast_2_B.HoughTransform_o2[279] = 0.86393797973719311;
    Houghline_real_fast_2_B.HoughTransform_o2[280] = 0.87266462599716477;
    Houghline_real_fast_2_B.HoughTransform_o2[281] = 0.88139127225713643;
    Houghline_real_fast_2_B.HoughTransform_o2[282] = 0.89011791851710809;
    Houghline_real_fast_2_B.HoughTransform_o2[283] = 0.89884456477707975;
    Houghline_real_fast_2_B.HoughTransform_o2[284] = 0.90757121103705141;
    Houghline_real_fast_2_B.HoughTransform_o2[285] = 0.91629785729702307;
    Houghline_real_fast_2_B.HoughTransform_o2[286] = 0.92502450355699462;
    Houghline_real_fast_2_B.HoughTransform_o2[287] = 0.93375114981696627;
    Houghline_real_fast_2_B.HoughTransform_o2[288] = 0.94247779607693793;
    Houghline_real_fast_2_B.HoughTransform_o2[289] = 0.95120444233690959;
    Houghline_real_fast_2_B.HoughTransform_o2[290] = 0.95993108859688125;
    Houghline_real_fast_2_B.HoughTransform_o2[291] = 0.96865773485685291;
    Houghline_real_fast_2_B.HoughTransform_o2[292] = 0.97738438111682457;
    Houghline_real_fast_2_B.HoughTransform_o2[293] = 0.98611102737679623;
    Houghline_real_fast_2_B.HoughTransform_o2[294] = 0.99483767363676789;
    Houghline_real_fast_2_B.HoughTransform_o2[295] = 1.0035643198967394;
    Houghline_real_fast_2_B.HoughTransform_o2[296] = 1.0122909661567112;
    Houghline_real_fast_2_B.HoughTransform_o2[297] = 1.0210176124166828;
    Houghline_real_fast_2_B.HoughTransform_o2[298] = 1.0297442586766545;
    Houghline_real_fast_2_B.HoughTransform_o2[299] = 1.0384709049366261;
    Houghline_real_fast_2_B.HoughTransform_o2[300] = 1.0471975511965976;
    Houghline_real_fast_2_B.HoughTransform_o2[301] = 1.0559241974565694;
    Houghline_real_fast_2_B.HoughTransform_o2[302] = 1.064650843716541;
    Houghline_real_fast_2_B.HoughTransform_o2[303] = 1.0733774899765127;
    Houghline_real_fast_2_B.HoughTransform_o2[304] = 1.0821041362364843;
    Houghline_real_fast_2_B.HoughTransform_o2[305] = 1.090830782496456;
    Houghline_real_fast_2_B.HoughTransform_o2[306] = 1.0995574287564276;
    Houghline_real_fast_2_B.HoughTransform_o2[307] = 1.1082840750163994;
    Houghline_real_fast_2_B.HoughTransform_o2[308] = 1.1170107212763709;
    Houghline_real_fast_2_B.HoughTransform_o2[309] = 1.1257373675363425;
    Houghline_real_fast_2_B.HoughTransform_o2[310] = 1.1344640137963142;
    Houghline_real_fast_2_B.HoughTransform_o2[311] = 1.1431906600562858;
    Houghline_real_fast_2_B.HoughTransform_o2[312] = 1.1519173063162575;
    Houghline_real_fast_2_B.HoughTransform_o2[313] = 1.1606439525762291;
    Houghline_real_fast_2_B.HoughTransform_o2[314] = 1.1693705988362009;
    Houghline_real_fast_2_B.HoughTransform_o2[315] = 1.1780972450961724;
    Houghline_real_fast_2_B.HoughTransform_o2[316] = 1.1868238913561442;
    Houghline_real_fast_2_B.HoughTransform_o2[317] = 1.1955505376161157;
    Houghline_real_fast_2_B.HoughTransform_o2[318] = 1.2042771838760873;
    Houghline_real_fast_2_B.HoughTransform_o2[319] = 1.2130038301360591;
    Houghline_real_fast_2_B.HoughTransform_o2[320] = 1.2217304763960306;
    Houghline_real_fast_2_B.HoughTransform_o2[321] = 1.2304571226560024;
    Houghline_real_fast_2_B.HoughTransform_o2[322] = 1.2391837689159739;
    Houghline_real_fast_2_B.HoughTransform_o2[323] = 1.2479104151759457;
    Houghline_real_fast_2_B.HoughTransform_o2[324] = 1.2566370614359172;
    Houghline_real_fast_2_B.HoughTransform_o2[325] = 1.265363707695889;
    Houghline_real_fast_2_B.HoughTransform_o2[326] = 1.2740903539558606;
    Houghline_real_fast_2_B.HoughTransform_o2[327] = 1.2828170002158321;
    Houghline_real_fast_2_B.HoughTransform_o2[328] = 1.2915436464758039;
    Houghline_real_fast_2_B.HoughTransform_o2[329] = 1.3002702927357754;
    Houghline_real_fast_2_B.HoughTransform_o2[330] = 1.3089969389957472;
    Houghline_real_fast_2_B.HoughTransform_o2[331] = 1.3177235852557188;
    Houghline_real_fast_2_B.HoughTransform_o2[332] = 1.3264502315156905;
    Houghline_real_fast_2_B.HoughTransform_o2[333] = 1.3351768777756621;
    Houghline_real_fast_2_B.HoughTransform_o2[334] = 1.3439035240356338;
    Houghline_real_fast_2_B.HoughTransform_o2[335] = 1.3526301702956054;
    Houghline_real_fast_2_B.HoughTransform_o2[336] = 1.3613568165555769;
    Houghline_real_fast_2_B.HoughTransform_o2[337] = 1.3700834628155487;
    Houghline_real_fast_2_B.HoughTransform_o2[338] = 1.3788101090755203;
    Houghline_real_fast_2_B.HoughTransform_o2[339] = 1.387536755335492;
    Houghline_real_fast_2_B.HoughTransform_o2[340] = 1.3962634015954636;
    Houghline_real_fast_2_B.HoughTransform_o2[341] = 1.4049900478554354;
    Houghline_real_fast_2_B.HoughTransform_o2[342] = 1.4137166941154069;
    Houghline_real_fast_2_B.HoughTransform_o2[343] = 1.4224433403753787;
    Houghline_real_fast_2_B.HoughTransform_o2[344] = 1.4311699866353502;
    Houghline_real_fast_2_B.HoughTransform_o2[345] = 1.4398966328953218;
    Houghline_real_fast_2_B.HoughTransform_o2[346] = 1.4486232791552935;
    Houghline_real_fast_2_B.HoughTransform_o2[347] = 1.4573499254152651;
    Houghline_real_fast_2_B.HoughTransform_o2[348] = 1.4660765716752369;
    Houghline_real_fast_2_B.HoughTransform_o2[349] = 1.4748032179352084;
    Houghline_real_fast_2_B.HoughTransform_o2[350] = 1.4835298641951802;
    Houghline_real_fast_2_B.HoughTransform_o2[351] = 1.4922565104551517;
    Houghline_real_fast_2_B.HoughTransform_o2[352] = 1.5009831567151235;
    Houghline_real_fast_2_B.HoughTransform_o2[353] = 1.509709802975095;
    Houghline_real_fast_2_B.HoughTransform_o2[354] = 1.5184364492350666;
    Houghline_real_fast_2_B.HoughTransform_o2[355] = 1.5271630954950384;
    Houghline_real_fast_2_B.HoughTransform_o2[356] = 1.53588974175501;
    Houghline_real_fast_2_B.HoughTransform_o2[357] = 1.5446163880149817;
    Houghline_real_fast_2_B.HoughTransform_o2[358] = 1.5533430342749532;
    Houghline_real_fast_2_B.HoughTransform_o2[359] = 1.562069680534925;
    Houghline_real_fast_2_B.HoughTransform_o3[0] = -670.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1] = -669.0;
    Houghline_real_fast_2_B.HoughTransform_o3[2] = -668.0;
    Houghline_real_fast_2_B.HoughTransform_o3[3] = -667.0;
    Houghline_real_fast_2_B.HoughTransform_o3[4] = -666.0;
    Houghline_real_fast_2_B.HoughTransform_o3[5] = -665.0;
    Houghline_real_fast_2_B.HoughTransform_o3[6] = -664.0;
    Houghline_real_fast_2_B.HoughTransform_o3[7] = -663.0;
    Houghline_real_fast_2_B.HoughTransform_o3[8] = -662.0;
    Houghline_real_fast_2_B.HoughTransform_o3[9] = -661.0;
    Houghline_real_fast_2_B.HoughTransform_o3[10] = -660.0;
    Houghline_real_fast_2_B.HoughTransform_o3[11] = -659.0;
    Houghline_real_fast_2_B.HoughTransform_o3[12] = -658.0;
    Houghline_real_fast_2_B.HoughTransform_o3[13] = -657.0;
    Houghline_real_fast_2_B.HoughTransform_o3[14] = -656.0;
    Houghline_real_fast_2_B.HoughTransform_o3[15] = -655.0;
    Houghline_real_fast_2_B.HoughTransform_o3[16] = -654.0;
    Houghline_real_fast_2_B.HoughTransform_o3[17] = -653.0;
    Houghline_real_fast_2_B.HoughTransform_o3[18] = -652.0;
    Houghline_real_fast_2_B.HoughTransform_o3[19] = -651.0;
    Houghline_real_fast_2_B.HoughTransform_o3[20] = -650.0;
    Houghline_real_fast_2_B.HoughTransform_o3[21] = -649.0;
    Houghline_real_fast_2_B.HoughTransform_o3[22] = -648.0;
    Houghline_real_fast_2_B.HoughTransform_o3[23] = -647.0;
    Houghline_real_fast_2_B.HoughTransform_o3[24] = -646.0;
    Houghline_real_fast_2_B.HoughTransform_o3[25] = -645.0;
    Houghline_real_fast_2_B.HoughTransform_o3[26] = -644.0;
    Houghline_real_fast_2_B.HoughTransform_o3[27] = -643.0;
    Houghline_real_fast_2_B.HoughTransform_o3[28] = -642.0;
    Houghline_real_fast_2_B.HoughTransform_o3[29] = -641.0;
    Houghline_real_fast_2_B.HoughTransform_o3[30] = -640.0;
    Houghline_real_fast_2_B.HoughTransform_o3[31] = -639.0;
    Houghline_real_fast_2_B.HoughTransform_o3[32] = -638.0;
    Houghline_real_fast_2_B.HoughTransform_o3[33] = -637.0;
    Houghline_real_fast_2_B.HoughTransform_o3[34] = -636.0;
    Houghline_real_fast_2_B.HoughTransform_o3[35] = -635.0;
    Houghline_real_fast_2_B.HoughTransform_o3[36] = -634.0;
    Houghline_real_fast_2_B.HoughTransform_o3[37] = -633.0;
    Houghline_real_fast_2_B.HoughTransform_o3[38] = -632.0;
    Houghline_real_fast_2_B.HoughTransform_o3[39] = -631.0;
    Houghline_real_fast_2_B.HoughTransform_o3[40] = -630.0;
    Houghline_real_fast_2_B.HoughTransform_o3[41] = -629.0;
    Houghline_real_fast_2_B.HoughTransform_o3[42] = -628.0;
    Houghline_real_fast_2_B.HoughTransform_o3[43] = -627.0;
    Houghline_real_fast_2_B.HoughTransform_o3[44] = -626.0;
    Houghline_real_fast_2_B.HoughTransform_o3[45] = -625.0;
    Houghline_real_fast_2_B.HoughTransform_o3[46] = -624.0;
    Houghline_real_fast_2_B.HoughTransform_o3[47] = -623.0;
    Houghline_real_fast_2_B.HoughTransform_o3[48] = -622.0;
    Houghline_real_fast_2_B.HoughTransform_o3[49] = -621.0;
    Houghline_real_fast_2_B.HoughTransform_o3[50] = -620.0;
    Houghline_real_fast_2_B.HoughTransform_o3[51] = -619.0;
    Houghline_real_fast_2_B.HoughTransform_o3[52] = -618.0;
    Houghline_real_fast_2_B.HoughTransform_o3[53] = -617.0;
    Houghline_real_fast_2_B.HoughTransform_o3[54] = -616.0;
    Houghline_real_fast_2_B.HoughTransform_o3[55] = -615.0;
    Houghline_real_fast_2_B.HoughTransform_o3[56] = -614.0;
    Houghline_real_fast_2_B.HoughTransform_o3[57] = -613.0;
    Houghline_real_fast_2_B.HoughTransform_o3[58] = -612.0;
    Houghline_real_fast_2_B.HoughTransform_o3[59] = -611.0;
    Houghline_real_fast_2_B.HoughTransform_o3[60] = -610.0;
    Houghline_real_fast_2_B.HoughTransform_o3[61] = -609.0;
    Houghline_real_fast_2_B.HoughTransform_o3[62] = -608.0;
    Houghline_real_fast_2_B.HoughTransform_o3[63] = -607.0;
    Houghline_real_fast_2_B.HoughTransform_o3[64] = -606.0;
    Houghline_real_fast_2_B.HoughTransform_o3[65] = -605.0;
    Houghline_real_fast_2_B.HoughTransform_o3[66] = -604.0;
    Houghline_real_fast_2_B.HoughTransform_o3[67] = -603.0;
    Houghline_real_fast_2_B.HoughTransform_o3[68] = -602.0;
    Houghline_real_fast_2_B.HoughTransform_o3[69] = -601.0;
    Houghline_real_fast_2_B.HoughTransform_o3[70] = -600.0;
    Houghline_real_fast_2_B.HoughTransform_o3[71] = -599.0;
    Houghline_real_fast_2_B.HoughTransform_o3[72] = -598.0;
    Houghline_real_fast_2_B.HoughTransform_o3[73] = -597.0;
    Houghline_real_fast_2_B.HoughTransform_o3[74] = -596.0;
    Houghline_real_fast_2_B.HoughTransform_o3[75] = -595.0;
    Houghline_real_fast_2_B.HoughTransform_o3[76] = -594.0;
    Houghline_real_fast_2_B.HoughTransform_o3[77] = -593.0;
    Houghline_real_fast_2_B.HoughTransform_o3[78] = -592.0;
    Houghline_real_fast_2_B.HoughTransform_o3[79] = -591.0;
    Houghline_real_fast_2_B.HoughTransform_o3[80] = -590.0;
    Houghline_real_fast_2_B.HoughTransform_o3[81] = -589.0;
    Houghline_real_fast_2_B.HoughTransform_o3[82] = -588.0;
    Houghline_real_fast_2_B.HoughTransform_o3[83] = -587.0;
    Houghline_real_fast_2_B.HoughTransform_o3[84] = -586.0;
    Houghline_real_fast_2_B.HoughTransform_o3[85] = -585.0;
    Houghline_real_fast_2_B.HoughTransform_o3[86] = -584.0;
    Houghline_real_fast_2_B.HoughTransform_o3[87] = -583.0;
    Houghline_real_fast_2_B.HoughTransform_o3[88] = -582.0;
    Houghline_real_fast_2_B.HoughTransform_o3[89] = -581.0;
    Houghline_real_fast_2_B.HoughTransform_o3[90] = -580.0;
    Houghline_real_fast_2_B.HoughTransform_o3[91] = -579.0;
    Houghline_real_fast_2_B.HoughTransform_o3[92] = -578.0;
    Houghline_real_fast_2_B.HoughTransform_o3[93] = -577.0;
    Houghline_real_fast_2_B.HoughTransform_o3[94] = -576.0;
    Houghline_real_fast_2_B.HoughTransform_o3[95] = -575.0;
    Houghline_real_fast_2_B.HoughTransform_o3[96] = -574.0;
    Houghline_real_fast_2_B.HoughTransform_o3[97] = -573.0;
    Houghline_real_fast_2_B.HoughTransform_o3[98] = -572.0;
    Houghline_real_fast_2_B.HoughTransform_o3[99] = -571.0;
    Houghline_real_fast_2_B.HoughTransform_o3[100] = -570.0;
    Houghline_real_fast_2_B.HoughTransform_o3[101] = -569.0;
    Houghline_real_fast_2_B.HoughTransform_o3[102] = -568.0;
    Houghline_real_fast_2_B.HoughTransform_o3[103] = -567.0;
    Houghline_real_fast_2_B.HoughTransform_o3[104] = -566.0;
    Houghline_real_fast_2_B.HoughTransform_o3[105] = -565.0;
    Houghline_real_fast_2_B.HoughTransform_o3[106] = -564.0;
    Houghline_real_fast_2_B.HoughTransform_o3[107] = -563.0;
    Houghline_real_fast_2_B.HoughTransform_o3[108] = -562.0;
    Houghline_real_fast_2_B.HoughTransform_o3[109] = -561.0;
    Houghline_real_fast_2_B.HoughTransform_o3[110] = -560.0;
    Houghline_real_fast_2_B.HoughTransform_o3[111] = -559.0;
    Houghline_real_fast_2_B.HoughTransform_o3[112] = -558.0;
    Houghline_real_fast_2_B.HoughTransform_o3[113] = -557.0;
    Houghline_real_fast_2_B.HoughTransform_o3[114] = -556.0;
    Houghline_real_fast_2_B.HoughTransform_o3[115] = -555.0;
    Houghline_real_fast_2_B.HoughTransform_o3[116] = -554.0;
    Houghline_real_fast_2_B.HoughTransform_o3[117] = -553.0;
    Houghline_real_fast_2_B.HoughTransform_o3[118] = -552.0;
    Houghline_real_fast_2_B.HoughTransform_o3[119] = -551.0;
    Houghline_real_fast_2_B.HoughTransform_o3[120] = -550.0;
    Houghline_real_fast_2_B.HoughTransform_o3[121] = -549.0;
    Houghline_real_fast_2_B.HoughTransform_o3[122] = -548.0;
    Houghline_real_fast_2_B.HoughTransform_o3[123] = -547.0;
    Houghline_real_fast_2_B.HoughTransform_o3[124] = -546.0;
    Houghline_real_fast_2_B.HoughTransform_o3[125] = -545.0;
    Houghline_real_fast_2_B.HoughTransform_o3[126] = -544.0;
    Houghline_real_fast_2_B.HoughTransform_o3[127] = -543.0;
    Houghline_real_fast_2_B.HoughTransform_o3[128] = -542.0;
    Houghline_real_fast_2_B.HoughTransform_o3[129] = -541.0;
    Houghline_real_fast_2_B.HoughTransform_o3[130] = -540.0;
    Houghline_real_fast_2_B.HoughTransform_o3[131] = -539.0;
    Houghline_real_fast_2_B.HoughTransform_o3[132] = -538.0;
    Houghline_real_fast_2_B.HoughTransform_o3[133] = -537.0;
    Houghline_real_fast_2_B.HoughTransform_o3[134] = -536.0;
    Houghline_real_fast_2_B.HoughTransform_o3[135] = -535.0;
    Houghline_real_fast_2_B.HoughTransform_o3[136] = -534.0;
    Houghline_real_fast_2_B.HoughTransform_o3[137] = -533.0;
    Houghline_real_fast_2_B.HoughTransform_o3[138] = -532.0;
    Houghline_real_fast_2_B.HoughTransform_o3[139] = -531.0;
    Houghline_real_fast_2_B.HoughTransform_o3[140] = -530.0;
    Houghline_real_fast_2_B.HoughTransform_o3[141] = -529.0;
    Houghline_real_fast_2_B.HoughTransform_o3[142] = -528.0;
    Houghline_real_fast_2_B.HoughTransform_o3[143] = -527.0;
    Houghline_real_fast_2_B.HoughTransform_o3[144] = -526.0;
    Houghline_real_fast_2_B.HoughTransform_o3[145] = -525.0;
    Houghline_real_fast_2_B.HoughTransform_o3[146] = -524.0;
    Houghline_real_fast_2_B.HoughTransform_o3[147] = -523.0;
    Houghline_real_fast_2_B.HoughTransform_o3[148] = -522.0;
    Houghline_real_fast_2_B.HoughTransform_o3[149] = -521.0;
    Houghline_real_fast_2_B.HoughTransform_o3[150] = -520.0;
    Houghline_real_fast_2_B.HoughTransform_o3[151] = -519.0;
    Houghline_real_fast_2_B.HoughTransform_o3[152] = -518.0;
    Houghline_real_fast_2_B.HoughTransform_o3[153] = -517.0;
    Houghline_real_fast_2_B.HoughTransform_o3[154] = -516.0;
    Houghline_real_fast_2_B.HoughTransform_o3[155] = -515.0;
    Houghline_real_fast_2_B.HoughTransform_o3[156] = -514.0;
    Houghline_real_fast_2_B.HoughTransform_o3[157] = -513.0;
    Houghline_real_fast_2_B.HoughTransform_o3[158] = -512.0;
    Houghline_real_fast_2_B.HoughTransform_o3[159] = -511.0;
    Houghline_real_fast_2_B.HoughTransform_o3[160] = -510.0;
    Houghline_real_fast_2_B.HoughTransform_o3[161] = -509.0;
    Houghline_real_fast_2_B.HoughTransform_o3[162] = -508.0;
    Houghline_real_fast_2_B.HoughTransform_o3[163] = -507.0;
    Houghline_real_fast_2_B.HoughTransform_o3[164] = -506.0;
    Houghline_real_fast_2_B.HoughTransform_o3[165] = -505.0;
    Houghline_real_fast_2_B.HoughTransform_o3[166] = -504.0;
    Houghline_real_fast_2_B.HoughTransform_o3[167] = -503.0;
    Houghline_real_fast_2_B.HoughTransform_o3[168] = -502.0;
    Houghline_real_fast_2_B.HoughTransform_o3[169] = -501.0;
    Houghline_real_fast_2_B.HoughTransform_o3[170] = -500.0;
    Houghline_real_fast_2_B.HoughTransform_o3[171] = -499.0;
    Houghline_real_fast_2_B.HoughTransform_o3[172] = -498.0;
    Houghline_real_fast_2_B.HoughTransform_o3[173] = -497.0;
    Houghline_real_fast_2_B.HoughTransform_o3[174] = -496.0;
    Houghline_real_fast_2_B.HoughTransform_o3[175] = -495.0;
    Houghline_real_fast_2_B.HoughTransform_o3[176] = -494.0;
    Houghline_real_fast_2_B.HoughTransform_o3[177] = -493.0;
    Houghline_real_fast_2_B.HoughTransform_o3[178] = -492.0;
    Houghline_real_fast_2_B.HoughTransform_o3[179] = -491.0;
    Houghline_real_fast_2_B.HoughTransform_o3[180] = -490.0;
    Houghline_real_fast_2_B.HoughTransform_o3[181] = -489.0;
    Houghline_real_fast_2_B.HoughTransform_o3[182] = -488.0;
    Houghline_real_fast_2_B.HoughTransform_o3[183] = -487.0;
    Houghline_real_fast_2_B.HoughTransform_o3[184] = -486.0;
    Houghline_real_fast_2_B.HoughTransform_o3[185] = -485.0;
    Houghline_real_fast_2_B.HoughTransform_o3[186] = -484.0;
    Houghline_real_fast_2_B.HoughTransform_o3[187] = -483.0;
    Houghline_real_fast_2_B.HoughTransform_o3[188] = -482.0;
    Houghline_real_fast_2_B.HoughTransform_o3[189] = -481.0;
    Houghline_real_fast_2_B.HoughTransform_o3[190] = -480.0;
    Houghline_real_fast_2_B.HoughTransform_o3[191] = -479.0;
    Houghline_real_fast_2_B.HoughTransform_o3[192] = -478.0;
    Houghline_real_fast_2_B.HoughTransform_o3[193] = -477.0;
    Houghline_real_fast_2_B.HoughTransform_o3[194] = -476.0;
    Houghline_real_fast_2_B.HoughTransform_o3[195] = -475.0;
    Houghline_real_fast_2_B.HoughTransform_o3[196] = -474.0;
    Houghline_real_fast_2_B.HoughTransform_o3[197] = -473.0;
    Houghline_real_fast_2_B.HoughTransform_o3[198] = -472.0;
    Houghline_real_fast_2_B.HoughTransform_o3[199] = -471.0;
    Houghline_real_fast_2_B.HoughTransform_o3[200] = -470.0;
    Houghline_real_fast_2_B.HoughTransform_o3[201] = -469.0;
    Houghline_real_fast_2_B.HoughTransform_o3[202] = -468.0;
    Houghline_real_fast_2_B.HoughTransform_o3[203] = -467.0;
    Houghline_real_fast_2_B.HoughTransform_o3[204] = -466.0;
    Houghline_real_fast_2_B.HoughTransform_o3[205] = -465.0;
    Houghline_real_fast_2_B.HoughTransform_o3[206] = -464.0;
    Houghline_real_fast_2_B.HoughTransform_o3[207] = -463.0;
    Houghline_real_fast_2_B.HoughTransform_o3[208] = -462.0;
    Houghline_real_fast_2_B.HoughTransform_o3[209] = -461.0;
    Houghline_real_fast_2_B.HoughTransform_o3[210] = -460.0;
    Houghline_real_fast_2_B.HoughTransform_o3[211] = -459.0;
    Houghline_real_fast_2_B.HoughTransform_o3[212] = -458.0;
    Houghline_real_fast_2_B.HoughTransform_o3[213] = -457.0;
    Houghline_real_fast_2_B.HoughTransform_o3[214] = -456.0;
    Houghline_real_fast_2_B.HoughTransform_o3[215] = -455.0;
    Houghline_real_fast_2_B.HoughTransform_o3[216] = -454.0;
    Houghline_real_fast_2_B.HoughTransform_o3[217] = -453.0;
    Houghline_real_fast_2_B.HoughTransform_o3[218] = -452.0;
    Houghline_real_fast_2_B.HoughTransform_o3[219] = -451.0;
    Houghline_real_fast_2_B.HoughTransform_o3[220] = -450.0;
    Houghline_real_fast_2_B.HoughTransform_o3[221] = -449.0;
    Houghline_real_fast_2_B.HoughTransform_o3[222] = -448.0;
    Houghline_real_fast_2_B.HoughTransform_o3[223] = -447.0;
    Houghline_real_fast_2_B.HoughTransform_o3[224] = -446.0;
    Houghline_real_fast_2_B.HoughTransform_o3[225] = -445.0;
    Houghline_real_fast_2_B.HoughTransform_o3[226] = -444.0;
    Houghline_real_fast_2_B.HoughTransform_o3[227] = -443.0;
    Houghline_real_fast_2_B.HoughTransform_o3[228] = -442.0;
    Houghline_real_fast_2_B.HoughTransform_o3[229] = -441.0;
    Houghline_real_fast_2_B.HoughTransform_o3[230] = -440.0;
    Houghline_real_fast_2_B.HoughTransform_o3[231] = -439.0;
    Houghline_real_fast_2_B.HoughTransform_o3[232] = -438.0;
    Houghline_real_fast_2_B.HoughTransform_o3[233] = -437.0;
    Houghline_real_fast_2_B.HoughTransform_o3[234] = -436.0;
    Houghline_real_fast_2_B.HoughTransform_o3[235] = -435.0;
    Houghline_real_fast_2_B.HoughTransform_o3[236] = -434.0;
    Houghline_real_fast_2_B.HoughTransform_o3[237] = -433.0;
    Houghline_real_fast_2_B.HoughTransform_o3[238] = -432.0;
    Houghline_real_fast_2_B.HoughTransform_o3[239] = -431.0;
    Houghline_real_fast_2_B.HoughTransform_o3[240] = -430.0;
    Houghline_real_fast_2_B.HoughTransform_o3[241] = -429.0;
    Houghline_real_fast_2_B.HoughTransform_o3[242] = -428.0;
    Houghline_real_fast_2_B.HoughTransform_o3[243] = -427.0;
    Houghline_real_fast_2_B.HoughTransform_o3[244] = -426.0;
    Houghline_real_fast_2_B.HoughTransform_o3[245] = -425.0;
    Houghline_real_fast_2_B.HoughTransform_o3[246] = -424.0;
    Houghline_real_fast_2_B.HoughTransform_o3[247] = -423.0;
    Houghline_real_fast_2_B.HoughTransform_o3[248] = -422.0;
    Houghline_real_fast_2_B.HoughTransform_o3[249] = -421.0;
    Houghline_real_fast_2_B.HoughTransform_o3[250] = -420.0;
    Houghline_real_fast_2_B.HoughTransform_o3[251] = -419.0;
    Houghline_real_fast_2_B.HoughTransform_o3[252] = -418.0;
    Houghline_real_fast_2_B.HoughTransform_o3[253] = -417.0;
    Houghline_real_fast_2_B.HoughTransform_o3[254] = -416.0;
    Houghline_real_fast_2_B.HoughTransform_o3[255] = -415.0;
    Houghline_real_fast_2_B.HoughTransform_o3[256] = -414.0;
    Houghline_real_fast_2_B.HoughTransform_o3[257] = -413.0;
    Houghline_real_fast_2_B.HoughTransform_o3[258] = -412.0;
    Houghline_real_fast_2_B.HoughTransform_o3[259] = -411.0;
    Houghline_real_fast_2_B.HoughTransform_o3[260] = -410.0;
    Houghline_real_fast_2_B.HoughTransform_o3[261] = -409.0;
    Houghline_real_fast_2_B.HoughTransform_o3[262] = -408.0;
    Houghline_real_fast_2_B.HoughTransform_o3[263] = -407.0;
    Houghline_real_fast_2_B.HoughTransform_o3[264] = -406.0;
    Houghline_real_fast_2_B.HoughTransform_o3[265] = -405.0;
    Houghline_real_fast_2_B.HoughTransform_o3[266] = -404.0;
    Houghline_real_fast_2_B.HoughTransform_o3[267] = -403.0;
    Houghline_real_fast_2_B.HoughTransform_o3[268] = -402.0;
    Houghline_real_fast_2_B.HoughTransform_o3[269] = -401.0;
    Houghline_real_fast_2_B.HoughTransform_o3[270] = -400.0;
    Houghline_real_fast_2_B.HoughTransform_o3[271] = -399.0;
    Houghline_real_fast_2_B.HoughTransform_o3[272] = -398.0;
    Houghline_real_fast_2_B.HoughTransform_o3[273] = -397.0;
    Houghline_real_fast_2_B.HoughTransform_o3[274] = -396.0;
    Houghline_real_fast_2_B.HoughTransform_o3[275] = -395.0;
    Houghline_real_fast_2_B.HoughTransform_o3[276] = -394.0;
    Houghline_real_fast_2_B.HoughTransform_o3[277] = -393.0;
    Houghline_real_fast_2_B.HoughTransform_o3[278] = -392.0;
    Houghline_real_fast_2_B.HoughTransform_o3[279] = -391.0;
    Houghline_real_fast_2_B.HoughTransform_o3[280] = -390.0;
    Houghline_real_fast_2_B.HoughTransform_o3[281] = -389.0;
    Houghline_real_fast_2_B.HoughTransform_o3[282] = -388.0;
    Houghline_real_fast_2_B.HoughTransform_o3[283] = -387.0;
    Houghline_real_fast_2_B.HoughTransform_o3[284] = -386.0;
    Houghline_real_fast_2_B.HoughTransform_o3[285] = -385.0;
    Houghline_real_fast_2_B.HoughTransform_o3[286] = -384.0;
    Houghline_real_fast_2_B.HoughTransform_o3[287] = -383.0;
    Houghline_real_fast_2_B.HoughTransform_o3[288] = -382.0;
    Houghline_real_fast_2_B.HoughTransform_o3[289] = -381.0;
    Houghline_real_fast_2_B.HoughTransform_o3[290] = -380.0;
    Houghline_real_fast_2_B.HoughTransform_o3[291] = -379.0;
    Houghline_real_fast_2_B.HoughTransform_o3[292] = -378.0;
    Houghline_real_fast_2_B.HoughTransform_o3[293] = -377.0;
    Houghline_real_fast_2_B.HoughTransform_o3[294] = -376.0;
    Houghline_real_fast_2_B.HoughTransform_o3[295] = -375.0;
    Houghline_real_fast_2_B.HoughTransform_o3[296] = -374.0;
    Houghline_real_fast_2_B.HoughTransform_o3[297] = -373.0;
    Houghline_real_fast_2_B.HoughTransform_o3[298] = -372.0;
    Houghline_real_fast_2_B.HoughTransform_o3[299] = -371.0;
    Houghline_real_fast_2_B.HoughTransform_o3[300] = -370.0;
    Houghline_real_fast_2_B.HoughTransform_o3[301] = -369.0;
    Houghline_real_fast_2_B.HoughTransform_o3[302] = -368.0;
    Houghline_real_fast_2_B.HoughTransform_o3[303] = -367.0;
    Houghline_real_fast_2_B.HoughTransform_o3[304] = -366.0;
    Houghline_real_fast_2_B.HoughTransform_o3[305] = -365.0;
    Houghline_real_fast_2_B.HoughTransform_o3[306] = -364.0;
    Houghline_real_fast_2_B.HoughTransform_o3[307] = -363.0;
    Houghline_real_fast_2_B.HoughTransform_o3[308] = -362.0;
    Houghline_real_fast_2_B.HoughTransform_o3[309] = -361.0;
    Houghline_real_fast_2_B.HoughTransform_o3[310] = -360.0;
    Houghline_real_fast_2_B.HoughTransform_o3[311] = -359.0;
    Houghline_real_fast_2_B.HoughTransform_o3[312] = -358.0;
    Houghline_real_fast_2_B.HoughTransform_o3[313] = -357.0;
    Houghline_real_fast_2_B.HoughTransform_o3[314] = -356.0;
    Houghline_real_fast_2_B.HoughTransform_o3[315] = -355.0;
    Houghline_real_fast_2_B.HoughTransform_o3[316] = -354.0;
    Houghline_real_fast_2_B.HoughTransform_o3[317] = -353.0;
    Houghline_real_fast_2_B.HoughTransform_o3[318] = -352.0;
    Houghline_real_fast_2_B.HoughTransform_o3[319] = -351.0;
    Houghline_real_fast_2_B.HoughTransform_o3[320] = -350.0;
    Houghline_real_fast_2_B.HoughTransform_o3[321] = -349.0;
    Houghline_real_fast_2_B.HoughTransform_o3[322] = -348.0;
    Houghline_real_fast_2_B.HoughTransform_o3[323] = -347.0;
    Houghline_real_fast_2_B.HoughTransform_o3[324] = -346.0;
    Houghline_real_fast_2_B.HoughTransform_o3[325] = -345.0;
    Houghline_real_fast_2_B.HoughTransform_o3[326] = -344.0;
    Houghline_real_fast_2_B.HoughTransform_o3[327] = -343.0;
    Houghline_real_fast_2_B.HoughTransform_o3[328] = -342.0;
    Houghline_real_fast_2_B.HoughTransform_o3[329] = -341.0;
    Houghline_real_fast_2_B.HoughTransform_o3[330] = -340.0;
    Houghline_real_fast_2_B.HoughTransform_o3[331] = -339.0;
    Houghline_real_fast_2_B.HoughTransform_o3[332] = -338.0;
    Houghline_real_fast_2_B.HoughTransform_o3[333] = -337.0;
    Houghline_real_fast_2_B.HoughTransform_o3[334] = -336.0;
    Houghline_real_fast_2_B.HoughTransform_o3[335] = -335.0;
    Houghline_real_fast_2_B.HoughTransform_o3[336] = -334.0;
    Houghline_real_fast_2_B.HoughTransform_o3[337] = -333.0;
    Houghline_real_fast_2_B.HoughTransform_o3[338] = -332.0;
    Houghline_real_fast_2_B.HoughTransform_o3[339] = -331.0;
    Houghline_real_fast_2_B.HoughTransform_o3[340] = -330.0;
    Houghline_real_fast_2_B.HoughTransform_o3[341] = -329.0;
    Houghline_real_fast_2_B.HoughTransform_o3[342] = -328.0;
    Houghline_real_fast_2_B.HoughTransform_o3[343] = -327.0;
    Houghline_real_fast_2_B.HoughTransform_o3[344] = -326.0;
    Houghline_real_fast_2_B.HoughTransform_o3[345] = -325.0;
    Houghline_real_fast_2_B.HoughTransform_o3[346] = -324.0;
    Houghline_real_fast_2_B.HoughTransform_o3[347] = -323.0;
    Houghline_real_fast_2_B.HoughTransform_o3[348] = -322.0;
    Houghline_real_fast_2_B.HoughTransform_o3[349] = -321.0;
    Houghline_real_fast_2_B.HoughTransform_o3[350] = -320.0;
    Houghline_real_fast_2_B.HoughTransform_o3[351] = -319.0;
    Houghline_real_fast_2_B.HoughTransform_o3[352] = -318.0;
    Houghline_real_fast_2_B.HoughTransform_o3[353] = -317.0;
    Houghline_real_fast_2_B.HoughTransform_o3[354] = -316.0;
    Houghline_real_fast_2_B.HoughTransform_o3[355] = -315.0;
    Houghline_real_fast_2_B.HoughTransform_o3[356] = -314.0;
    Houghline_real_fast_2_B.HoughTransform_o3[357] = -313.0;
    Houghline_real_fast_2_B.HoughTransform_o3[358] = -312.0;
    Houghline_real_fast_2_B.HoughTransform_o3[359] = -311.0;
    Houghline_real_fast_2_B.HoughTransform_o3[360] = -310.0;
    Houghline_real_fast_2_B.HoughTransform_o3[361] = -309.0;
    Houghline_real_fast_2_B.HoughTransform_o3[362] = -308.0;
    Houghline_real_fast_2_B.HoughTransform_o3[363] = -307.0;
    Houghline_real_fast_2_B.HoughTransform_o3[364] = -306.0;
    Houghline_real_fast_2_B.HoughTransform_o3[365] = -305.0;
    Houghline_real_fast_2_B.HoughTransform_o3[366] = -304.0;
    Houghline_real_fast_2_B.HoughTransform_o3[367] = -303.0;
    Houghline_real_fast_2_B.HoughTransform_o3[368] = -302.0;
    Houghline_real_fast_2_B.HoughTransform_o3[369] = -301.0;
    Houghline_real_fast_2_B.HoughTransform_o3[370] = -300.0;
    Houghline_real_fast_2_B.HoughTransform_o3[371] = -299.0;
    Houghline_real_fast_2_B.HoughTransform_o3[372] = -298.0;
    Houghline_real_fast_2_B.HoughTransform_o3[373] = -297.0;
    Houghline_real_fast_2_B.HoughTransform_o3[374] = -296.0;
    Houghline_real_fast_2_B.HoughTransform_o3[375] = -295.0;
    Houghline_real_fast_2_B.HoughTransform_o3[376] = -294.0;
    Houghline_real_fast_2_B.HoughTransform_o3[377] = -293.0;
    Houghline_real_fast_2_B.HoughTransform_o3[378] = -292.0;
    Houghline_real_fast_2_B.HoughTransform_o3[379] = -291.0;
    Houghline_real_fast_2_B.HoughTransform_o3[380] = -290.0;
    Houghline_real_fast_2_B.HoughTransform_o3[381] = -289.0;
    Houghline_real_fast_2_B.HoughTransform_o3[382] = -288.0;
    Houghline_real_fast_2_B.HoughTransform_o3[383] = -287.0;
    Houghline_real_fast_2_B.HoughTransform_o3[384] = -286.0;
    Houghline_real_fast_2_B.HoughTransform_o3[385] = -285.0;
    Houghline_real_fast_2_B.HoughTransform_o3[386] = -284.0;
    Houghline_real_fast_2_B.HoughTransform_o3[387] = -283.0;
    Houghline_real_fast_2_B.HoughTransform_o3[388] = -282.0;
    Houghline_real_fast_2_B.HoughTransform_o3[389] = -281.0;
    Houghline_real_fast_2_B.HoughTransform_o3[390] = -280.0;
    Houghline_real_fast_2_B.HoughTransform_o3[391] = -279.0;
    Houghline_real_fast_2_B.HoughTransform_o3[392] = -278.0;
    Houghline_real_fast_2_B.HoughTransform_o3[393] = -277.0;
    Houghline_real_fast_2_B.HoughTransform_o3[394] = -276.0;
    Houghline_real_fast_2_B.HoughTransform_o3[395] = -275.0;
    Houghline_real_fast_2_B.HoughTransform_o3[396] = -274.0;
    Houghline_real_fast_2_B.HoughTransform_o3[397] = -273.0;
    Houghline_real_fast_2_B.HoughTransform_o3[398] = -272.0;
    Houghline_real_fast_2_B.HoughTransform_o3[399] = -271.0;
    Houghline_real_fast_2_B.HoughTransform_o3[400] = -270.0;
    Houghline_real_fast_2_B.HoughTransform_o3[401] = -269.0;
    Houghline_real_fast_2_B.HoughTransform_o3[402] = -268.0;
    Houghline_real_fast_2_B.HoughTransform_o3[403] = -267.0;
    Houghline_real_fast_2_B.HoughTransform_o3[404] = -266.0;
    Houghline_real_fast_2_B.HoughTransform_o3[405] = -265.0;
    Houghline_real_fast_2_B.HoughTransform_o3[406] = -264.0;
    Houghline_real_fast_2_B.HoughTransform_o3[407] = -263.0;
    Houghline_real_fast_2_B.HoughTransform_o3[408] = -262.0;
    Houghline_real_fast_2_B.HoughTransform_o3[409] = -261.0;
    Houghline_real_fast_2_B.HoughTransform_o3[410] = -260.0;
    Houghline_real_fast_2_B.HoughTransform_o3[411] = -259.0;
    Houghline_real_fast_2_B.HoughTransform_o3[412] = -258.0;
    Houghline_real_fast_2_B.HoughTransform_o3[413] = -257.0;
    Houghline_real_fast_2_B.HoughTransform_o3[414] = -256.0;
    Houghline_real_fast_2_B.HoughTransform_o3[415] = -255.0;
    Houghline_real_fast_2_B.HoughTransform_o3[416] = -254.0;
    Houghline_real_fast_2_B.HoughTransform_o3[417] = -253.0;
    Houghline_real_fast_2_B.HoughTransform_o3[418] = -252.0;
    Houghline_real_fast_2_B.HoughTransform_o3[419] = -251.0;
    Houghline_real_fast_2_B.HoughTransform_o3[420] = -250.0;
    Houghline_real_fast_2_B.HoughTransform_o3[421] = -249.0;
    Houghline_real_fast_2_B.HoughTransform_o3[422] = -248.0;
    Houghline_real_fast_2_B.HoughTransform_o3[423] = -247.0;
    Houghline_real_fast_2_B.HoughTransform_o3[424] = -246.0;
    Houghline_real_fast_2_B.HoughTransform_o3[425] = -245.0;
    Houghline_real_fast_2_B.HoughTransform_o3[426] = -244.0;
    Houghline_real_fast_2_B.HoughTransform_o3[427] = -243.0;
    Houghline_real_fast_2_B.HoughTransform_o3[428] = -242.0;
    Houghline_real_fast_2_B.HoughTransform_o3[429] = -241.0;
    Houghline_real_fast_2_B.HoughTransform_o3[430] = -240.0;
    Houghline_real_fast_2_B.HoughTransform_o3[431] = -239.0;
    Houghline_real_fast_2_B.HoughTransform_o3[432] = -238.0;
    Houghline_real_fast_2_B.HoughTransform_o3[433] = -237.0;
    Houghline_real_fast_2_B.HoughTransform_o3[434] = -236.0;
    Houghline_real_fast_2_B.HoughTransform_o3[435] = -235.0;
    Houghline_real_fast_2_B.HoughTransform_o3[436] = -234.0;
    Houghline_real_fast_2_B.HoughTransform_o3[437] = -233.0;
    Houghline_real_fast_2_B.HoughTransform_o3[438] = -232.0;
    Houghline_real_fast_2_B.HoughTransform_o3[439] = -231.0;
    Houghline_real_fast_2_B.HoughTransform_o3[440] = -230.0;
    Houghline_real_fast_2_B.HoughTransform_o3[441] = -229.0;
    Houghline_real_fast_2_B.HoughTransform_o3[442] = -228.0;
    Houghline_real_fast_2_B.HoughTransform_o3[443] = -227.0;
    Houghline_real_fast_2_B.HoughTransform_o3[444] = -226.0;
    Houghline_real_fast_2_B.HoughTransform_o3[445] = -225.0;
    Houghline_real_fast_2_B.HoughTransform_o3[446] = -224.0;
    Houghline_real_fast_2_B.HoughTransform_o3[447] = -223.0;
    Houghline_real_fast_2_B.HoughTransform_o3[448] = -222.0;
    Houghline_real_fast_2_B.HoughTransform_o3[449] = -221.0;
    Houghline_real_fast_2_B.HoughTransform_o3[450] = -220.0;
    Houghline_real_fast_2_B.HoughTransform_o3[451] = -219.0;
    Houghline_real_fast_2_B.HoughTransform_o3[452] = -218.0;
    Houghline_real_fast_2_B.HoughTransform_o3[453] = -217.0;
    Houghline_real_fast_2_B.HoughTransform_o3[454] = -216.0;
    Houghline_real_fast_2_B.HoughTransform_o3[455] = -215.0;
    Houghline_real_fast_2_B.HoughTransform_o3[456] = -214.0;
    Houghline_real_fast_2_B.HoughTransform_o3[457] = -213.0;
    Houghline_real_fast_2_B.HoughTransform_o3[458] = -212.0;
    Houghline_real_fast_2_B.HoughTransform_o3[459] = -211.0;
    Houghline_real_fast_2_B.HoughTransform_o3[460] = -210.0;
    Houghline_real_fast_2_B.HoughTransform_o3[461] = -209.0;
    Houghline_real_fast_2_B.HoughTransform_o3[462] = -208.0;
    Houghline_real_fast_2_B.HoughTransform_o3[463] = -207.0;
    Houghline_real_fast_2_B.HoughTransform_o3[464] = -206.0;
    Houghline_real_fast_2_B.HoughTransform_o3[465] = -205.0;
    Houghline_real_fast_2_B.HoughTransform_o3[466] = -204.0;
    Houghline_real_fast_2_B.HoughTransform_o3[467] = -203.0;
    Houghline_real_fast_2_B.HoughTransform_o3[468] = -202.0;
    Houghline_real_fast_2_B.HoughTransform_o3[469] = -201.0;
    Houghline_real_fast_2_B.HoughTransform_o3[470] = -200.0;
    Houghline_real_fast_2_B.HoughTransform_o3[471] = -199.0;
    Houghline_real_fast_2_B.HoughTransform_o3[472] = -198.0;
    Houghline_real_fast_2_B.HoughTransform_o3[473] = -197.0;
    Houghline_real_fast_2_B.HoughTransform_o3[474] = -196.0;
    Houghline_real_fast_2_B.HoughTransform_o3[475] = -195.0;
    Houghline_real_fast_2_B.HoughTransform_o3[476] = -194.0;
    Houghline_real_fast_2_B.HoughTransform_o3[477] = -193.0;
    Houghline_real_fast_2_B.HoughTransform_o3[478] = -192.0;
    Houghline_real_fast_2_B.HoughTransform_o3[479] = -191.0;
    Houghline_real_fast_2_B.HoughTransform_o3[480] = -190.0;
    Houghline_real_fast_2_B.HoughTransform_o3[481] = -189.0;
    Houghline_real_fast_2_B.HoughTransform_o3[482] = -188.0;
    Houghline_real_fast_2_B.HoughTransform_o3[483] = -187.0;
    Houghline_real_fast_2_B.HoughTransform_o3[484] = -186.0;
    Houghline_real_fast_2_B.HoughTransform_o3[485] = -185.0;
    Houghline_real_fast_2_B.HoughTransform_o3[486] = -184.0;
    Houghline_real_fast_2_B.HoughTransform_o3[487] = -183.0;
    Houghline_real_fast_2_B.HoughTransform_o3[488] = -182.0;
    Houghline_real_fast_2_B.HoughTransform_o3[489] = -181.0;
    Houghline_real_fast_2_B.HoughTransform_o3[490] = -180.0;
    Houghline_real_fast_2_B.HoughTransform_o3[491] = -179.0;
    Houghline_real_fast_2_B.HoughTransform_o3[492] = -178.0;
    Houghline_real_fast_2_B.HoughTransform_o3[493] = -177.0;
    Houghline_real_fast_2_B.HoughTransform_o3[494] = -176.0;
    Houghline_real_fast_2_B.HoughTransform_o3[495] = -175.0;
    Houghline_real_fast_2_B.HoughTransform_o3[496] = -174.0;
    Houghline_real_fast_2_B.HoughTransform_o3[497] = -173.0;
    Houghline_real_fast_2_B.HoughTransform_o3[498] = -172.0;
    Houghline_real_fast_2_B.HoughTransform_o3[499] = -171.0;
    Houghline_real_fast_2_B.HoughTransform_o3[500] = -170.0;
    Houghline_real_fast_2_B.HoughTransform_o3[501] = -169.0;
    Houghline_real_fast_2_B.HoughTransform_o3[502] = -168.0;
    Houghline_real_fast_2_B.HoughTransform_o3[503] = -167.0;
    Houghline_real_fast_2_B.HoughTransform_o3[504] = -166.0;
    Houghline_real_fast_2_B.HoughTransform_o3[505] = -165.0;
    Houghline_real_fast_2_B.HoughTransform_o3[506] = -164.0;
    Houghline_real_fast_2_B.HoughTransform_o3[507] = -163.0;
    Houghline_real_fast_2_B.HoughTransform_o3[508] = -162.0;
    Houghline_real_fast_2_B.HoughTransform_o3[509] = -161.0;
    Houghline_real_fast_2_B.HoughTransform_o3[510] = -160.0;
    Houghline_real_fast_2_B.HoughTransform_o3[511] = -159.0;
    Houghline_real_fast_2_B.HoughTransform_o3[512] = -158.0;
    Houghline_real_fast_2_B.HoughTransform_o3[513] = -157.0;
    Houghline_real_fast_2_B.HoughTransform_o3[514] = -156.0;
    Houghline_real_fast_2_B.HoughTransform_o3[515] = -155.0;
    Houghline_real_fast_2_B.HoughTransform_o3[516] = -154.0;
    Houghline_real_fast_2_B.HoughTransform_o3[517] = -153.0;
    Houghline_real_fast_2_B.HoughTransform_o3[518] = -152.0;
    Houghline_real_fast_2_B.HoughTransform_o3[519] = -151.0;
    Houghline_real_fast_2_B.HoughTransform_o3[520] = -150.0;
    Houghline_real_fast_2_B.HoughTransform_o3[521] = -149.0;
    Houghline_real_fast_2_B.HoughTransform_o3[522] = -148.0;
    Houghline_real_fast_2_B.HoughTransform_o3[523] = -147.0;
    Houghline_real_fast_2_B.HoughTransform_o3[524] = -146.0;
    Houghline_real_fast_2_B.HoughTransform_o3[525] = -145.0;
    Houghline_real_fast_2_B.HoughTransform_o3[526] = -144.0;
    Houghline_real_fast_2_B.HoughTransform_o3[527] = -143.0;
    Houghline_real_fast_2_B.HoughTransform_o3[528] = -142.0;
    Houghline_real_fast_2_B.HoughTransform_o3[529] = -141.0;
    Houghline_real_fast_2_B.HoughTransform_o3[530] = -140.0;
    Houghline_real_fast_2_B.HoughTransform_o3[531] = -139.0;
    Houghline_real_fast_2_B.HoughTransform_o3[532] = -138.0;
    Houghline_real_fast_2_B.HoughTransform_o3[533] = -137.0;
    Houghline_real_fast_2_B.HoughTransform_o3[534] = -136.0;
    Houghline_real_fast_2_B.HoughTransform_o3[535] = -135.0;
    Houghline_real_fast_2_B.HoughTransform_o3[536] = -134.0;
    Houghline_real_fast_2_B.HoughTransform_o3[537] = -133.0;
    Houghline_real_fast_2_B.HoughTransform_o3[538] = -132.0;
    Houghline_real_fast_2_B.HoughTransform_o3[539] = -131.0;
    Houghline_real_fast_2_B.HoughTransform_o3[540] = -130.0;
    Houghline_real_fast_2_B.HoughTransform_o3[541] = -129.0;
    Houghline_real_fast_2_B.HoughTransform_o3[542] = -128.0;
    Houghline_real_fast_2_B.HoughTransform_o3[543] = -127.0;
    Houghline_real_fast_2_B.HoughTransform_o3[544] = -126.0;
    Houghline_real_fast_2_B.HoughTransform_o3[545] = -125.0;
    Houghline_real_fast_2_B.HoughTransform_o3[546] = -124.0;
    Houghline_real_fast_2_B.HoughTransform_o3[547] = -123.0;
    Houghline_real_fast_2_B.HoughTransform_o3[548] = -122.0;
    Houghline_real_fast_2_B.HoughTransform_o3[549] = -121.0;
    Houghline_real_fast_2_B.HoughTransform_o3[550] = -120.0;
    Houghline_real_fast_2_B.HoughTransform_o3[551] = -119.0;
    Houghline_real_fast_2_B.HoughTransform_o3[552] = -118.0;
    Houghline_real_fast_2_B.HoughTransform_o3[553] = -117.0;
    Houghline_real_fast_2_B.HoughTransform_o3[554] = -116.0;
    Houghline_real_fast_2_B.HoughTransform_o3[555] = -115.0;
    Houghline_real_fast_2_B.HoughTransform_o3[556] = -114.0;
    Houghline_real_fast_2_B.HoughTransform_o3[557] = -113.0;
    Houghline_real_fast_2_B.HoughTransform_o3[558] = -112.0;
    Houghline_real_fast_2_B.HoughTransform_o3[559] = -111.0;
    Houghline_real_fast_2_B.HoughTransform_o3[560] = -110.0;
    Houghline_real_fast_2_B.HoughTransform_o3[561] = -109.0;
    Houghline_real_fast_2_B.HoughTransform_o3[562] = -108.0;
    Houghline_real_fast_2_B.HoughTransform_o3[563] = -107.0;
    Houghline_real_fast_2_B.HoughTransform_o3[564] = -106.0;
    Houghline_real_fast_2_B.HoughTransform_o3[565] = -105.0;
    Houghline_real_fast_2_B.HoughTransform_o3[566] = -104.0;
    Houghline_real_fast_2_B.HoughTransform_o3[567] = -103.0;
    Houghline_real_fast_2_B.HoughTransform_o3[568] = -102.0;
    Houghline_real_fast_2_B.HoughTransform_o3[569] = -101.0;
    Houghline_real_fast_2_B.HoughTransform_o3[570] = -100.0;
    Houghline_real_fast_2_B.HoughTransform_o3[571] = -99.0;
    Houghline_real_fast_2_B.HoughTransform_o3[572] = -98.0;
    Houghline_real_fast_2_B.HoughTransform_o3[573] = -97.0;
    Houghline_real_fast_2_B.HoughTransform_o3[574] = -96.0;
    Houghline_real_fast_2_B.HoughTransform_o3[575] = -95.0;
    Houghline_real_fast_2_B.HoughTransform_o3[576] = -94.0;
    Houghline_real_fast_2_B.HoughTransform_o3[577] = -93.0;
    Houghline_real_fast_2_B.HoughTransform_o3[578] = -92.0;
    Houghline_real_fast_2_B.HoughTransform_o3[579] = -91.0;
    Houghline_real_fast_2_B.HoughTransform_o3[580] = -90.0;
    Houghline_real_fast_2_B.HoughTransform_o3[581] = -89.0;
    Houghline_real_fast_2_B.HoughTransform_o3[582] = -88.0;
    Houghline_real_fast_2_B.HoughTransform_o3[583] = -87.0;
    Houghline_real_fast_2_B.HoughTransform_o3[584] = -86.0;
    Houghline_real_fast_2_B.HoughTransform_o3[585] = -85.0;
    Houghline_real_fast_2_B.HoughTransform_o3[586] = -84.0;
    Houghline_real_fast_2_B.HoughTransform_o3[587] = -83.0;
    Houghline_real_fast_2_B.HoughTransform_o3[588] = -82.0;
    Houghline_real_fast_2_B.HoughTransform_o3[589] = -81.0;
    Houghline_real_fast_2_B.HoughTransform_o3[590] = -80.0;
    Houghline_real_fast_2_B.HoughTransform_o3[591] = -79.0;
    Houghline_real_fast_2_B.HoughTransform_o3[592] = -78.0;
    Houghline_real_fast_2_B.HoughTransform_o3[593] = -77.0;
    Houghline_real_fast_2_B.HoughTransform_o3[594] = -76.0;
    Houghline_real_fast_2_B.HoughTransform_o3[595] = -75.0;
    Houghline_real_fast_2_B.HoughTransform_o3[596] = -74.0;
    Houghline_real_fast_2_B.HoughTransform_o3[597] = -73.0;
    Houghline_real_fast_2_B.HoughTransform_o3[598] = -72.0;
    Houghline_real_fast_2_B.HoughTransform_o3[599] = -71.0;
    Houghline_real_fast_2_B.HoughTransform_o3[600] = -70.0;
    Houghline_real_fast_2_B.HoughTransform_o3[601] = -69.0;
    Houghline_real_fast_2_B.HoughTransform_o3[602] = -68.0;
    Houghline_real_fast_2_B.HoughTransform_o3[603] = -67.0;
    Houghline_real_fast_2_B.HoughTransform_o3[604] = -66.0;
    Houghline_real_fast_2_B.HoughTransform_o3[605] = -65.0;
    Houghline_real_fast_2_B.HoughTransform_o3[606] = -64.0;
    Houghline_real_fast_2_B.HoughTransform_o3[607] = -63.0;
    Houghline_real_fast_2_B.HoughTransform_o3[608] = -62.0;
    Houghline_real_fast_2_B.HoughTransform_o3[609] = -61.0;
    Houghline_real_fast_2_B.HoughTransform_o3[610] = -60.0;
    Houghline_real_fast_2_B.HoughTransform_o3[611] = -59.0;
    Houghline_real_fast_2_B.HoughTransform_o3[612] = -58.0;
    Houghline_real_fast_2_B.HoughTransform_o3[613] = -57.0;
    Houghline_real_fast_2_B.HoughTransform_o3[614] = -56.0;
    Houghline_real_fast_2_B.HoughTransform_o3[615] = -55.0;
    Houghline_real_fast_2_B.HoughTransform_o3[616] = -54.0;
    Houghline_real_fast_2_B.HoughTransform_o3[617] = -53.0;
    Houghline_real_fast_2_B.HoughTransform_o3[618] = -52.0;
    Houghline_real_fast_2_B.HoughTransform_o3[619] = -51.0;
    Houghline_real_fast_2_B.HoughTransform_o3[620] = -50.0;
    Houghline_real_fast_2_B.HoughTransform_o3[621] = -49.0;
    Houghline_real_fast_2_B.HoughTransform_o3[622] = -48.0;
    Houghline_real_fast_2_B.HoughTransform_o3[623] = -47.0;
    Houghline_real_fast_2_B.HoughTransform_o3[624] = -46.0;
    Houghline_real_fast_2_B.HoughTransform_o3[625] = -45.0;
    Houghline_real_fast_2_B.HoughTransform_o3[626] = -44.0;
    Houghline_real_fast_2_B.HoughTransform_o3[627] = -43.0;
    Houghline_real_fast_2_B.HoughTransform_o3[628] = -42.0;
    Houghline_real_fast_2_B.HoughTransform_o3[629] = -41.0;
    Houghline_real_fast_2_B.HoughTransform_o3[630] = -40.0;
    Houghline_real_fast_2_B.HoughTransform_o3[631] = -39.0;
    Houghline_real_fast_2_B.HoughTransform_o3[632] = -38.0;
    Houghline_real_fast_2_B.HoughTransform_o3[633] = -37.0;
    Houghline_real_fast_2_B.HoughTransform_o3[634] = -36.0;
    Houghline_real_fast_2_B.HoughTransform_o3[635] = -35.0;
    Houghline_real_fast_2_B.HoughTransform_o3[636] = -34.0;
    Houghline_real_fast_2_B.HoughTransform_o3[637] = -33.0;
    Houghline_real_fast_2_B.HoughTransform_o3[638] = -32.0;
    Houghline_real_fast_2_B.HoughTransform_o3[639] = -31.0;
    Houghline_real_fast_2_B.HoughTransform_o3[640] = -30.0;
    Houghline_real_fast_2_B.HoughTransform_o3[641] = -29.0;
    Houghline_real_fast_2_B.HoughTransform_o3[642] = -28.0;
    Houghline_real_fast_2_B.HoughTransform_o3[643] = -27.0;
    Houghline_real_fast_2_B.HoughTransform_o3[644] = -26.0;
    Houghline_real_fast_2_B.HoughTransform_o3[645] = -25.0;
    Houghline_real_fast_2_B.HoughTransform_o3[646] = -24.0;
    Houghline_real_fast_2_B.HoughTransform_o3[647] = -23.0;
    Houghline_real_fast_2_B.HoughTransform_o3[648] = -22.0;
    Houghline_real_fast_2_B.HoughTransform_o3[649] = -21.0;
    Houghline_real_fast_2_B.HoughTransform_o3[650] = -20.0;
    Houghline_real_fast_2_B.HoughTransform_o3[651] = -19.0;
    Houghline_real_fast_2_B.HoughTransform_o3[652] = -18.0;
    Houghline_real_fast_2_B.HoughTransform_o3[653] = -17.0;
    Houghline_real_fast_2_B.HoughTransform_o3[654] = -16.0;
    Houghline_real_fast_2_B.HoughTransform_o3[655] = -15.0;
    Houghline_real_fast_2_B.HoughTransform_o3[656] = -14.0;
    Houghline_real_fast_2_B.HoughTransform_o3[657] = -13.0;
    Houghline_real_fast_2_B.HoughTransform_o3[658] = -12.0;
    Houghline_real_fast_2_B.HoughTransform_o3[659] = -11.0;
    Houghline_real_fast_2_B.HoughTransform_o3[660] = -10.0;
    Houghline_real_fast_2_B.HoughTransform_o3[661] = -9.0;
    Houghline_real_fast_2_B.HoughTransform_o3[662] = -8.0;
    Houghline_real_fast_2_B.HoughTransform_o3[663] = -7.0;
    Houghline_real_fast_2_B.HoughTransform_o3[664] = -6.0;
    Houghline_real_fast_2_B.HoughTransform_o3[665] = -5.0;
    Houghline_real_fast_2_B.HoughTransform_o3[666] = -4.0;
    Houghline_real_fast_2_B.HoughTransform_o3[667] = -3.0;
    Houghline_real_fast_2_B.HoughTransform_o3[668] = -2.0;
    Houghline_real_fast_2_B.HoughTransform_o3[669] = -1.0;
    Houghline_real_fast_2_B.HoughTransform_o3[670] = 0.0;
    Houghline_real_fast_2_B.HoughTransform_o3[671] = 1.0;
    Houghline_real_fast_2_B.HoughTransform_o3[672] = 2.0;
    Houghline_real_fast_2_B.HoughTransform_o3[673] = 3.0;
    Houghline_real_fast_2_B.HoughTransform_o3[674] = 4.0;
    Houghline_real_fast_2_B.HoughTransform_o3[675] = 5.0;
    Houghline_real_fast_2_B.HoughTransform_o3[676] = 6.0;
    Houghline_real_fast_2_B.HoughTransform_o3[677] = 7.0;
    Houghline_real_fast_2_B.HoughTransform_o3[678] = 8.0;
    Houghline_real_fast_2_B.HoughTransform_o3[679] = 9.0;
    Houghline_real_fast_2_B.HoughTransform_o3[680] = 10.0;
    Houghline_real_fast_2_B.HoughTransform_o3[681] = 11.0;
    Houghline_real_fast_2_B.HoughTransform_o3[682] = 12.0;
    Houghline_real_fast_2_B.HoughTransform_o3[683] = 13.0;
    Houghline_real_fast_2_B.HoughTransform_o3[684] = 14.0;
    Houghline_real_fast_2_B.HoughTransform_o3[685] = 15.0;
    Houghline_real_fast_2_B.HoughTransform_o3[686] = 16.0;
    Houghline_real_fast_2_B.HoughTransform_o3[687] = 17.0;
    Houghline_real_fast_2_B.HoughTransform_o3[688] = 18.0;
    Houghline_real_fast_2_B.HoughTransform_o3[689] = 19.0;
    Houghline_real_fast_2_B.HoughTransform_o3[690] = 20.0;
    Houghline_real_fast_2_B.HoughTransform_o3[691] = 21.0;
    Houghline_real_fast_2_B.HoughTransform_o3[692] = 22.0;
    Houghline_real_fast_2_B.HoughTransform_o3[693] = 23.0;
    Houghline_real_fast_2_B.HoughTransform_o3[694] = 24.0;
    Houghline_real_fast_2_B.HoughTransform_o3[695] = 25.0;
    Houghline_real_fast_2_B.HoughTransform_o3[696] = 26.0;
    Houghline_real_fast_2_B.HoughTransform_o3[697] = 27.0;
    Houghline_real_fast_2_B.HoughTransform_o3[698] = 28.0;
    Houghline_real_fast_2_B.HoughTransform_o3[699] = 29.0;
    Houghline_real_fast_2_B.HoughTransform_o3[700] = 30.0;
    Houghline_real_fast_2_B.HoughTransform_o3[701] = 31.0;
    Houghline_real_fast_2_B.HoughTransform_o3[702] = 32.0;
    Houghline_real_fast_2_B.HoughTransform_o3[703] = 33.0;
    Houghline_real_fast_2_B.HoughTransform_o3[704] = 34.0;
    Houghline_real_fast_2_B.HoughTransform_o3[705] = 35.0;
    Houghline_real_fast_2_B.HoughTransform_o3[706] = 36.0;
    Houghline_real_fast_2_B.HoughTransform_o3[707] = 37.0;
    Houghline_real_fast_2_B.HoughTransform_o3[708] = 38.0;
    Houghline_real_fast_2_B.HoughTransform_o3[709] = 39.0;
    Houghline_real_fast_2_B.HoughTransform_o3[710] = 40.0;
    Houghline_real_fast_2_B.HoughTransform_o3[711] = 41.0;
    Houghline_real_fast_2_B.HoughTransform_o3[712] = 42.0;
    Houghline_real_fast_2_B.HoughTransform_o3[713] = 43.0;
    Houghline_real_fast_2_B.HoughTransform_o3[714] = 44.0;
    Houghline_real_fast_2_B.HoughTransform_o3[715] = 45.0;
    Houghline_real_fast_2_B.HoughTransform_o3[716] = 46.0;
    Houghline_real_fast_2_B.HoughTransform_o3[717] = 47.0;
    Houghline_real_fast_2_B.HoughTransform_o3[718] = 48.0;
    Houghline_real_fast_2_B.HoughTransform_o3[719] = 49.0;
    Houghline_real_fast_2_B.HoughTransform_o3[720] = 50.0;
    Houghline_real_fast_2_B.HoughTransform_o3[721] = 51.0;
    Houghline_real_fast_2_B.HoughTransform_o3[722] = 52.0;
    Houghline_real_fast_2_B.HoughTransform_o3[723] = 53.0;
    Houghline_real_fast_2_B.HoughTransform_o3[724] = 54.0;
    Houghline_real_fast_2_B.HoughTransform_o3[725] = 55.0;
    Houghline_real_fast_2_B.HoughTransform_o3[726] = 56.0;
    Houghline_real_fast_2_B.HoughTransform_o3[727] = 57.0;
    Houghline_real_fast_2_B.HoughTransform_o3[728] = 58.0;
    Houghline_real_fast_2_B.HoughTransform_o3[729] = 59.0;
    Houghline_real_fast_2_B.HoughTransform_o3[730] = 60.0;
    Houghline_real_fast_2_B.HoughTransform_o3[731] = 61.0;
    Houghline_real_fast_2_B.HoughTransform_o3[732] = 62.0;
    Houghline_real_fast_2_B.HoughTransform_o3[733] = 63.0;
    Houghline_real_fast_2_B.HoughTransform_o3[734] = 64.0;
    Houghline_real_fast_2_B.HoughTransform_o3[735] = 65.0;
    Houghline_real_fast_2_B.HoughTransform_o3[736] = 66.0;
    Houghline_real_fast_2_B.HoughTransform_o3[737] = 67.0;
    Houghline_real_fast_2_B.HoughTransform_o3[738] = 68.0;
    Houghline_real_fast_2_B.HoughTransform_o3[739] = 69.0;
    Houghline_real_fast_2_B.HoughTransform_o3[740] = 70.0;
    Houghline_real_fast_2_B.HoughTransform_o3[741] = 71.0;
    Houghline_real_fast_2_B.HoughTransform_o3[742] = 72.0;
    Houghline_real_fast_2_B.HoughTransform_o3[743] = 73.0;
    Houghline_real_fast_2_B.HoughTransform_o3[744] = 74.0;
    Houghline_real_fast_2_B.HoughTransform_o3[745] = 75.0;
    Houghline_real_fast_2_B.HoughTransform_o3[746] = 76.0;
    Houghline_real_fast_2_B.HoughTransform_o3[747] = 77.0;
    Houghline_real_fast_2_B.HoughTransform_o3[748] = 78.0;
    Houghline_real_fast_2_B.HoughTransform_o3[749] = 79.0;
    Houghline_real_fast_2_B.HoughTransform_o3[750] = 80.0;
    Houghline_real_fast_2_B.HoughTransform_o3[751] = 81.0;
    Houghline_real_fast_2_B.HoughTransform_o3[752] = 82.0;
    Houghline_real_fast_2_B.HoughTransform_o3[753] = 83.0;
    Houghline_real_fast_2_B.HoughTransform_o3[754] = 84.0;
    Houghline_real_fast_2_B.HoughTransform_o3[755] = 85.0;
    Houghline_real_fast_2_B.HoughTransform_o3[756] = 86.0;
    Houghline_real_fast_2_B.HoughTransform_o3[757] = 87.0;
    Houghline_real_fast_2_B.HoughTransform_o3[758] = 88.0;
    Houghline_real_fast_2_B.HoughTransform_o3[759] = 89.0;
    Houghline_real_fast_2_B.HoughTransform_o3[760] = 90.0;
    Houghline_real_fast_2_B.HoughTransform_o3[761] = 91.0;
    Houghline_real_fast_2_B.HoughTransform_o3[762] = 92.0;
    Houghline_real_fast_2_B.HoughTransform_o3[763] = 93.0;
    Houghline_real_fast_2_B.HoughTransform_o3[764] = 94.0;
    Houghline_real_fast_2_B.HoughTransform_o3[765] = 95.0;
    Houghline_real_fast_2_B.HoughTransform_o3[766] = 96.0;
    Houghline_real_fast_2_B.HoughTransform_o3[767] = 97.0;
    Houghline_real_fast_2_B.HoughTransform_o3[768] = 98.0;
    Houghline_real_fast_2_B.HoughTransform_o3[769] = 99.0;
    Houghline_real_fast_2_B.HoughTransform_o3[770] = 100.0;
    Houghline_real_fast_2_B.HoughTransform_o3[771] = 101.0;
    Houghline_real_fast_2_B.HoughTransform_o3[772] = 102.0;
    Houghline_real_fast_2_B.HoughTransform_o3[773] = 103.0;
    Houghline_real_fast_2_B.HoughTransform_o3[774] = 104.0;
    Houghline_real_fast_2_B.HoughTransform_o3[775] = 105.0;
    Houghline_real_fast_2_B.HoughTransform_o3[776] = 106.0;
    Houghline_real_fast_2_B.HoughTransform_o3[777] = 107.0;
    Houghline_real_fast_2_B.HoughTransform_o3[778] = 108.0;
    Houghline_real_fast_2_B.HoughTransform_o3[779] = 109.0;
    Houghline_real_fast_2_B.HoughTransform_o3[780] = 110.0;
    Houghline_real_fast_2_B.HoughTransform_o3[781] = 111.0;
    Houghline_real_fast_2_B.HoughTransform_o3[782] = 112.0;
    Houghline_real_fast_2_B.HoughTransform_o3[783] = 113.0;
    Houghline_real_fast_2_B.HoughTransform_o3[784] = 114.0;
    Houghline_real_fast_2_B.HoughTransform_o3[785] = 115.0;
    Houghline_real_fast_2_B.HoughTransform_o3[786] = 116.0;
    Houghline_real_fast_2_B.HoughTransform_o3[787] = 117.0;
    Houghline_real_fast_2_B.HoughTransform_o3[788] = 118.0;
    Houghline_real_fast_2_B.HoughTransform_o3[789] = 119.0;
    Houghline_real_fast_2_B.HoughTransform_o3[790] = 120.0;
    Houghline_real_fast_2_B.HoughTransform_o3[791] = 121.0;
    Houghline_real_fast_2_B.HoughTransform_o3[792] = 122.0;
    Houghline_real_fast_2_B.HoughTransform_o3[793] = 123.0;
    Houghline_real_fast_2_B.HoughTransform_o3[794] = 124.0;
    Houghline_real_fast_2_B.HoughTransform_o3[795] = 125.0;
    Houghline_real_fast_2_B.HoughTransform_o3[796] = 126.0;
    Houghline_real_fast_2_B.HoughTransform_o3[797] = 127.0;
    Houghline_real_fast_2_B.HoughTransform_o3[798] = 128.0;
    Houghline_real_fast_2_B.HoughTransform_o3[799] = 129.0;
    Houghline_real_fast_2_B.HoughTransform_o3[800] = 130.0;
    Houghline_real_fast_2_B.HoughTransform_o3[801] = 131.0;
    Houghline_real_fast_2_B.HoughTransform_o3[802] = 132.0;
    Houghline_real_fast_2_B.HoughTransform_o3[803] = 133.0;
    Houghline_real_fast_2_B.HoughTransform_o3[804] = 134.0;
    Houghline_real_fast_2_B.HoughTransform_o3[805] = 135.0;
    Houghline_real_fast_2_B.HoughTransform_o3[806] = 136.0;
    Houghline_real_fast_2_B.HoughTransform_o3[807] = 137.0;
    Houghline_real_fast_2_B.HoughTransform_o3[808] = 138.0;
    Houghline_real_fast_2_B.HoughTransform_o3[809] = 139.0;
    Houghline_real_fast_2_B.HoughTransform_o3[810] = 140.0;
    Houghline_real_fast_2_B.HoughTransform_o3[811] = 141.0;
    Houghline_real_fast_2_B.HoughTransform_o3[812] = 142.0;
    Houghline_real_fast_2_B.HoughTransform_o3[813] = 143.0;
    Houghline_real_fast_2_B.HoughTransform_o3[814] = 144.0;
    Houghline_real_fast_2_B.HoughTransform_o3[815] = 145.0;
    Houghline_real_fast_2_B.HoughTransform_o3[816] = 146.0;
    Houghline_real_fast_2_B.HoughTransform_o3[817] = 147.0;
    Houghline_real_fast_2_B.HoughTransform_o3[818] = 148.0;
    Houghline_real_fast_2_B.HoughTransform_o3[819] = 149.0;
    Houghline_real_fast_2_B.HoughTransform_o3[820] = 150.0;
    Houghline_real_fast_2_B.HoughTransform_o3[821] = 151.0;
    Houghline_real_fast_2_B.HoughTransform_o3[822] = 152.0;
    Houghline_real_fast_2_B.HoughTransform_o3[823] = 153.0;
    Houghline_real_fast_2_B.HoughTransform_o3[824] = 154.0;
    Houghline_real_fast_2_B.HoughTransform_o3[825] = 155.0;
    Houghline_real_fast_2_B.HoughTransform_o3[826] = 156.0;
    Houghline_real_fast_2_B.HoughTransform_o3[827] = 157.0;
    Houghline_real_fast_2_B.HoughTransform_o3[828] = 158.0;
    Houghline_real_fast_2_B.HoughTransform_o3[829] = 159.0;
    Houghline_real_fast_2_B.HoughTransform_o3[830] = 160.0;
    Houghline_real_fast_2_B.HoughTransform_o3[831] = 161.0;
    Houghline_real_fast_2_B.HoughTransform_o3[832] = 162.0;
    Houghline_real_fast_2_B.HoughTransform_o3[833] = 163.0;
    Houghline_real_fast_2_B.HoughTransform_o3[834] = 164.0;
    Houghline_real_fast_2_B.HoughTransform_o3[835] = 165.0;
    Houghline_real_fast_2_B.HoughTransform_o3[836] = 166.0;
    Houghline_real_fast_2_B.HoughTransform_o3[837] = 167.0;
    Houghline_real_fast_2_B.HoughTransform_o3[838] = 168.0;
    Houghline_real_fast_2_B.HoughTransform_o3[839] = 169.0;
    Houghline_real_fast_2_B.HoughTransform_o3[840] = 170.0;
    Houghline_real_fast_2_B.HoughTransform_o3[841] = 171.0;
    Houghline_real_fast_2_B.HoughTransform_o3[842] = 172.0;
    Houghline_real_fast_2_B.HoughTransform_o3[843] = 173.0;
    Houghline_real_fast_2_B.HoughTransform_o3[844] = 174.0;
    Houghline_real_fast_2_B.HoughTransform_o3[845] = 175.0;
    Houghline_real_fast_2_B.HoughTransform_o3[846] = 176.0;
    Houghline_real_fast_2_B.HoughTransform_o3[847] = 177.0;
    Houghline_real_fast_2_B.HoughTransform_o3[848] = 178.0;
    Houghline_real_fast_2_B.HoughTransform_o3[849] = 179.0;
    Houghline_real_fast_2_B.HoughTransform_o3[850] = 180.0;
    Houghline_real_fast_2_B.HoughTransform_o3[851] = 181.0;
    Houghline_real_fast_2_B.HoughTransform_o3[852] = 182.0;
    Houghline_real_fast_2_B.HoughTransform_o3[853] = 183.0;
    Houghline_real_fast_2_B.HoughTransform_o3[854] = 184.0;
    Houghline_real_fast_2_B.HoughTransform_o3[855] = 185.0;
    Houghline_real_fast_2_B.HoughTransform_o3[856] = 186.0;
    Houghline_real_fast_2_B.HoughTransform_o3[857] = 187.0;
    Houghline_real_fast_2_B.HoughTransform_o3[858] = 188.0;
    Houghline_real_fast_2_B.HoughTransform_o3[859] = 189.0;
    Houghline_real_fast_2_B.HoughTransform_o3[860] = 190.0;
    Houghline_real_fast_2_B.HoughTransform_o3[861] = 191.0;
    Houghline_real_fast_2_B.HoughTransform_o3[862] = 192.0;
    Houghline_real_fast_2_B.HoughTransform_o3[863] = 193.0;
    Houghline_real_fast_2_B.HoughTransform_o3[864] = 194.0;
    Houghline_real_fast_2_B.HoughTransform_o3[865] = 195.0;
    Houghline_real_fast_2_B.HoughTransform_o3[866] = 196.0;
    Houghline_real_fast_2_B.HoughTransform_o3[867] = 197.0;
    Houghline_real_fast_2_B.HoughTransform_o3[868] = 198.0;
    Houghline_real_fast_2_B.HoughTransform_o3[869] = 199.0;
    Houghline_real_fast_2_B.HoughTransform_o3[870] = 200.0;
    Houghline_real_fast_2_B.HoughTransform_o3[871] = 201.0;
    Houghline_real_fast_2_B.HoughTransform_o3[872] = 202.0;
    Houghline_real_fast_2_B.HoughTransform_o3[873] = 203.0;
    Houghline_real_fast_2_B.HoughTransform_o3[874] = 204.0;
    Houghline_real_fast_2_B.HoughTransform_o3[875] = 205.0;
    Houghline_real_fast_2_B.HoughTransform_o3[876] = 206.0;
    Houghline_real_fast_2_B.HoughTransform_o3[877] = 207.0;
    Houghline_real_fast_2_B.HoughTransform_o3[878] = 208.0;
    Houghline_real_fast_2_B.HoughTransform_o3[879] = 209.0;
    Houghline_real_fast_2_B.HoughTransform_o3[880] = 210.0;
    Houghline_real_fast_2_B.HoughTransform_o3[881] = 211.0;
    Houghline_real_fast_2_B.HoughTransform_o3[882] = 212.0;
    Houghline_real_fast_2_B.HoughTransform_o3[883] = 213.0;
    Houghline_real_fast_2_B.HoughTransform_o3[884] = 214.0;
    Houghline_real_fast_2_B.HoughTransform_o3[885] = 215.0;
    Houghline_real_fast_2_B.HoughTransform_o3[886] = 216.0;
    Houghline_real_fast_2_B.HoughTransform_o3[887] = 217.0;
    Houghline_real_fast_2_B.HoughTransform_o3[888] = 218.0;
    Houghline_real_fast_2_B.HoughTransform_o3[889] = 219.0;
    Houghline_real_fast_2_B.HoughTransform_o3[890] = 220.0;
    Houghline_real_fast_2_B.HoughTransform_o3[891] = 221.0;
    Houghline_real_fast_2_B.HoughTransform_o3[892] = 222.0;
    Houghline_real_fast_2_B.HoughTransform_o3[893] = 223.0;
    Houghline_real_fast_2_B.HoughTransform_o3[894] = 224.0;
    Houghline_real_fast_2_B.HoughTransform_o3[895] = 225.0;
    Houghline_real_fast_2_B.HoughTransform_o3[896] = 226.0;
    Houghline_real_fast_2_B.HoughTransform_o3[897] = 227.0;
    Houghline_real_fast_2_B.HoughTransform_o3[898] = 228.0;
    Houghline_real_fast_2_B.HoughTransform_o3[899] = 229.0;
    Houghline_real_fast_2_B.HoughTransform_o3[900] = 230.0;
    Houghline_real_fast_2_B.HoughTransform_o3[901] = 231.0;
    Houghline_real_fast_2_B.HoughTransform_o3[902] = 232.0;
    Houghline_real_fast_2_B.HoughTransform_o3[903] = 233.0;
    Houghline_real_fast_2_B.HoughTransform_o3[904] = 234.0;
    Houghline_real_fast_2_B.HoughTransform_o3[905] = 235.0;
    Houghline_real_fast_2_B.HoughTransform_o3[906] = 236.0;
    Houghline_real_fast_2_B.HoughTransform_o3[907] = 237.0;
    Houghline_real_fast_2_B.HoughTransform_o3[908] = 238.0;
    Houghline_real_fast_2_B.HoughTransform_o3[909] = 239.0;
    Houghline_real_fast_2_B.HoughTransform_o3[910] = 240.0;
    Houghline_real_fast_2_B.HoughTransform_o3[911] = 241.0;
    Houghline_real_fast_2_B.HoughTransform_o3[912] = 242.0;
    Houghline_real_fast_2_B.HoughTransform_o3[913] = 243.0;
    Houghline_real_fast_2_B.HoughTransform_o3[914] = 244.0;
    Houghline_real_fast_2_B.HoughTransform_o3[915] = 245.0;
    Houghline_real_fast_2_B.HoughTransform_o3[916] = 246.0;
    Houghline_real_fast_2_B.HoughTransform_o3[917] = 247.0;
    Houghline_real_fast_2_B.HoughTransform_o3[918] = 248.0;
    Houghline_real_fast_2_B.HoughTransform_o3[919] = 249.0;
    Houghline_real_fast_2_B.HoughTransform_o3[920] = 250.0;
    Houghline_real_fast_2_B.HoughTransform_o3[921] = 251.0;
    Houghline_real_fast_2_B.HoughTransform_o3[922] = 252.0;
    Houghline_real_fast_2_B.HoughTransform_o3[923] = 253.0;
    Houghline_real_fast_2_B.HoughTransform_o3[924] = 254.0;
    Houghline_real_fast_2_B.HoughTransform_o3[925] = 255.0;
    Houghline_real_fast_2_B.HoughTransform_o3[926] = 256.0;
    Houghline_real_fast_2_B.HoughTransform_o3[927] = 257.0;
    Houghline_real_fast_2_B.HoughTransform_o3[928] = 258.0;
    Houghline_real_fast_2_B.HoughTransform_o3[929] = 259.0;
    Houghline_real_fast_2_B.HoughTransform_o3[930] = 260.0;
    Houghline_real_fast_2_B.HoughTransform_o3[931] = 261.0;
    Houghline_real_fast_2_B.HoughTransform_o3[932] = 262.0;
    Houghline_real_fast_2_B.HoughTransform_o3[933] = 263.0;
    Houghline_real_fast_2_B.HoughTransform_o3[934] = 264.0;
    Houghline_real_fast_2_B.HoughTransform_o3[935] = 265.0;
    Houghline_real_fast_2_B.HoughTransform_o3[936] = 266.0;
    Houghline_real_fast_2_B.HoughTransform_o3[937] = 267.0;
    Houghline_real_fast_2_B.HoughTransform_o3[938] = 268.0;
    Houghline_real_fast_2_B.HoughTransform_o3[939] = 269.0;
    Houghline_real_fast_2_B.HoughTransform_o3[940] = 270.0;
    Houghline_real_fast_2_B.HoughTransform_o3[941] = 271.0;
    Houghline_real_fast_2_B.HoughTransform_o3[942] = 272.0;
    Houghline_real_fast_2_B.HoughTransform_o3[943] = 273.0;
    Houghline_real_fast_2_B.HoughTransform_o3[944] = 274.0;
    Houghline_real_fast_2_B.HoughTransform_o3[945] = 275.0;
    Houghline_real_fast_2_B.HoughTransform_o3[946] = 276.0;
    Houghline_real_fast_2_B.HoughTransform_o3[947] = 277.0;
    Houghline_real_fast_2_B.HoughTransform_o3[948] = 278.0;
    Houghline_real_fast_2_B.HoughTransform_o3[949] = 279.0;
    Houghline_real_fast_2_B.HoughTransform_o3[950] = 280.0;
    Houghline_real_fast_2_B.HoughTransform_o3[951] = 281.0;
    Houghline_real_fast_2_B.HoughTransform_o3[952] = 282.0;
    Houghline_real_fast_2_B.HoughTransform_o3[953] = 283.0;
    Houghline_real_fast_2_B.HoughTransform_o3[954] = 284.0;
    Houghline_real_fast_2_B.HoughTransform_o3[955] = 285.0;
    Houghline_real_fast_2_B.HoughTransform_o3[956] = 286.0;
    Houghline_real_fast_2_B.HoughTransform_o3[957] = 287.0;
    Houghline_real_fast_2_B.HoughTransform_o3[958] = 288.0;
    Houghline_real_fast_2_B.HoughTransform_o3[959] = 289.0;
    Houghline_real_fast_2_B.HoughTransform_o3[960] = 290.0;
    Houghline_real_fast_2_B.HoughTransform_o3[961] = 291.0;
    Houghline_real_fast_2_B.HoughTransform_o3[962] = 292.0;
    Houghline_real_fast_2_B.HoughTransform_o3[963] = 293.0;
    Houghline_real_fast_2_B.HoughTransform_o3[964] = 294.0;
    Houghline_real_fast_2_B.HoughTransform_o3[965] = 295.0;
    Houghline_real_fast_2_B.HoughTransform_o3[966] = 296.0;
    Houghline_real_fast_2_B.HoughTransform_o3[967] = 297.0;
    Houghline_real_fast_2_B.HoughTransform_o3[968] = 298.0;
    Houghline_real_fast_2_B.HoughTransform_o3[969] = 299.0;
    Houghline_real_fast_2_B.HoughTransform_o3[970] = 300.0;
    Houghline_real_fast_2_B.HoughTransform_o3[971] = 301.0;
    Houghline_real_fast_2_B.HoughTransform_o3[972] = 302.0;
    Houghline_real_fast_2_B.HoughTransform_o3[973] = 303.0;
    Houghline_real_fast_2_B.HoughTransform_o3[974] = 304.0;
    Houghline_real_fast_2_B.HoughTransform_o3[975] = 305.0;
    Houghline_real_fast_2_B.HoughTransform_o3[976] = 306.0;
    Houghline_real_fast_2_B.HoughTransform_o3[977] = 307.0;
    Houghline_real_fast_2_B.HoughTransform_o3[978] = 308.0;
    Houghline_real_fast_2_B.HoughTransform_o3[979] = 309.0;
    Houghline_real_fast_2_B.HoughTransform_o3[980] = 310.0;
    Houghline_real_fast_2_B.HoughTransform_o3[981] = 311.0;
    Houghline_real_fast_2_B.HoughTransform_o3[982] = 312.0;
    Houghline_real_fast_2_B.HoughTransform_o3[983] = 313.0;
    Houghline_real_fast_2_B.HoughTransform_o3[984] = 314.0;
    Houghline_real_fast_2_B.HoughTransform_o3[985] = 315.0;
    Houghline_real_fast_2_B.HoughTransform_o3[986] = 316.0;
    Houghline_real_fast_2_B.HoughTransform_o3[987] = 317.0;
    Houghline_real_fast_2_B.HoughTransform_o3[988] = 318.0;
    Houghline_real_fast_2_B.HoughTransform_o3[989] = 319.0;
    Houghline_real_fast_2_B.HoughTransform_o3[990] = 320.0;
    Houghline_real_fast_2_B.HoughTransform_o3[991] = 321.0;
    Houghline_real_fast_2_B.HoughTransform_o3[992] = 322.0;
    Houghline_real_fast_2_B.HoughTransform_o3[993] = 323.0;
    Houghline_real_fast_2_B.HoughTransform_o3[994] = 324.0;
    Houghline_real_fast_2_B.HoughTransform_o3[995] = 325.0;
    Houghline_real_fast_2_B.HoughTransform_o3[996] = 326.0;
    Houghline_real_fast_2_B.HoughTransform_o3[997] = 327.0;
    Houghline_real_fast_2_B.HoughTransform_o3[998] = 328.0;
    Houghline_real_fast_2_B.HoughTransform_o3[999] = 329.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1000] = 330.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1001] = 331.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1002] = 332.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1003] = 333.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1004] = 334.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1005] = 335.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1006] = 336.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1007] = 337.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1008] = 338.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1009] = 339.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1010] = 340.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1011] = 341.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1012] = 342.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1013] = 343.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1014] = 344.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1015] = 345.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1016] = 346.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1017] = 347.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1018] = 348.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1019] = 349.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1020] = 350.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1021] = 351.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1022] = 352.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1023] = 353.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1024] = 354.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1025] = 355.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1026] = 356.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1027] = 357.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1028] = 358.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1029] = 359.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1030] = 360.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1031] = 361.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1032] = 362.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1033] = 363.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1034] = 364.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1035] = 365.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1036] = 366.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1037] = 367.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1038] = 368.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1039] = 369.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1040] = 370.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1041] = 371.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1042] = 372.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1043] = 373.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1044] = 374.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1045] = 375.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1046] = 376.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1047] = 377.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1048] = 378.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1049] = 379.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1050] = 380.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1051] = 381.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1052] = 382.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1053] = 383.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1054] = 384.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1055] = 385.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1056] = 386.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1057] = 387.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1058] = 388.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1059] = 389.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1060] = 390.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1061] = 391.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1062] = 392.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1063] = 393.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1064] = 394.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1065] = 395.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1066] = 396.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1067] = 397.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1068] = 398.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1069] = 399.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1070] = 400.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1071] = 401.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1072] = 402.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1073] = 403.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1074] = 404.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1075] = 405.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1076] = 406.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1077] = 407.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1078] = 408.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1079] = 409.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1080] = 410.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1081] = 411.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1082] = 412.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1083] = 413.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1084] = 414.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1085] = 415.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1086] = 416.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1087] = 417.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1088] = 418.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1089] = 419.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1090] = 420.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1091] = 421.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1092] = 422.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1093] = 423.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1094] = 424.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1095] = 425.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1096] = 426.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1097] = 427.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1098] = 428.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1099] = 429.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1100] = 430.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1101] = 431.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1102] = 432.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1103] = 433.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1104] = 434.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1105] = 435.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1106] = 436.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1107] = 437.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1108] = 438.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1109] = 439.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1110] = 440.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1111] = 441.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1112] = 442.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1113] = 443.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1114] = 444.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1115] = 445.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1116] = 446.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1117] = 447.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1118] = 448.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1119] = 449.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1120] = 450.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1121] = 451.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1122] = 452.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1123] = 453.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1124] = 454.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1125] = 455.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1126] = 456.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1127] = 457.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1128] = 458.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1129] = 459.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1130] = 460.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1131] = 461.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1132] = 462.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1133] = 463.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1134] = 464.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1135] = 465.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1136] = 466.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1137] = 467.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1138] = 468.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1139] = 469.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1140] = 470.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1141] = 471.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1142] = 472.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1143] = 473.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1144] = 474.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1145] = 475.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1146] = 476.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1147] = 477.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1148] = 478.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1149] = 479.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1150] = 480.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1151] = 481.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1152] = 482.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1153] = 483.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1154] = 484.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1155] = 485.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1156] = 486.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1157] = 487.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1158] = 488.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1159] = 489.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1160] = 490.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1161] = 491.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1162] = 492.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1163] = 493.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1164] = 494.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1165] = 495.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1166] = 496.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1167] = 497.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1168] = 498.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1169] = 499.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1170] = 500.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1171] = 501.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1172] = 502.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1173] = 503.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1174] = 504.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1175] = 505.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1176] = 506.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1177] = 507.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1178] = 508.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1179] = 509.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1180] = 510.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1181] = 511.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1182] = 512.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1183] = 513.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1184] = 514.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1185] = 515.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1186] = 516.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1187] = 517.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1188] = 518.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1189] = 519.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1190] = 520.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1191] = 521.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1192] = 522.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1193] = 523.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1194] = 524.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1195] = 525.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1196] = 526.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1197] = 527.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1198] = 528.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1199] = 529.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1200] = 530.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1201] = 531.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1202] = 532.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1203] = 533.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1204] = 534.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1205] = 535.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1206] = 536.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1207] = 537.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1208] = 538.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1209] = 539.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1210] = 540.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1211] = 541.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1212] = 542.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1213] = 543.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1214] = 544.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1215] = 545.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1216] = 546.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1217] = 547.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1218] = 548.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1219] = 549.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1220] = 550.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1221] = 551.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1222] = 552.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1223] = 553.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1224] = 554.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1225] = 555.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1226] = 556.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1227] = 557.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1228] = 558.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1229] = 559.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1230] = 560.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1231] = 561.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1232] = 562.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1233] = 563.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1234] = 564.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1235] = 565.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1236] = 566.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1237] = 567.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1238] = 568.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1239] = 569.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1240] = 570.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1241] = 571.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1242] = 572.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1243] = 573.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1244] = 574.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1245] = 575.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1246] = 576.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1247] = 577.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1248] = 578.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1249] = 579.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1250] = 580.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1251] = 581.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1252] = 582.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1253] = 583.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1254] = 584.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1255] = 585.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1256] = 586.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1257] = 587.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1258] = 588.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1259] = 589.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1260] = 590.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1261] = 591.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1262] = 592.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1263] = 593.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1264] = 594.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1265] = 595.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1266] = 596.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1267] = 597.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1268] = 598.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1269] = 599.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1270] = 600.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1271] = 601.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1272] = 602.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1273] = 603.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1274] = 604.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1275] = 605.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1276] = 606.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1277] = 607.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1278] = 608.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1279] = 609.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1280] = 610.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1281] = 611.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1282] = 612.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1283] = 613.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1284] = 614.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1285] = 615.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1286] = 616.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1287] = 617.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1288] = 618.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1289] = 619.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1290] = 620.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1291] = 621.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1292] = 622.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1293] = 623.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1294] = 624.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1295] = 625.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1296] = 626.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1297] = 627.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1298] = 628.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1299] = 629.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1300] = 630.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1301] = 631.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1302] = 632.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1303] = 633.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1304] = 634.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1305] = 635.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1306] = 636.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1307] = 637.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1308] = 638.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1309] = 639.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1310] = 640.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1311] = 641.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1312] = 642.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1313] = 643.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1314] = 644.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1315] = 645.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1316] = 646.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1317] = 647.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1318] = 648.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1319] = 649.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1320] = 650.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1321] = 651.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1322] = 652.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1323] = 653.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1324] = 654.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1325] = 655.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1326] = 656.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1327] = 657.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1328] = 658.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1329] = 659.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1330] = 660.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1331] = 661.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1332] = 662.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1333] = 663.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1334] = 664.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1335] = 665.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1336] = 666.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1337] = 667.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1338] = 668.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1339] = 669.0;
    Houghline_real_fast_2_B.HoughTransform_o3[1340] = 670.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Houghline_real_fast_2_DW, 0,
                sizeof(DW_Houghline_real_fast_2_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Houghline_real_fast_2_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Houghline_real_fast_2_M),
    Houghline_real_fast_2_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Houghline_real_fast_2_M)));

  {
    char_T *sErr;
    int32_T previous;
    int32_T step;
    boolean_T isValid;
    int32_T idxOut;
    int32_T curNumNonZ;
    int32_T n;
    int32_T m;

    /* Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    sErr = GetErrorBuffer(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib
                          [0U]);
    CreateHostLibrary("frommmfile.dll",
                      &Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&Houghline_real_fast_2_DW.FromMultimediaFile_AudioInfo[0U],
                    0U, 0U, 0.0, 0, 0, 0, 0, 0);
    createVideoInfo(&Houghline_real_fast_2_DW.FromMultimediaFile_VideoInfo[0U],
                    1U, 25.0, 25.0, "RGB ", 1, 3, 1280, 720, 1U, 1, 1, 0);
    if (*sErr == 0) {
      LibCreate_FromMMFile(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib
                           [0U], 0, (void *)
                           "C:\\MatlabCode\\amas_2016\\Fast and Robust Lane Detection using OpenCV (1).mp4",
                           1,
                           "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\multimedia\\bin\\win64\\reader\\,directshowplugin.dll,kakaduplugin.dll,mediafoundationplugin.dll,mjpegaviplugin.dll",
                           "",
                           &Houghline_real_fast_2_DW.FromMultimediaFile_AudioInfo
                           [0U],
                           &Houghline_real_fast_2_DW.FromMultimediaFile_VideoInfo
                           [0U], 0U, 1U, 1U, 0U, 0U, 1U);
    }

    if (*sErr == 0) {
      LibStart(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Houghline_real_fast_2_M, sErr);
        rtmSetStopRequested(Houghline_real_fast_2_M, 1);
      }
    }

    /* End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

    /* Start for S-Function (svipmorphop): '<S4>/reduce noise 1' */
    previous = 0;
    step = 0;
    curNumNonZ = 0;
    isValid = true;
    idxOut = 0;
    n = 0;
    while (n < 1) {
      m = 0;
      while (m < 1) {
        if (curNumNonZ == 0) {
          curNumNonZ = 1;
        } else if (curNumNonZ == 1) {
          step = idxOut - previous;
          curNumNonZ = 2;
        } else if (idxOut - previous == step) {
          curNumNonZ++;
        } else {
          isValid = false;
          m = 1;
          n = 1;
        }

        previous = idxOut;
        idxOut++;
        m++;
      }

      idxOut += 230;
      n++;
    }

    if (isValid && (curNumNonZ >= 4)) {
      if (step == 231) {
        Houghline_real_fast_2_DW.reducenoise1_STREL_DW = 2;
      } else {
        Houghline_real_fast_2_DW.reducenoise1_STREL_DW = (step == 1);
      }
    } else {
      Houghline_real_fast_2_DW.reducenoise1_STREL_DW = 0;
    }

    curNumNonZ = 0;
    n = 0;
    while (n < 1) {
      m = 0;
      while (m < 1) {
        Houghline_real_fast_2_DW.reducenoise1_ERODE_OFF_DW = 0;
        curNumNonZ++;
        m = 1;
      }

      n = 1;
    }

    Houghline_real_fast_2_DW.reducenoise1_NUMNONZ_DW = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<S4>/reduce noise 1' */

    /* Start for S-Function (svipedge): '<S4>/Edge Detection' */
    for (previous = 0; previous < 6; previous++) {
      Houghline_real_fast_2_DW.EdgeDetection_VO_DW[previous] =
        Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
        Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      if (Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous] > 0) {
        Houghline_real_fast_2_DW.EdgeDetection_VOU_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOD_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
      } else {
        Houghline_real_fast_2_DW.EdgeDetection_VOU_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_VOD_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      }

      if (Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] > 0) {
        Houghline_real_fast_2_DW.EdgeDetection_VOL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      } else {
        Houghline_real_fast_2_DW.EdgeDetection_VOL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_VOUL_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_VOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_VOLL_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_VOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_VOUR_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_VOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_VOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_VOLR_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_VOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_VOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_VOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_VCO_RTP[previous];
      }

      Houghline_real_fast_2_DW.EdgeDetection_HO_DW[previous] =
        Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
        Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      if (Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous] > 0) {
        Houghline_real_fast_2_DW.EdgeDetection_HOU_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOD_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
      } else {
        Houghline_real_fast_2_DW.EdgeDetection_HOU_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_HOD_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      }

      if (Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] > 0) {
        Houghline_real_fast_2_DW.EdgeDetection_HOL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      } else {
        Houghline_real_fast_2_DW.EdgeDetection_HOL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_HOUL_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_HOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_HOLL_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_HOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_HOUR_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_HOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_HOLR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        Houghline_real_fast_2_DW.EdgeDetection_HOLR_DW[previous] = 0;
        Houghline_real_fast_2_DW.EdgeDetection_HOUL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230 +
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
        Houghline_real_fast_2_DW.EdgeDetection_HOLL_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HRO_RTP[previous] * 230;
        Houghline_real_fast_2_DW.EdgeDetection_HOUR_DW[previous] =
          Houghline_real_fast_2_ConstP.EdgeDetection_HCO_RTP[previous];
      }
    }

    /* End of Start for S-Function (svipedge): '<S4>/Edge Detection' */

    /* Start for S-Function (svipmorphop): '<S4>/reduce noise ' */
    curNumNonZ = 0;
    n = 0;
    while (n < 1) {
      m = 0;
      while (m < 1) {
        Houghline_real_fast_2_DW.reducenoise_ERODE_OFF_DW = 0;
        curNumNonZ++;
        m = 1;
      }

      n = 1;
    }

    Houghline_real_fast_2_DW.reducenoise_NUMNONZ_DW = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<S4>/reduce noise ' */

    /* Start for S-Function (svipmorphop): '<S4>/Dilation' */
    curNumNonZ = 0;
    n = 0;
    while (n < 1) {
      m = 0;
      while (m < 1) {
        Houghline_real_fast_2_DW.Dilation_DILATE_OFF_DW = 0;
        curNumNonZ++;
        m = 1;
      }

      n = 1;
    }

    Houghline_real_fast_2_DW.Dilation_NUMNONZ_DW = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<S4>/Dilation' */

    /* Start for S-Function (sviptextrender): '<Root>/Insert Text' */
    for (previous = 0; previous < 6; previous++) {
      Houghline_real_fast_2_DW.InsertText_StringDataDW[previous] =
        Houghline_real_fast_2_ConstP.InsertText_StrArray[previous];
    }

    /* End of Start for S-Function (sviptextrender): '<Root>/Insert Text' */
  }

  /* InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  LibReset(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
}

/* Model terminate function */
void Houghline_real_fast_2_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
  LibTerminate(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Houghline_real_fast_2_M, sErr);
    rtmSetStopRequested(Houghline_real_fast_2_M, 1);
  }

  LibDestroy(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U], 0);
  DestroyHostLibrary(&Houghline_real_fast_2_DW.FromMultimediaFile_HostLib[0U]);

  /* End of Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
}
