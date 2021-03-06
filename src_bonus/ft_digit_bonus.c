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

int	ft_if_sign(t_flg_stc *flg, long int n)
{
	if (flg->pls == 1 && n > 0)
		return (1);
	else if (flg->spc == 1 && n > 0)
		return (1);
	else if (n < 0)
		return (1);
	return (0);
}

void	ft_digit_mns(long int n, t_flg_stc *flg)
{
	ft_output_sign(flg, n);
	ft_filler('0', flg->press - ft_numlen(n), flg);
	if (n > 0)
		ft_putnbr(n, flg);
	else
		ft_putnbr(n * -1, flg);
	if (flg->width > flg->press && flg->press > ft_numlen(n))
		ft_filler(' ', flg->width - flg->press - ft_if_sign(flg, n), flg);
	else if (flg->width > flg->press && flg->press <= ft_numlen(n))
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	else if (flg->press == -1 || flg->press == 0)
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
}

void	ft_digit_zro(long int n, t_flg_stc *flg)
{
	if (flg->press > 0 && flg->press < ft_numlen(n))
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	else if (flg->width > flg->press && flg->press > 0
		&& flg->width > ft_numlen(n) + ft_if_sign(flg, n))
		ft_filler(' ', flg->width - flg->press - ft_if_sign(flg, n), flg);
	else if (flg->width > flg->press && flg->press == 0
		&& flg->width > ft_numlen(n) + ft_if_sign(flg, n))
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	ft_output_sign(flg, n);
	if (flg->press > 0)
		ft_filler('0', flg->press - ft_numlen(n), flg);
	else if (flg->press < 0)
		ft_filler('0', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	if (n > 0)
		ft_putnbr(n, flg);
	else
		ft_putnbr(n * -1, flg);
}

void	ft_digit_base(long int n, t_flg_stc *flg)
{
	if (flg->width > flg->press && flg->press > ft_numlen(n))
		ft_filler(' ', flg->width - flg->press - ft_if_sign(flg, n), flg);
	else if (flg->width > flg->press && flg->press <= ft_numlen(n))
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	else if (flg->press == -1 || flg->press == 0)
		ft_filler(' ', flg->width - ft_numlen(n) - ft_if_sign(flg, n), flg);
	ft_output_sign(flg, n);
	if (flg->press > 0)
		ft_filler('0', flg->press - ft_numlen(n), flg);
	if (n > 0)
		ft_putnbr(n, flg);
	else
		ft_putnbr(n * -1, flg);
}

void	ft_digit(long int n, t_flg_stc *flg)
{
	if (n == 0 && flg->press == 0)
	{
		ft_filler(' ', flg->width, flg);
		return ;
	}
	if (flg->mns == 1)
		ft_digit_mns(n, flg);
	else if (flg->zro == 1)
		ft_digit_zro(n, flg);
	else if (flg->zro == 0 && flg->mns == 0)
		ft_digit_base(n, flg);
	else
	{
		ft_output_sign(flg, n);
		if (n > 0)
			ft_putnbr(n, flg);
		else
			ft_putnbr(n * -1, flg);
	}
}
