#include "ft_printf_bonus.h"

int main()
{
  ft_printf("TEST 1 |%+12.23d| |%+2.4d|\n",-123,123);
  printf(   "ORIG 1 |%+12.23d| |%+2.4d|\n",-123,123);
  ft_printf("TEST 2 |%010.d| |% 1.5d| |% .10d|\n",123,5887,987);
  printf   ("ORIG 2 |%010.d| |% 1.5d| |% .10d|\n",123,5887,987);
  ft_printf("TEST 3 |%-11.2d| |%-*.*d|\n",-432,10,11,13);
  printf(   "ORIG 3 |%-11.2d| |%-*.*d|\n",-432,10,11,13);
  ft_printf("TEST 4 |%-12.23d| |%-2.4d|\n",-123,123);
  printf(   "ORIG 4 |%-12.23d| |%-2.4d|\n",-123,123);

  //printf("\n%#x\n",123);
  //printf("\n   %+010.10d\n",123);
  return(0);
}
