#include "ft_printf_bonus.h"

int ft_numlen(int n)
{
      int len;

      len = 0;
      while(n / 10 != 0)
      {
            n /= 10;
            len++;
      }
      return(len + 1);
}

void ft_digit(int n, int *bytes,flg_stc *flg)
{
      int len;
      int lb;
      int rb;

      lb = 0;
      rb = 0;
      len = ft_numlen(n);
      if(flg->press < n)
            flg->press = n;


      (void)flg;
      (void)bytes;
      (void)n;
}
