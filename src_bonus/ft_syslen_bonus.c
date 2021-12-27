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

static int	ft_moder(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr(long n, t_flg_stc *flg)
{
	char	str[13];
	int		neg;
	long	i;

	i = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	ft_bzero(str, 13);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i] = '0' + ft_moder(n % 10);
		n /= 10;
		i++;
	}
	if (neg < 0)
		str[i] = '-';
	else
		i--;
	while (i >= 0)
		ft_putchar(str[i--], flg);
}

int	ft_numlen(long int n)
{
	int	len;
	int	num;

	if (n < 0)
		num = n * -1;
	else
		num = n;
	len = 0;
	while (num / 10)
	{
		len++;
		num /= 10;
	}
	return (len + 1);
}

int	ft_xlen(unsigned long int n)
{
	int					len;
	unsigned long int	num;

	num = n;
	len = 0;
	while (num / 16 != 0)
	{
		len++;
		num /= 16;
	}
	return (len + 1);
}

int	ft_ulen(unsigned int n)
{
	int				len;
	unsigned int	num;

	num = n;
	len = 0;
	while (num / 10 != 0)
	{
		len++;
		num /= 10;
	}
	return (len + 1);
}
