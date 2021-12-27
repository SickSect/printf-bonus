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
#include "ft_printf.h"

void	ft_hex(unsigned long int n, int *bytes)
{
	if (n < 16)
	{
		ft_putchar(HEX[n], bytes);
	}
	else
	{
		ft_hex(n / 16, bytes);
		ft_putchar (HEX[n % 16], bytes);
	}
}

void	ft_hex_x(unsigned long int n, int *bytes)
{
	if (n < 16)
	{
		ft_putchar(HEX_X[n], bytes);
	}
	else
	{
		ft_hex_x(n / 16, bytes);
		ft_putchar (HEX_X[n % 16], bytes);
	}
}

void	ft_string(char *str, int *bytes)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_string("(null)", bytes);
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], bytes);
			i++;
		}
	}
}

void	ft_void_pointer(void *ptr, int *bytes)
{
	unsigned long int	adress;

	adress = (unsigned long int)ptr;
	if (!adress)
	{
		write (1, "0x0", 3);
		(*bytes) += 3;
	}
	else
	{
		write(1, "0x", 2);
		(*bytes) += 2;
		ft_hex(adress, bytes);
	}
}

void	ft_unsigned(unsigned int n, int *bytes)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_unsigned(num, bytes);
	}
	if (num > 9 || num < -9)
	{
		ft_unsigned(num / 10, bytes);
		ft_unsigned(num % 10, bytes);
	}
	else
	{
		ft_putchar('0' + num, bytes);
	}
}
