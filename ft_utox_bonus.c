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

void ft_hex(unsigned long int n, flg_stc *flg, char *base)
{

}

void ft_hex_mns(unsigned long int num,flg_stc *flg, char *base)
{
  if(flg->press <= 0)
  {
    ft_nbr(num, flg);
    ft_filler(' ', flg->width - ft_ulen(num), flg);
  }
  else
  {
    ft_filler('0', flg->press - ft_ulen(num), flg);
    ft_nbr(num, flg);
    ft_filler(' ', flg->width - flg->press, flg);
  }
}

void ft_hex_zro(unsigned long int num,flg_stc *flg, char *base)
{
  if(flg->press > flg->width)
  {
    ft_filler('0', flg->press - ft_ulen(num), flg);
    ft_nbr(num, flg);
  }
  else if (flg->press <= 0)
  {
    ft_filler('0', flg->width - ft_ulen(num), flg);
    ft_nbr(num, flg);
  }
  else
  {
    ft_filler(' ', flg->width - flg->press, flg);
    ft_filler('0', flg->press - ft_ulen(num), flg);
    ft_nbr(num, flg);
  }
}

void ft_utox(unsigned long int num,flg_stc *flg, char *base)
{
  if(flg->mns == 1)
    ft_utox_mns(num, flg);
  else if(flg->zro == 1)
    ft_utox_zro(num, flg);
  else
  {
      if(flg->press <= 0)
      {
        ft_filler(' ', flg->width - ft_xlen(num), flg);
        ft_hex(num, flg);
      }
      else
      {
        ft_filler(' ', flg->width - flg->press, flg);
        ft_filler('0', flg->press - ft_x len(num), flg);
        ft_hex(num, flg);
      }
  }
}
