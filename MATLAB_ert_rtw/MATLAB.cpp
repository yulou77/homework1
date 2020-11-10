//
// File: MATLAB.cpp
//
// Code generated for Simulink model 'MATLAB'.
//
// Model version                  : 1.47
// Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
// C/C++ source code generated on : Tue Nov 10 08:25:53 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "MATLAB.h"
#define NumBitsPerChar                 8U

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern "C" {
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"
  //===========*
  //  Constants *
  // ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   // do nothing
# else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    return (boolean_T)((value!=value) ? 1U : 0U);
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    return (boolean_T)(((value!=value) ? 1U : 0U));
  }
}
  extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void MATLABModelClass::step()
{
  real_T L;
  real_T tanU1;
  real_T cosU1;
  real_T tanU2;
  real_T cosU2;
  real_T lambda;
  real_T lambda_;
  int32_T iterationLimit;
  real_T sin_delta;
  real_T cos2_deltaM;
  real_T cos_delta;
  real_T sinlambda;
  real_T coslambda;
  real_T sin_alpha;
  real_T C;
  real_T x;
  real_T b_x;
  real_T radLat1_tmp;
  real_T radLat2_tmp;
  int32_T exitg1;

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/lat1'
  //   Inport: '<Root>/lat2'
  //   Inport: '<Root>/lon1'
  //   Inport: '<Root>/lon2'

  radLat1_tmp = rtU.lat1 * 3.1415926535897931 / 180.0;
  radLat2_tmp = rtU.lat2 * 3.1415926535897931 / 180.0;
  x = std::sin((radLat1_tmp - radLat2_tmp) / 2.0);
  L = rtU.lon2 * 3.1415926535897931 / 180.0;
  tanU1 = rtU.lon1 * 3.1415926535897931 / 180.0;
  b_x = std::sin((tanU1 - L) / 2.0);
  L -= tanU1;
  tanU1 = std::tan(radLat1_tmp) * 0.99664718933525254;
  cosU1 = 1.0 / std::sqrt(tanU1 * tanU1 + 1.0);
  tanU1 *= cosU1;
  tanU2 = std::tan(radLat2_tmp) * 0.99664718933525254;
  cosU2 = 1.0 / std::sqrt(tanU2 * tanU2 + 1.0);
  tanU2 *= cosU2;
  lambda = L;
  lambda_ = 0.0;
  iterationLimit = 100;
  sinlambda = 0.0;
  coslambda = 0.0;
  do {
    exitg1 = 0;
    if (std::abs(lambda - lambda_) > 1.0E-12) {
      if (iterationLimit > 0) {
        iterationLimit--;
        sinlambda = std::sin(lambda);
        coslambda = std::cos(lambda);
        sin_delta = cosU1 * tanU2 - tanU1 * cosU2 * coslambda;
        cos_delta = cosU2 * sinlambda;
        sin_delta = std::sqrt(sin_delta * sin_delta + cos_delta * cos_delta);
        if (sin_delta == 0.0) {
          rtY.revAz = 0.0;
          exitg1 = 1;
        } else {
          lambda_ = cosU1 * cosU2;
          cos_delta = lambda_ * coslambda + tanU1 * tanU2;
          sin_alpha = lambda_ * sinlambda / sin_delta;
          lambda_ = 1.0 - sin_alpha * sin_alpha;
          cos2_deltaM = cos_delta - 2.0 * tanU1 * tanU2 / lambda_;
          C = ((4.0 - 3.0 * lambda_) * 0.0033528106647474805 + 4.0) *
            (0.00020955066654671753 * lambda_);
          lambda_ = lambda;
          lambda = (((2.0 * cos2_deltaM * cos2_deltaM + -1.0) * (C * cos_delta)
                     + cos2_deltaM) * (C * sin_delta) + rt_atan2d_snf(sin_delta,
                     cos_delta)) * ((1.0 - C) * 0.0033528106647474805 *
            sin_alpha) + L;
        }
      } else {
        rtY.revAz = rt_atan2d_snf(cosU1 * sinlambda, cosU1 * tanU2 * coslambda +
          -tanU1 * cosU2);
        exitg1 = 1;
      }
    } else {
      rtY.revAz = rt_atan2d_snf(cosU1 * sinlambda, cosU1 * tanU2 * coslambda +
        -tanU1 * cosU2);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  // Outport: '<Root>/Distance' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function1'

  rtY.Distance = std::asin(std::sqrt(std::cos(radLat1_tmp) * std::cos
    (radLat2_tmp) * (b_x * b_x) + x * x)) * 12742.008;
}

// Model initialize function
void MATLABModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
MATLABModelClass::MATLABModelClass()
{
}

// Destructor
MATLABModelClass::~MATLABModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * MATLABModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
