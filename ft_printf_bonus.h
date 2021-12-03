#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# ifndef TYPER
#  define TYPER "dscuxXp"
# endif

struct flg_stc
{
  _Bool flg_mns;
  _Bool flg_okt;
  _Bool flg_spc;
  _Bool flg_pls;
  _Bool flg_zro;
  int   width;
  int   press;
  char type;
}; typedef struct flg_stc flg_stc;

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int main();
void	ft_putchar(char c,int *bytes);
int ft_printf(const char *str, ...);

char	*ft_strjoin_char(char *s1, char s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str_s);
int	ft_atoi(const char *str);
int	ft_strlen(const char *str);
void	ft_bzero(void *dest, size_t n);
void	ft_bzero_char(void *dest, size_t n);
void	ft_putnbr_fd(int n, int *bytes);

int ft_catch_flgs(flg_stc *flg, const char str);
int ft_catch_wp(const char *str, int *pos);
char ft_find_type(const char str);
void ft_catch_flg(va_list arg,flg_stc *flg, const char *str, int *pos);
void ft_bzero_flg(flg_stc *flg);
void ft_correct_flg(flg_stc *flg);

void ft_digit(int n, int *bytes,flg_stc *flg);
char	*ft_itoa(int n);


#endif
