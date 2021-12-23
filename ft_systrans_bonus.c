#include "ft_printf_bonus.h"

void ft_catch_width(va_list arg,flg_stc *flg, const char *str)
{
  int temp;

  if (str[flg->id] == '*')
  {
    temp = va_arg(arg, int);
    if (temp < 0)
    {
      flg->mns = 1;
      flg->width = temp * -1;
    }
    else
      flg->width = temp;
    flg->id += 1;
  }
  else
    flg->width = ft_catch_wp(str,flg);
}

void ft_catch_press(va_list arg,flg_stc *flg, const char *str)
{
  int temp;
  if (str[flg->id] == '.')
  {
    if(str[++flg->id] == '*')
    {
      temp =  va_arg(arg, int);
      if(temp < -1)
        flg->press = -1;
      else
        flg->press = temp;
      flg->id += 1;
    }
    else
      flg->press = ft_catch_wp(str, flg);
  }
}

void ft_OX(char *str, flg_stc *flg)
{
	ft_putchar(str[16], flg);
	ft_putchar(str[17], flg);
}

void ft_ohex(unsigned long int n, flg_stc *flg, char *base)
{
  if (n < 16)
  {
    ft_putchar(base[n],flg);
  }
  else
  {
    ft_ohex(n / 16, flg, base);
    ft_putchar (base[n % 16], flg);
  }
}

void ft_filler(char fill, int counter, flg_stc *flg)
{
	if(counter < 0)
		return ;
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