#include "ft_printf_bonus.h"

int ft_numlen(long int n)
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
void ft_filler(char fill, int counter, flg_stc *flg)
{
  int i;
  if(counter <= 0)
      return ;
  i = 0;
  while (i < counter)
  {
    ft_putchar(fill, flg);
    i++;
  }
}
int ft_if_sign(flg_stc *flg, int n)
{
  if(flg->pls == 1 && n > 0)
    return(1);
  else if(flg->spc == 1 && n > 0)
    return (1);
  else if(n < 0)
    return(1);
  return (0);
}
void ft_output_sign(flg_stc *flg, int n)
{
  if(flg->pls == 1 && n > 0)
    ft_putchar('+', flg);
  else if(flg->spc == 1 && n > 0)
    ft_putchar(' ', flg);
  if(n < 0)
    ft_putchar('-', flg);
}
void ft_digit(long int n, flg_stc *flg)
{
    ft_output_sign(flg, n);
    if(flg->mns == 1)
    {
        ft_filler('0', flg->press - ft_numlen(n), flg);
        if (n > 0)
          ft_putnbr(n, flg);
        else
          ft_putnbr(n * -1, flg);
        if(flg->width > flg->press && flg->press > 0)
          ft_filler(' ',flg->width - flg->press - ft_if_sign(flg, n), flg);
        else if (flg->press == -1)
          ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
    }
    else if (flg->zro == 1)
    {
      ft_filler('0', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
      if (n > 0)
        ft_putnbr(n, flg);
      else
        ft_putnbr(n * -1, flg);
    }
    else if (flg->zro == 0 && flg->mns == 0)
    {
      if(flg->width > flg->press && flg->press > 0)
        ft_filler(' ',flg->width - flg->press - ft_if_sign(flg, n), flg);
      else if (flg->press == -1 || flg->press == 0)
        ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
      ft_output_sign(flg, n);
      if(flg->press > 0)
        ft_filler('0', flg->press - ft_numlen(n), flg);
      if (n > 0)
        ft_putnbr(n, flg);
      else
        ft_putnbr(n * -1, flg);
    }
    else
      ft_putnbr(n, flg);
}
