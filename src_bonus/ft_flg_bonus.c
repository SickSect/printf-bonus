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

void	ft_output_sign(t_flg_stc *flg, long int n)
{
	if (flg->pls == 1 && n >= 0)
		ft_putchar('+', flg);
	else if (flg->spc == 1 && n >= 0)
		ft_putchar(' ', flg);
	if (n < 0)
		ft_putchar('-', flg);
}

void	ft_bzero_flg(t_flg_stc *flg)
{
	flg->mns = 0;
	flg->pls = 0;
	flg->okt = 0;
	flg->spc = 0;
	flg->zro = 0;
	flg->width = -1;
	flg->press = -1;
	flg->type = '0';
}

int	ft_catch_wp(const char *str, t_flg_stc *flg)
{
	char	*size;
	int		ret;

	size = ft_strdup("\0");
	if (str[flg->id] <= '0' && str[flg->id] >= '9')
		return (0);
	while (str[flg->id] >= '0' && str[flg->id] <= '9')
	{
		size = ft_strjoin_char(size, str[flg->id]);
		flg->id += 1;
	}
	ret = ft_atoi(size);
	free(size);
	return (ret);
}

char	ft_find_type(const char str)
{
	if (str == 'd' || str == 's' || str == 'x'
		|| str == 'X' || str == 'i' || str == '%'
		|| str == 'u' || str == 'p' || str == 'c'
		|| str == '%')
		return (str);
	else
		return ('Q');
}
