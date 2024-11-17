/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS0.h
 *
 * Code generated for Simulink model 'ABS0'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Nov 17 11:57:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ABS0_h_
#define RTW_HEADER_ABS0_h_
#ifndef ABS0_COMMON_INCLUDES_
#define ABS0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ABS0_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S1>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S1>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S1>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S1>/Discrete-Time Integrator4' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: tanh([0
     0.4
     0.8
     0.97
     1
     0.98
     0.96
     0.94
     0.92
     0.9
     0.855
     0.83
     0.81
     0.79
     0.77
     0.75
     0.73
     0.72
     0.71
     0.7
     ])
   * Referenced by: '<S1>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[20];

  /* Expression: [0
     0.05
     0.1
     0.15
     0.2
     0.25
     0.35
     0.4
     0.45
     0.5
     0.55
     0.6
     0.65
     0.7
     0.75
     0.8
     0.85
     0.9
     0.95
     1
     ]
   * Referenced by: '<S1>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[20];
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void ABS0_initialize(void);
extern void ABS0_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Actual Sleep ABS' : Unused code path elimination
 * Block '<S1>/Vehicle Speed ABS' : Unused code path elimination
 * Block '<S1>/Wheel Speed ABS' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BBW_ABS_2023HT65255/ABS')    - opens subsystem BBW_ABS_2023HT65255/ABS
 * hilite_system('BBW_ABS_2023HT65255/ABS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BBW_ABS_2023HT65255'
 * '<S1>'   : 'BBW_ABS_2023HT65255/ABS'
 * '<S2>'   : 'BBW_ABS_2023HT65255/ABS/PID Controler'
 */
#endif                                 /* RTW_HEADER_ABS0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
