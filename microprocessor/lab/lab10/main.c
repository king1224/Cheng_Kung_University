#include "io430.h"

unsigned int dmadst[1000];
/*
You should configure the following registers of adc & DMA.
ADC:
ADC12CTL0	configure reference voltage,sample &conversion time, adc on, enable ADC12SC automatically after conversion
ADC12CTL1	configure Pulse mode, timer and  sample mode 
ADC12MCTL0	channel(you can find the corresponding inch in user guide) & reference(1.5V)
ADC12CTL2	resolution

DMA:
DMACTL0		triggered by ADC12IFGx 
DMA0CTL		Repeat single tranfer, inc dst, Enable Interrupt
DMA0SZ		Size
DMA0SA		Source address
DMA0DA		destination
*/
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  REFCTL0 &= ~REFMSTR;
 /*
	write your code here.
 */
  ADC12CTL0 = ADC12SHT0_8 + ADC12REFON + ADC12ON + ADC12MSC;
/*
  ADC12CTL0_bit.ADC12REF2_5V = 0;
  ADC12CTL0_bit.ADC12SHT00   = 0;
  ADC12CTL0_bit.ADC12SHT01   = 1;
  ADC12CTL0_bit.ADC12SHT02   = 0;
  ADC12CTL0_bit.ADC12SHT03   = 1;
  ADC12CTL0_bit.ADC12REFON   = 1;
  ADC12CTL0_bit.ADC12ON      = 1;
  ADC12CTL0_bit.ADC12SC      = 1;
*/

  ADC12CTL1 = ADC12SHP + ADC12SSEL1 + ADC12CONSEQ1;
  ADC12MCTL0 = ADC12SREF_1 + ADC12INCH_10;
  ADC12CTL2 = ADC12RES_2;
  
  ADC12CTL0 |= ADC12ENC;
  ADC12CTL0 |= ADC12SC;
  
//  ADC12CTL1 = ADC12SHP_H + ADC12SSEL_2 + ADC12CONSEQ_2;
//  ADC12MCTL0 = ADC12SREF_0 + ADC12INCH_10;
//  ADC12CTL2 = ADC12RES_2;
  
  DMACTL0 = DMA0TSEL_24;
  DMA0CTL = DMAEN_L + DMADT_4 + DMADSTINCR_3 + DMAIE_L;
  
  DMA0SZ = 0x1000;
  DMA0SA = 0x0720;
  DMA0DA = (unsigned int)&dmadst[0];
  
  P1DIR=1;
  
  __bis_SR_register(LPM4_bits + GIE);     // LPM0 with interrupts enabled
  __no_operation();
}

//------------------------------------------------------------------------------
// DMA Interrupt Service Routine
//------------------------------------------------------------------------------
#pragma vector=DMA_VECTOR
__interrupt void DMA_ISR(void)
{
  switch(__even_in_range(DMAIV,16))
  {
    case 0: break;
    case 2:                                 // DMA0IFG = DMA Channel 0
      P1OUT ^= BIT0;                        // Toggle P1.0 - PLACE BREAKPOINT HERE AND CHECK DMA_DST VARIABLE
      break;
    case 4: break;                          // DMA1IFG = DMA Channel 1
    case 6: break;                          // DMA2IFG = DMA Channel 2
    case 8: break;                          // DMA3IFG = DMA Channel 3
    case 10: break;                         // DMA4IFG = DMA Channel 4
    case 12: break;                         // DMA5IFG = DMA Channel 5
    case 14: break;                         // DMA6IFG = DMA Channel 6
    case 16: break;                         // DMA7IFG = DMA Channel 7
    default: break;
  }
}