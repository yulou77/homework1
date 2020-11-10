//
// File: MATLAB.h
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
#ifndef RTW_HEADER_MATLAB_h_
#define RTW_HEADER_MATLAB_h_
#include <stddef.h>
#include <cmath>
#include <math.h>
#ifndef MATLAB_COMMON_INCLUDES_
# define MATLAB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // MATLAB_COMMON_INCLUDES_

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// External inputs (root inport signals with default storage)
typedef struct {
  real_T lon1;                         // '<Root>/lon1'
  real_T lon2;                         // '<Root>/lon2'
  real_T lat1;                         // '<Root>/lat1'
  real_T lat2;                         // '<Root>/lat2'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T Distance;                     // '<Root>/Distance'
  real_T revAz;                        // '<Root>/revAz'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

// Class declaration for model MATLAB
class MATLABModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  MATLABModelClass();

  // Destructor
  ~MATLABModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('untitled/MATLAB Function1')    - opens subsystem untitled/MATLAB Function1
//  hilite_system('untitled/MATLAB Function1/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'untitled'
//  '<S1>'   : 'untitled/MATLAB Function1'

#endif                                 // RTW_HEADER_MATLAB_h_

//
// File trailer for generated code.
//
// [EOF]
//
