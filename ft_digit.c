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
      int i;
      int j;

      i = 0;
      j = 0;
      if(flg->flg_pls == 1)
      {
            if(n < 0)
            {
                  n *= -1;
                  ft_putchar('-',bytes);
            }
            else
                  ft_putchar('+',bytes);
      }
      if(flg->press > flg->width && flg->width != -1)
      {
            j = flg->press - ft_numlen(n);
            while(i < j)
            {
                  ft_putchar('0',bytes);
                  i++;
            }
      }

      ft_putnbr_fd(n,bytes);
      (void)flg;
      (void)bytes;
      (void)n;
}
