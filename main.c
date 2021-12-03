#include "ft_printf_bonus.h"

int main()
{
  ft_printf("TEST 1 %+12.23d FIN 1 TEST\n",123);
  ft_printf("TEST 2 %-3.10d %#31.10d FIN 2 TEST\n",123);
  ft_printf("TEST 3 %-.4d %*.*d",10,11,12);
  //printf("\n%d",123);
  return(0);
}
