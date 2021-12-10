#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

struct flg_stc
{
  va_list arg;
  int id;
  int mns;
  int okt;
  int spc;
  int pls;
  int zro;
  int width;
  int press;
  char type;
  long int bytes;
}; typedef struct flg_stc flg_stc;

int ft_printf(const char *stroke, ...);

void ft_flagger(flg_stc *flg, const char *str);
int ft_catch_wp(const char *str, flg_stc *flg);
char ft_find_type(const char str);
void ft_bzero_flg(flg_stc *flg);

void	ft_putchar(int c,flg_stc *flg);
int	    ft_atoi(const char *str);
void	ft_putstr(char *s, flg_stc *flg);
char	*ft_strdup(const char *str_s);
char	*ft_strjoin_char(char *s1, char s2);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);
void	ft_putnbr(long n, flg_stc *flg);

void ft_digit(long int n, flg_stc *flg);
void ft_output_sign(flg_stc *flg, int n);
int ft_if_sign(flg_stc *flg, int n);

int ft_char(int ch, flg_stc *flg);
int ft_string(char *str, flg_stc *flg);
void ft_filler(char fill, int counter, flg_stc *flg);
void ft_hex(unsigned long int n,flg_stc *flg, char *base);
void ft_void_pointer(void *ptr, flg_stc *flg, char *base);
void ft_utoi(unsigned long int num,flg_stc *flg);


#endif
