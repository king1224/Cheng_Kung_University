
#include "io430.h"

extern long long int Mult(long int a,long int b,long int c,long int d,long int e);

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  /*while(1){
    LED();
  }*/
  long int a=65538;
  long int b=65539;
  long int c=65540;
  long int d=65541;
  long int e=65542;
  long int ans=0;
  ans=Mult(a,b,c,d,e);
  
  return 0;
}