#include "ft_printf_bonus.h"

static int ft_numlen(int n)
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

static void ft_filler(char ch, int counter,int *bytes)
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
    int i;
    char sign;

    i = 0;

    if(flg->press < ft_numlen(n))
        flg->press = ft_numlen(n);
    if(n < 0)
        sign = '-';
    else
        sign = '+';


    ft_putnbr(n,bytes);
}
