#include "ft_printf_bonus.h"

void ft_flagger(flg_stc *flg, const char *str)
{
  int cycle;

  cycle = 0;
  while(cycle == 0)
  {
      if(str[flg->id] == '-')
        flg->mns = 1;
      else if(str[flg->id] == '+')
        flg->pls = 1;
      else if(str[flg->id] == '#')
        flg->okt = 1;
      else if(str[flg->id] == ' ')
        flg->spc = 1;
      else if (str[flg->id] == '0')
        flg->zro = 1;
      else
        cycle = 1;
    flg->id += 1;
  }
  flg->id -= 1;
}

void ft_bzero_flg(flg_stc *flg)
{
      flg->mns = 0;
      flg->pls = 0;
      flg->okt = 0;
      flg->spc = 0;
      flg->zro = 0;
      flg->width = 0;
      flg->press = -1;
      flg->type = '0';
}

int ft_catch_wp(const char *str, flg_stc *flg)
{
    char *size;
    int ret;

    size = ft_strdup("\0");
    if(str[flg->id] <= 48 && str[flg->id] >= 57)
        return (0);
    while(str[flg->id] >= 48 && str[flg->id] <= 57)
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
      || str == 'u' || str == 'p' || str == 'c')
            return (str);
      else
            return ('Q');
}
