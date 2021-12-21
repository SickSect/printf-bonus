#include "ft_printf_bonus.h"

int ft_char(int ch,flg_stc *flg)
{
    if(flg->mns == 1)
    {
        ft_putchar(ch, flg);
        ft_filler(' ', flg->width - 1, flg);
    }
    else
    {
        ft_filler(' ', flg->width - 1, flg);
        ft_putchar(ch, flg);
    }
    return(0);
}

int ft_string(char *str, flg_stc *flg)
{
  int f_null;
  char c_null [] = "(null)";

  if(!str)
  {
    str = c_null;
    f_null = 1;
  }
    if(flg->mns == 1)
    {
      if(flg->press == -1)
      {
        ft_putstr(str, ft_strlen(str), flg);
        ft_filler(' ', flg->width - ft_strlen(str), flg);
      }
      else
      {
        if(flg->press < ft_strlen(str))
        {
          if (f_null != 1)
            ft_putstr(str, flg->press, flg);
          else if (f_null == 1 && flg->press > 6)
          {
            ft_filler(' ', flg->width, flg);
            ft_putstr("(null)", 6, flg);
          }
          else if (f_null == 1 && flg->press < 6)
            ft_filler(' ', flg->width, flg);
          ft_filler(' ', flg->width - flg->press, flg);
        }
        else
        {
          ft_putstr(str, ft_strlen(str), flg);
          ft_filler(' ', flg->width - ft_strlen(str), flg);
        }
      }
    }
    else
    {
      if(flg->press == -1)
      {
        ft_filler(' ', flg->width - ft_strlen(str), flg);
        ft_putstr(str, ft_strlen(str), flg);
      }
      else
      {
        if(flg->press < ft_strlen(str))
        {
          if(f_null == 1 && flg->press < ft_strlen(str))
            return (1);
          ft_filler(' ', flg->width - flg->press, flg);
          ft_putstr(str, flg->press, flg);
        }
        else
        {
          ft_filler(' ', flg->width - ft_strlen(str), flg);
          ft_putstr(str, ft_strlen(str), flg);
        }
      }
    }
    return(0);
}

void ft_hex(unsigned long int n,flg_stc *flg, char *base)
{
  if (n < 16)
  {
    ft_putchar(base[n], flg);
  }
  else
  {
    ft_hex(n / 16, flg, base);
    ft_putchar (base[n % 16], flg);
  }
}