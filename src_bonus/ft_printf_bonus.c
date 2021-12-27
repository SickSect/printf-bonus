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

void	ft_flagger(t_flg_stc *flg, const char *str)
{
	int	cycle;

	cycle = 0;
	while (cycle == 0)
	{
		if (str[flg->id] == '-')
			flg->mns = 1;
		else if (str[flg->id] == '+')
			flg->pls = 1;
		else if (str[flg->id] == '#')
			flg->okt = 1;
		else if (str[flg->id] == ' ')
			flg->spc = 1;
		else if (str[flg->id] == '0')
			flg->zro = 1;
		else
			cycle = 1;
		flg->id += 1;
	}
	flg->id -= 1;
}

void	ft_catch_flg(va_list arg, t_flg_stc *flg, const char *str)
{
	ft_flagger(flg, str);
	ft_catch_width(arg, flg, str);
	ft_catch_press(arg, flg, str);
	flg->type = ft_find_type(str[flg->id]);
}

void	ft_linker(t_flg_stc *flg)
{
	if (flg->type == 'd' || flg->type == 'i')
		ft_digit(va_arg(flg->arg, int), flg);
	else if (flg->type == 'c')
		ft_char(va_arg(flg->arg, int), flg);
	else if (flg->type == 's')
		ft_string(va_arg(flg->arg, char *), flg);
	else if (flg->type == 'p')
		ft_void_pointer(va_arg(flg->arg, void *), flg, "0123456789abcdef");
	else if (flg->type == 'u')
		ft_utoi(va_arg(flg->arg, unsigned int), flg);
	else if (flg->type == 'x')
		ft_htoi(va_arg(flg->arg, unsigned int), flg, "0123456789abcdef0x");
	else if (flg->type == 'X')
		ft_htoi(va_arg(flg->arg, unsigned int), flg, "0123456789ABCDEF0X");
	else if (flg->type == '%')
		ft_putchar('%', flg);
}

int	ft_printf(const char *stroke, ...)
{
	t_flg_stc	*flg;
	long		bytes;

	flg = malloc(sizeof(t_flg_stc));
	if (!flg)
		return (0);
	va_start (flg->arg, stroke);
	flg->id = 0;
	flg->bytes = 0;
	while (stroke[flg->id] != '\0')
	{
		if (stroke[flg->id] == '%' && stroke[++flg->id])
		{
			ft_bzero_flg(flg);
			ft_catch_flg(flg->arg, flg, stroke);
			ft_linker(flg);
		}
		else
			ft_putchar(stroke[flg->id], flg);
		flg->id++;
	}
	bytes = flg->bytes;
	va_end(flg->arg);
	free(flg);
	return (bytes);
}
