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
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct s_flg_stc
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
typedef struct s_flg_stc	t_flg_stc;
int		ft_printf(const char *stroke, ...);
int		ft_catch_wp(const char *str, t_flg_stc *flg);
char	ft_find_type(const char str);
void	ft_bzero_flg(t_flg_stc *flg);
int		ft_ulen(unsigned int n);
int		ft_xlen(unsigned long int n);
void	ft_catch_width(va_list arg, t_flg_stc *flg, const char *str);
void	ft_catch_press(va_list arg, t_flg_stc *flg, const char *str);
void	ft_putchar(int c, t_flg_stc *flg);
int		ft_atoi(const char *str);
void	ft_putstr(char *s, int p, t_flg_stc *flg);
char	*ft_strdup(const char *str_s);
char	*ft_strjoin_char(char *s1, char s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
void	ft_putnbr(long n, t_flg_stc *flg);
void	ft_bzero(void *dest, size_t n);
void	ft_nbr(unsigned int n, t_flg_stc *flg);
void	ft_htoi(unsigned int num, t_flg_stc *flg, char *base);
void	ft_ox(char *str, t_flg_stc *flg);
int		ft_isdigit(int ch);
void	ft_digit(long int n, t_flg_stc *flg);
void	ft_output_sign(t_flg_stc *flg, long int n);
int		ft_if_sign(t_flg_stc *flg, long int n);
int		ft_char(int ch, t_flg_stc *flg);
int		ft_string(char *str, t_flg_stc *flg);
void	ft_filler(char fill, int counter, t_flg_stc *flg);
void	ft_ohex(unsigned long int n, t_flg_stc *flg, char *base);
void	ft_void_pointer(void *ptr, t_flg_stc *flg, char *base);
void	ft_utoi(unsigned int num, t_flg_stc *flg);
int		ft_numlen(long int n);
#endif