#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct	flg_stc
{
	va_list		arg;
	int			id;
	int			mns;
	int			okt;
	int			spc;
	int			pls;
	int			zro;
	int			width;
	int			press;
	char		type;
	long int	bytes;
};
typedef struct flg_stc	flg_stc;
int		ft_printf(const char *stroke, ...);
int		ft_catch_wp(const char *str, flg_stc *flg);
char	ft_find_type(const char str);
void	ft_bzero_flg(flg_stc *flg);
int		ft_ulen(unsigned int n);
int		ft_xlen(unsigned long int n);
void	ft_catch_width(va_list arg, flg_stc *flg, const char *str);
void	ft_catch_press(va_list arg, flg_stc *flg, const char *str);
void	ft_putchar(int c, flg_stc *flg);
int		ft_atoi(const char *str);
void	ft_putstr(char *s, int p, flg_stc *flg);
char	*ft_strdup(const char *str_s);
char	*ft_strjoin_char(char *s1, char s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
void	ft_putnbr(long n, flg_stc *flg);
void	ft_bzero(void *dest, size_t n);
void	ft_nbr(unsigned int n, flg_stc *flg);
void	ft_htoi(unsigned int num, flg_stc *flg, char *base);
void	ft_OX(char *str, flg_stc *flg);
int		ft_isdigit(int ch);
void	ft_digit(long int n, flg_stc *flg);
void	ft_output_sign(flg_stc *flg, long int n);
int		ft_if_sign(flg_stc *flg, long int n);
int		ft_char(int ch, flg_stc *flg);
int		ft_string(char *str, flg_stc *flg);
void	ft_filler(char fill, int counter, flg_stc *flg);
void	ft_ohex(unsigned long int n, flg_stc *flg, char *base);
void	ft_void_pointer(void *ptr, flg_stc *flg, char *base);
void	ft_utoi(unsigned int num, flg_stc *flg);
int		ft_numlen(long int n);
#endif
