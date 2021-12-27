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

void	ft_catch_width(va_list arg, t_flg_stc *flg, const char *str)
{
	int	temp;

	if (str[flg->id] == '*')
	{
		temp = va_arg(arg, int);
		if (temp < 0)
		{
			flg->mns = 1;
			flg->width = temp * -1;
		}
		else
			flg->width = temp;
		flg->id += 1;
	}
	else
		flg->width = ft_catch_wp(str, flg);
}

void	ft_catch_press(va_list arg, t_flg_stc *flg, const char *str)
{
	int	temp;

	if (str[flg->id] == '.')
	{
		if (str[++flg->id] == '*')
		{
			temp = va_arg(arg, int);
			if (temp < -1)
				flg->press = -1;
			else
				flg->press = temp;
			flg->id += 1;
		}
		else
			flg->press = ft_catch_wp(str, flg);
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_ohex(unsigned long int n, t_flg_stc *flg, char *base)
{
	if (n < 16)
		ft_putchar(base[n], flg);
	else
	{
		ft_ohex(n / 16, flg, base);
		ft_putchar (base[n % 16], flg);
	}
}

void	ft_filler(char fill, int counter, t_flg_stc *flg)
{
	int	i;

	if (counter <= 0)
		return ;
	i = 0;
	while (i < counter)
	{
		ft_putchar(fill, flg);
		i++;
	}
}
