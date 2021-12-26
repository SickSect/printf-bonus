/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:13:12 by ugina             #+#    #+#             */
/*   Updated: 2021/10/16 20:17:11 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	ft_putchar(int c, flg_stc *flg)
{
	write (1, &c, 1);
	flg->bytes++;
}

void	ft_putstr(char *s, int p, flg_stc *flg)
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

int	ft_char(int ch, flg_stc *flg)
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
