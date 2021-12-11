#include "ft_printf_bonus.h"

void	ft_putstr(char *s, flg_stc *flg)
{
	size_t	i;
	size_t lb;

	if(flg->press > 0)
		lb = flg->press;
	else
		lb = ft_strlen(s);
	if (!s)
		return ;
	i = 0;
	while (s[i] && lb)
	{
		ft_putchar(s[i], flg);
		i++;
	}
}

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

void	ft_putchar(int c,flg_stc *flg)
{
	write (1, &c, 1);
	flg->bytes++;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_char(char *s1, char s2)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

static int	ft_moder(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr(long n, flg_stc *flg)
{
	char	str[13];
	int		neg;
	long		i;

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
	{
		ft_putchar(str[i], flg);
		i--;
	}
}

int ft_numlen(long int n)
{
    int len;
    int num;

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
    return(len + 1);
}
void ft_filler(char fill, int counter, flg_stc *flg)
{
  int i;
  if(counter <= 0)
      return ;
  i = 0;
  while (i < counter)
  {
    ft_putchar(fill, flg);
    i++;
  }
}
