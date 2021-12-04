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

void ft_filler(char ch, int counter,int *bytes)
{
    int i;

    i = 0;
    while(i < counter)
    {
        ft_putchar(ch,bytes);
        i++;
    }
}

void ft_digit(int n, int *bytes,flg_stc *flg)
{
    char sign;
    int i;

    i = 0;
    sign = '+';
    if(n < 0)
    {
        sign = '-';
        n *= -1;
    }

    if (flg->width > flg->press)
        i = flg->width - ft_numlen(n);
    else
        i = flg->press - ft_numlen(n);

    if(flg->press > flg->width || flg->width > flg->press)
    {
        
    }


    (void)n;
    (void)bytes;
    (void)flg;
    (void)i;
    (void)sign;
}
