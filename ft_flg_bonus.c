#include "ft_printf_bonus.h"

void ft_output_sign(flg_stc *flg, long int n)
{
  if(flg->pls == 1 && n >= 0)
    ft_putchar('+', flg);
  else if(flg->spc == 1 && n >= 0)
    ft_putchar(' ', flg);
  if(n < 0)
    ft_putchar('-', flg);
}

int ft_check_errflg(flg_stc *flg)
{
  if(flg->mns > 1 || flg->pls > 1 || flg->zro > 1
    || flg->okt > 1 || flg->spc > 1)
    return (1);
  return (0);
}

void ft_bzero_flg(flg_stc *flg)
{
  flg->mns = 0;
  flg->pls = 0;
  flg->okt = 0;
  flg->spc = 0;
  flg->zro = 0;
  flg->width = -1;
  flg->press = -1;
  flg->type = '0';
}

int ft_catch_wp(const char *str, flg_stc *flg)
{
    char *size;
    int ret;

    size = ft_strdup("\0");
    /*
    if(str[str->id] == '-')
      flg->mns += 1;
      */
    if(str[flg->id] <= '0' && str[flg->id] >= '9')
      return (0);
    while(str[flg->id] >= '0' && str[flg->id] <= '9')
    {
      size= ft_strjoin_char(size,str[flg->id]);
      flg->id += 1;
    }
    ret = ft_atoi(size);
    free(size);
    return (ret);
}

char ft_find_type(const char str)
{
  if(str == 'd' || str == 's' || str == 'x'
    || str == 'X' || str == 'i' || str == '%'
    || str == 'u' || str == 'p' || str == 'c'
    || str == '%')
      return (str);
  else
    return ('Q');
}
