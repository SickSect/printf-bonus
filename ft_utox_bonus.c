#include "ft_printf_bonus.h"

int ft_xlen(unsigned int n)
{
    int len;
    unsigned long int num;

    num = n;
    len = 0;
    while (num / 16 != 0)
    {
        len++;
        num /= 16;
    }
    return(len + 1);
}

void ft_ohex(unsigned int n, flg_stc *flg, char *base)
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

void ft_hex_mns(unsigned int num,flg_stc *flg, char *base)
{
  if(flg->press <= 0)
  {
    ft_ohex(num, flg, base);
    ft_filler(' ', flg->width - ft_xlen(num), flg);
  }
  else if(flg->press > flg->width)
  {
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
  }
  else
  {
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
    if(flg->width > ft_xlen(num) && flg->width > flg->press)
    {
      if(flg->press > ft_xlen(num))
        ft_filler(' ', flg->width - flg->press, flg);
      else
        ft_filler(' ', flg-> width - ft_xlen(num), flg);
    }
    else if(flg->press > ft_xlen(num) && flg->press > flg->width)
    {
      ft_filler(' ', flg->press - ft_xlen(num), flg);
    }
    /*
    if(flg->width > ft_xlen(num) && flg->width > flg->press)
      ft_filler(' ', flg-> width - ft_xlen(num), flg);
    else if(flg->press > ft_xlen(num) && flg->press > flg->width)
      ft_filler(' ', flg->press - ft_xlen(num), flg);

    if(flg->press >= ft_xlen(num) && flg->press > flg->width)
      ft_filler(' ', flg->width - ft_xlen(num), flg);
    else if (flg->press < flg->width && flg->press >= ft_xlen(num))
      ft_filler(' ', flg->width - flg->press, flg);
      */

  }
}

void ft_hex_zro(unsigned int num,flg_stc *flg, char *base)
{
  if(flg->press > flg->width)
  {
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
  }
  else if (flg->press == -1)
  {
    ft_filler('0', flg->width - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
  }
  else
  {
    if(flg->press > ft_xlen(num))
    {
      ft_filler(' ', flg->width - flg->press, flg);
      ft_filler('0', flg->press - ft_xlen(num), flg);
    }
    else
    {
      ft_filler(' ', flg->width - ft_xlen(num), flg);
    }
    ft_ohex(num, flg, base);
  }
}

void ft_htoi(unsigned int num,flg_stc *flg, char *base)
{
  if(flg->press == 0 && num == 0)
  {
    ft_filler (' ', flg->width, flg);
    return ;
  }
  if(flg->okt == 1)
  {
    ft_putchar('0', flg);
    ft_putchar(base[17], flg);
  }
  if(flg->mns == 1)
    ft_hex_mns(num, flg, base);
  else if(flg->zro == 1)
    ft_hex_zro(num, flg, base);
  else if (flg->mns == 0 && flg->zro == 0 && (flg->width >= 0 || flg->press >= 0))
  {
    if(flg->width > 0 && flg->width > ft_xlen(num) && flg->width > flg->press)
    {
      if(flg->press > ft_xlen(num))
      {
        ft_filler(' ', flg->width - flg->press, flg);
        ft_filler('0', flg->press - ft_xlen(num), flg);
      }
      else
        ft_filler(' ', flg->width - ft_xlen(num), flg);
    }
    else if (flg->press >= flg->width)
    {
      ft_filler('0', flg->press - ft_xlen(num), flg);
    }
    else if((flg->width == 0 || flg->width < flg->press)&& flg->press > 0)
    {
      ft_filler('0', flg->press - ft_xlen(num), flg);
    }
    ft_ohex(num, flg, base);
    /*
      if(flg->press == 0 && flg->width > 0 && flg->width > ft_numlen(num))
      {
        ft_filler(' ', flg->width - ft_xlen(num), flg);
        ft_ohex(num, flg, base);
      }
      else if(flg->width == 0 && flg->press == -1)
        ft_ohex(num, flg, base);
      else
      {
        ft_filler(' ', flg->width - ft_xlen(num), flg);
        //ft_filler('0', flg->press - ft_xlen(num), flg);
        ft_ohex(num, flg, base);
      }
      */
  }
  else
    ft_ohex(num, flg, base);
}
