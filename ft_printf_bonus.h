#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# ifndef TYPER
#  define TYPER "dscuxXp"
# endif

struct flg_stc
{
  t_bool flg_mns;
  t_bool flg_okt;
  t_bool flg_spc;
  t_bool flg_pls;
  t_bool flg_zro;
  int   width;
  int   press;
  char *size;
  char type;
}; typedef struct flg_stc flg_stc;

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int main();
void	ft_putchar(char c);
int ft_printf(const char *str, ...);

char	*ft_strjoin(char *s1, char s2);
void ft_catch_flg(int *bytes,flg_stc *flg, const char *str, int *pos);
void ft_bzero_flg(flg_stc *flg);
char	*ft_strdup(const char *str_s);
int	ft_atoi(const char *str);
int	ft_strlen(const char *str);

int ft_catch_flgs(flg_stc *flg, char ch);
void ft_catch_flg(int *bytes,flg_stc *flg, const char *str,int *pos);
int ft_catch_press(flg_stc *flg, char *str, int *pos, int *bytes);
int ft_catch_width(flg_stc *flg, char *str, int *pos, int *bytes);

#endif
