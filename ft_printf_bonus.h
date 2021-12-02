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

int ft_catch_flgs(flg_stc *flg, const char str);
void ft_catch_flg(int *bytes,flg_stc *flg, const char *str,int *pos);
int ft_catch_press(const char *str, int *pos, int *bytes);
int ft_catch_width(const char *str, int *pos, int *bytes);
char ft_find_type(const char str);

#endif
