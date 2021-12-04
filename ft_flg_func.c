#include "ft_printf_bonus.h"

void ft_bzero_flg(flg_stc *flg)
{
      flg->flg_mns = 0;
      flg->flg_pls = 0;
      flg->flg_okt = 0;
      flg->flg_spc = 0;
      flg->flg_zro = 0;
      flg->width = 0;
      flg->press = -1;
      flg->type = '0';
      flg->prs = '0';
}      

int ft_catch_wp(const char *str, int *pos)
{
    char *size;

    size = ft_strdup("\0");
    if(str[*pos] <= 48 && str[*pos] >= 57)
        return (0);
    while(str[*pos] >= 48 && str[*pos] <= 57)
    {
        size= ft_strjoin_char(size,str[*pos]);
        (*pos)++;
    }
    return (atoi(size));
}

char ft_find_type(const char str)
{
      if(str == 'd' || str == 's' || str == 'x'
      || str == 'X' || str == 'i' || str == '%'
      || str == 'u' || str == 'p')
            return (str);
      else
            return ('Q');
}
