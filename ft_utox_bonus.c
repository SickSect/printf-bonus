#include "ft_printf_bonus.h"

int ft_xlen(unsigned long int n)
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

void ft_hex_mns(unsigned long int num,flg_stc *flg, char *base)
{
  if(flg->press <= 0)
  {
    ft_ohex(num, flg, base);
    ft_filler(' ', flg->width - ft_xlen(num), flg);
  }
  else
  {
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
    ft_filler(' ', flg->width - flg->press, flg);
  }
}

void ft_hex_zro(unsigned long int num,flg_stc *flg, char *base)
{
  if(flg->press > flg->width)
  {
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
  }
  else if (flg->press <= 0)
  {
    ft_filler('0', flg->width - ft_xlen(num), flg);
    ft_ohex(num, flg, base);
  }
  else
  {
    ft_filler(' ', flg->width - flg->press, flg);
    ft_filler('0', flg->press - ft_xlen(num), flg);
    ft_nbr(num, flg);
  }
}

void ft_htoi(unsigned int num,flg_stc *flg, char *base)
{
  if(flg->mns == 1)
    ft_hex_mns(num, flg, base);
  else if(flg->zro == 1)
    ft_hex_zro(num, flg, base);
  else
  {
      if(flg->press <= 0)
      {
        ft_filler(' ', flg->width - ft_xlen(num), flg);
        ft_ohex(num, flg, base);
      }
      else
      {
        ft_filler(' ', flg->width - flg->press, flg);
        ft_filler('0', flg->press - ft_xlen(num), flg);
        ft_ohex(num, flg, base);
      }
  }
}
