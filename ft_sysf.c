#include "ft_printf_bonus.h"

int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
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

char	*ft_strdup(const char *str_s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(str_s) + 1));
	if (!str)
		return (NULL);
	while (str_s[i])
	{
		str[i] = str_s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_putchar(char c,int *bytes)
{
	write (1, &c, 1);
	(*bytes)++;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * ((ft_strlen((char *)s1)) + 2));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	str[j++] = s2;
	str[j] = '\0';
	free (s1);
	return (str);
}
