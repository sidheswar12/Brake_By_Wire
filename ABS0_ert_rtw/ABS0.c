/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS0.c
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

#include "ABS0.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Model step function */
void ABS0_step(void)
{
  real_T rtb_DataTypeConversion;
  real_T rtb_DataTypeConversion1;
  real_T rtb_Gain4;

  /* Outport: '<Root>/Output' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator3'
   */
  rtY.Output = rtDW.DiscreteTimeIntegrator3_DSTATE;

  /* Gain: '<S1>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
   */
  rtb_Gain4 = 0.8 * rtDW.DiscreteTimeIntegrator2_DSTATE;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Product: '<S1>/Divide'
   */
  rtb_DataTypeConversion1 = 0.8 - rtDW.DiscreteTimeIntegrator_DSTATE / rtb_Gain4;

  /* Gain: '<S1>/Gain1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  Gain: '<S1>/Gain'
   *  Lookup_n-D: '<S1>/1-D Lookup Table'
   */
  rtb_DataTypeConversion = 183.9375 * look1_binlx(rtb_DataTypeConversion1,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 19U) *
    1.25;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  rtDW.DiscreteTimeIntegrator3_DSTATE += 0.001 * rtb_Gain4;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S1>/Sum1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += (rtb_DataTypeConversion -
    rtDW.DiscreteTimeIntegrator1_DSTATE) * 0.25 * 0.001;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  rtDW.DiscreteTimeIntegrator2_DSTATE += -0.013333333333333334 *
    rtb_DataTypeConversion * 0.001;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator4'
   */
  rtDW.DiscreteTimeIntegrator1_DSTATE += 0.001 *
    rtDW.DiscreteTimeIntegrator4_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator4' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant1'
   *  RelationalOperator: '<S2>/GreaterThan'
   *  RelationalOperator: '<S2>/Less Than'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  rtDW.DiscreteTimeIntegrator4_DSTATE += (real_T)((0.2 - rtb_DataTypeConversion1
    > 0.0) - (0.2 - rtb_DataTypeConversion1 < 0.0)) * 0.001;
}

/* Model initialize function */
void ABS0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
