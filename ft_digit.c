#include "ft_printf_bonus.h"

int ft_numlen(int n)
{
    int len;
    int num;

    if (n < 0)
        num = n * -1;
    else
        num = n;
    len = 0;
    while (num / 10)
    {
        len++;
        num /= 10;
    }
    return(len + 1);
}
void ft_filler(char fill, int counter, int *bytes)
{
  int i;

  i = 0;
  while (i < counter)
  {
    ft_putchar(fill, bytes);
    i++;
  }
}
int ft_if_sign(flg_stc *flg, int n)
{
  if(flg->flg_pls == 1 && n > 0)
    return(1);
  else if(flg->flg_spc == 1 && n > 0)
    return (1);
  else if(n < 0)
    return(1);
  return (0);
}
void ft_output_sign(flg_stc *flg, int n, int *bytes)
{
  if(flg->flg_pls == 1 && n > 0)
    ft_putchar('+', bytes);
  else if(flg->flg_spc == 1 && n > 0)
    ft_putchar(' ', bytes);
  if(n < 0)
    ft_putchar('-', bytes);
}
void ft_digit(int n, int *bytes,flg_stc *flg)
{
    if(flg->flg_mns == 1)
    {
      /*
      if(flg->width > flg->press && flg->press > 0)
      {
        ft_output_sign(flg, n, bytes);
        ft_filler('0', flg->press - ft_numlen(n), bytes);
        if (n > 0)
          ft_putnbr(n, bytes);
        else
          ft_putnbr(n * -1, bytes);
        ft_filler(' ',flg->width - flg->press - ft_if_sign(flg, n), bytes);
      }
      */
        ft_output_sign(flg, n, bytes);
        ft_filler('0', flg->press - ft_numlen(n), bytes);
        if (n > 0)
          ft_putnbr(n, bytes);
        else
          ft_putnbr(n * -1, bytes);
        if(flg->width > flg->press && flg->press > 0)
          ft_filler(' ',flg->width - flg->press - ft_if_sign(flg, n), bytes);
        else if (flg->press == -1)
          ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), bytes);
    }
    else if (flg->flg_zro == 1)
    {
      ft_output_sign(flg, n, bytes);
      ft_filler('0', flg->width - ft_numlen(n) - ft_if_sign(flg, n), bytes);
      if (n > 0)
        ft_putnbr(n, bytes);
      else
        ft_putnbr(n * -1, bytes);
    }
    else
    {
      if(flg->width > flg->press && flg->press > 0)
        ft_filler(' ',flg->width - flg->press - ft_if_sign(flg, n), bytes);
      else if (flg->press == -1 || flg->press == 0)
        ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), bytes);
      ft_output_sign(flg, n, bytes);
      if(flg->press > 0)
        ft_filler('0', flg->press - ft_numlen(n), bytes);
      if (n > 0)
        ft_putnbr(n, bytes);
      else
        ft_putnbr(n * -1, bytes);
    }
    (void)n;
    (void)bytes;
    (void)flg;
}
