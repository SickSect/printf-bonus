#include "ft_printf_bonus.h"

int main()
{
  //ft_printf("TEST 1 %+ 12.23d\n",123);
  printf("ORIG 1 %0 12.23d %12.23d\n",123,123);
  //ft_printf("TEST 2 %-03.10d %#31.10d\n",123);
  printf("ORIG 2 %010.d % 5.10d  % .10d\n",123,5887,987);
  //ft_printf("TEST 3 %-.4d %*.*d",10,11,12);
  printf("ORIG 3 %-11.2d %-*.*d",432,10,3,12);

  //printf("\n%#x\n",123);
  //printf("\n   %+010.10d\n",123);
  return(0);
}
