/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:07:18 by ugina             #+#    #+#             */
/*   Updated: 2021/12/27 15:07:33 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	ft_void_null(t_flg_stc *flg)
{
	if (flg->mns == 1)
	{
		ft_putstr("0x0", 3, flg);
		if (flg->press > flg->width)
			ft_filler(' ', flg->press - flg->width - 4, flg);
		else
			ft_filler(' ', flg->width - flg->press - 4, flg);
		return ;
	}
	else
	{
		if (flg->press > flg->width)
			ft_filler(' ', flg->press - flg->width - 4, flg);
		else
			ft_filler(' ', flg->width - flg->press - 4, flg);
		ft_putstr("0x0", 3, flg);
		return ;
	}
}

void	ft_void_mns(unsigned long int adress, t_flg_stc *flg, char *base)
{
	if (flg->press <= 0)
	{
		ft_putstr("0x", 2, flg);
		ft_ohex(adress, flg, base);
		ft_filler(' ', flg->width - ft_xlen(adress) - 2, flg);
	}
	else
	{
		ft_putstr("0x", 2, flg);
		ft_filler('0', flg->press - ft_xlen(adress), flg);
		ft_ohex(adress, flg, base);
		if (flg->press < flg->width)
			ft_filler(' ', flg->width - flg->press - 2, flg);
	}
}

void	ft_void_base(unsigned long int adress, t_flg_stc *flg, char *base)
{
	if (flg->press <= 0)
	{
		ft_filler(' ', flg->width - ft_xlen(adress) - 2, flg);
		ft_putstr("0x", 2, flg);
		ft_ohex(adress, flg, base);
	}
	else
	{
		ft_putstr("0x", 2, flg);
		ft_filler('0', flg->press - ft_xlen(adress), flg);
		ft_ohex(adress, flg, base);
		if (flg->press < flg->width)
			ft_filler(' ', flg->width - flg->press - 2, flg);
	}
}

void	ft_void_pointer(void *ptr, t_flg_stc *flg, char *base)
{
	unsigned long int	adress;

	adress = (unsigned long int)ptr;
	if (!adress)
		ft_void_null(flg);
	else
	{
		if (flg->mns == 1)
			ft_void_mns(adress, flg, base);
		else
			ft_void_base(adress, flg, base);
	}
}
