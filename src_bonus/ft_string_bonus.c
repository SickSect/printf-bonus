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

void	ft_str_mns_cut(char *str, t_flg_stc *flg, int f_null)
{
	if (f_null != 1)
		ft_putstr(str, flg->press, flg);
	else if (f_null == 1)
	{
		ft_filler(' ', flg->width - flg->press, flg);
		if (flg->press > 6)
			ft_putstr(str, 6, flg);
		else
			ft_putstr(str, flg->press, flg);
	}
	ft_filler(' ', flg->width - flg->press, flg);
}

void	ft_str_mns(char *str, t_flg_stc *flg, int f_null)
{
	if (flg->press == -1)
	{
		ft_putstr(str, ft_strlen(str), flg);
		ft_filler(' ', flg->width - ft_strlen(str), flg);
	}
	else
	{
		if (flg->press < ft_strlen(str))
			ft_str_mns_cut(str, flg, f_null);
		else
		{
			ft_putstr(str, ft_strlen(str), flg);
			ft_filler(' ', flg->width - ft_strlen(str), flg);
		}
	}
}

void	ft_str_base(char *str, t_flg_stc *flg)
{
	if (flg->press == -1)
	{
		ft_filler(' ', flg->width - ft_strlen(str), flg);
		ft_putstr(str, ft_strlen(str), flg);
	}
	else
	{
		if (flg->press < ft_strlen(str))
		{
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

int	ft_string(char *str, t_flg_stc *flg)
{
	int	f_null;

	f_null = 0;
	if (!str)
	{
		f_null = 1;
		if (flg->mns == 1)
			ft_str_mns("(null)", flg, f_null);
		else
			ft_str_base("(null)", flg);
		return (0);
	}
	if (flg->mns == 1)
		ft_str_mns(str, flg, f_null);
	else
		ft_str_base(str, flg);
	return (0);
}
