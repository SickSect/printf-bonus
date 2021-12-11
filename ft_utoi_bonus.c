#include "ft_printf_bonus.h"

int ft_ulen(unsigned long int n)
{
    int len;
    unsigned long int num;

    num = n;
    len = 0;
    while (num / 10 != 0)
    {
        len++;
        num /= 10;
    }
    return(len + 1);
}

void ft_nbr(unsigned long int n, flg_stc *flg)
{
	char	str[13];
	long		i;

	i = 0;
	ft_bzero(str, 13);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
  i--;
	while (i >= 0)
	{
		ft_putchar(str[i], flg);
		i--;
	}
}

void ft_utoi_mns(unsigned long int num,flg_stc *flg)
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

void ft_utoi_zro(unsigned long int num,flg_stc *flg)
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

void ft_utoi(unsigned long int num,flg_stc *flg)
{
  if(flg->mns == 1)
    ft_utoi_mns(num, flg);
  else if(flg->zro == 1)
    ft_utoi_zro(num, flg);
  else
  {
      if(flg->press <= 0)
      {
        ft_filler(' ', flg->width - ft_ulen(num), flg);
        ft_nbr(num, flg);
      }
      else
      {
        ft_filler(' ', flg->width - flg->press, flg);
        ft_filler('0', flg->press - ft_ulen(num), flg);
        ft_nbr(num, flg);
      }
  }
}
