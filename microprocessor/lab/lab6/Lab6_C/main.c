#define PORT2_VECTOR    (42 * 2u)
#define PORT1_VECTOR    (47 * 2u)


#include "io430.h"
#include "intrinsics.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  P2DIR = 0x00;
  P2SEL = 0x00;
  P2REN = 0x02;
  P2OUT = 0x02;
  P2IES = 0x02;
  P2IE  = 0x02;
  
  P1DIR = 0x00;
  P1SEL = 0x00;
  P1REN = 0x02;
  P1OUT = 0x02;
  P1IES = 0x02;
  P1IE  = 0x02;
  
  P1DIR = 0x01;
  P1SEL = 0x00;
  P4DIR = 0x80;
  P4SEL = 0x00;
  
  __bis_SR_register(GIE);
  
  for(;;){
    ;
  }
}

#pragma vector=PORT2_VECTOR
__interrupt void P2_ISR(void){
  P2IE  = 0x00; 
  
  P1OUT = P1OUT | 0x01;
  int i,j;
  for(i=0;i<900;++i){
    for(j=0;j<500;++j){
      ;
    }
  }
  P1OUT = P1OUT - 0x01;
  
  P2IFG = 0x00;
  P2IE  = 0x02;
}

#pragma vector=PORT1_VECTOR
__interrupt void P1_ISR(void){
  P1IE  = 0x00; 
  
  P4OUT = 0x80;
  int i,j;
  for(i=0;i<900;++i){
    for(j=0;j<500;++j){
      ;
    }
  }
  P4OUT = 0x00;
  
  P1IFG = 0x00;
  P1IE  = 0x02;
}
