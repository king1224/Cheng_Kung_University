
#include "io430.h"

extern unsigned long long int multi(unsigned int a, unsigned int b, unsigned int c, unsigned int d); 
extern unsigned int digital_sum(unsigned long long int a); 
extern void LED_blink(unsigned int times); 

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  unsigned int sum=50;
  unsigned long long ans=169;
  ans = multi(9999,9999,9999,9999);
  sum = digital_sum(ans);
  LED_blink(sum);
  while(1);
  return 0;
}
