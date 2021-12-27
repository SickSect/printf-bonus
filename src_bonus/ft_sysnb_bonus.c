#include "ft_printf_bonus.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = '0';
		i++;
	}
}

void	ft_bzero_char(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = '\0';
		i++;
	}
}

static int	ft_whiler(const char *str, int neg, int i)
{
	long	res;
	int		max;

	max = 0;
	res = 0;
	while (str[i] != '\0' && ft_isdigit((char)str[i]))
	{
		res = (res * 10) + (str[i++] - '0');
		max++;
	}
	if (max > 19)
	{
		if (neg == 1)
			return (0);
		return (-1);
	}
	if (neg == 1)
		return (-1 * res);
	return (res);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\r'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		i++;
		neg = 1;
	}
	else if (str[i] == '+')
		i++;
	res = ft_whiler(str, neg, i);
	return (res);
}

int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}
