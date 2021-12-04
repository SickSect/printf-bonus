#include "ft_printf_bonus.h"

int main()
{
    //ft_printf("|%012d|\n",-123);
    //printf("|%012d|\n",-123);
    ft_printf("TEST 0 |% 012d| |% 5.7d| |% -10.15d|\n",-23,456,-345);
    printf(   "ORIG 0 |% 012d| |% 5.7d| |% -10.15d|\n",-23,456,-345);
  ft_printf("TEST 1 |%012d| |%+6.d| |%5.d| |%-10.15d|\n",-123,123,564,123);
  printf(   "ORIG 1 |%012d| |%+6.d| |%5.d| |%-10.15d|\n",-123,123,564,123);
  ft_printf(   "TEST 2 |%-10d| |%-+15d| |%-+10d|\n",123,5887,987);
  printf   (   "ORIG 2 |%-10d| |%-+15d| |%-+10d|\n",123,5887,987);
  ft_printf(      "TEST 3 |%-11.2d| |%-*.*d|\n",-432,10,11,13);
  printf(         "ORIG 3 |%-11.2d| |%-*.*d|\n",-432,10,11,13);
  ft_printf("TEST 4 |%-5.8d| |%-2.4d|\n",-123,123);
  printf(   "ORIG 4 |%-5.8d| |%-2.4d|\n",-123,123);

  //printf("\n%#x\n",123);
  //printf("\n   %+010.10d\n",123);
  return(0);
}
