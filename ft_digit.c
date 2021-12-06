#include "ft_printf_bonus.h"

int ft_filllen(int num, flg_stc *flg)
{
      int len;
      int ret;
      int n;

      n = num;
      len = 0;
      while(n / 10 != 0)
      {
            n /= 10;
            len++;
      }
      len++;
      if (flg-> press <= 0 && flg->width > len)
        ret = flg->width - len;
      else if(flg->press > flg->width && flg->press > len)
        ret = flg->press - len;
      else
        ret = len;

      return (ret);
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
    i = ft_filllen(n, flg);
    if (flg->press < flg->width && flg->flg_mns == 1)
    {
      ft_putchar('H',bytes);
    }
    else if (flg->flg_zro == 1 || flg->press > flg->width)
    {
      ft_putchar('A', bytes);
    }
    else if (flg->press == 0)
    {
      ft_putchar('B', bytes);
    }
    (void)n;
    (void)bytes;
    (void)flg;
    (void)i;
    (void)sign;
}
