#include "ft_printf_bonus.h"

void	ft_nbr(unsigned int n, t_flg_stc *flg)
{
	char	str[13];
	long	i;

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

void	ft_utoi_mns(unsigned int num, t_flg_stc *flg)
{
	if (flg->press <= 0)
	{
		ft_nbr(num, flg);
		ft_filler(' ', flg->width - ft_ulen(num), flg);
	}
	else if (flg->press > flg->width && flg->press > ft_numlen(num))
	{
		ft_filler('0', flg->press - ft_ulen(num), flg);
		ft_nbr(num, flg);
	}
	else
	{
		ft_filler('0', flg->press - ft_ulen(num), flg);
		ft_nbr(num, flg);
		if (flg->width > ft_ulen(num) && flg->width > flg->press)
		{
			if (flg->press > ft_ulen(num))
				ft_filler(' ', flg->width - flg->press, flg);
			else
				ft_filler(' ', flg-> width - ft_ulen(num), flg);
		}
		else if (flg->press > ft_ulen(num) && flg->press > flg->width)
			ft_filler(' ', flg->press - ft_ulen(num), flg);
	}
}

void	ft_utoi_zro(unsigned int num, t_flg_stc *flg)
{
	if (flg->press > flg->width)
	{
		ft_filler('0', flg->press - ft_ulen(num), flg);
		ft_nbr(num, flg);
	}
	else if (flg->press == -1)
	{
		ft_filler('0', flg->width - ft_ulen(num), flg);
		ft_nbr(num, flg);
	}
	else
	{
		if (flg->press > ft_ulen(num))
		{
			ft_filler(' ', flg->width - flg->press, flg);
			ft_filler('0', flg->press - ft_ulen(num), flg);
		}
		else
			ft_filler(' ', flg->width - ft_ulen(num), flg);
		ft_nbr(num, flg);
	}
}

void	ft_utoi_base(unsigned int num, t_flg_stc *flg)
{
	if (flg->width > 0 && flg->width > ft_ulen(num) && flg->width > flg->press)
	{
		if (flg->press > ft_ulen(num))
		{
			ft_filler(' ', flg->width - flg->press, flg);
			ft_filler('0', flg->press - ft_ulen(num), flg);
		}
		else
			ft_filler(' ', flg->width - ft_ulen(num), flg);
	}
	else if (flg->press >= flg->width)
		ft_filler('0', flg->press - ft_ulen(num), flg);
	else if ((flg->width == 0 || flg->width < flg->press) && flg->press > 0)
		ft_filler('0', flg->press - ft_ulen(num), flg);
	ft_nbr(num, flg);
}

void	ft_utoi(unsigned int num, t_flg_stc *flg)
{
	if (flg->press == 0 && num == 0)
	{
		ft_filler (' ', flg->width, flg);
		return ;
	}
	if (flg->mns == 1)
		ft_utoi_mns(num, flg);
	else if (flg->zro == 1)
		ft_utoi_zro(num, flg);
	else if (flg->mns == 0 && flg->zro == 0
		&& (flg->width >= 0 || flg->press >= 0))
		ft_utoi_base(num, flg);
	else
		ft_nbr(num, flg);
}
