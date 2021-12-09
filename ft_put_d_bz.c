#include "ft_printf.h"

void ft_putchar(int c, int *bytes)
{
	write(1, &c, 1);
	(*bytes)++;
}

void ft_digit(int n, int *bytes)
{
	long num;

	num = n;
	if(num < 0)
	{
		num *= -1;
		ft_putchar('-',bytes);
	}
	if (num > 9)
	{
		ft_digit(num / 10, bytes);
		ft_digit(num % 10, bytes);
	}
	else
	{
		ft_putchar('0' + num, bytes);
	}
}

void ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = 0;
		i++;
	}
}
