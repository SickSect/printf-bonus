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

void	ft_putchar(int c, t_flg_stc *flg)
{
	write (1, &c, 1);
	flg->bytes++;
}

void	ft_putstr(char *s, int p, t_flg_stc *flg)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < p)
	{
		ft_putchar(s[i], flg);
		i++;
	}
}

int	ft_char(int ch, t_flg_stc *flg)
{
	if (flg->mns == 1)
	{
		ft_putchar(ch, flg);
		ft_filler(' ', flg->width - 1, flg);
	}
	else
	{
		ft_filler(' ', flg->width - 1, flg);
		ft_putchar(ch, flg);
	}
	return (0);
}
