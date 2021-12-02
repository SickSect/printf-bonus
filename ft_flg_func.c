#include "ft_printf_bonus.h"

void ft_bzero_flg(flg_stc *flg)
{
      flg->flg_mns = '0';
      flg->flg_pls = '0';
      flg->flg_okt = '0';
      flg->flg_spc = '0';
      flg->flg_zro = '0';
      flg->width = 0;
      flg->press = 0;
      flg->type = '0';
}

int ft_catch_flgs(flg_stc *flg, char ch)
{
      if(str[*pos] == '-')
        flg->flg_mns = 1;
      else if(str[*pos] == '+')
        flg->flg_pls = 1;
      else if(str[*pos] == '#')
        flg->flg_okt = 1;
      else if(str[*pos] == ' ')
        flg->flg_spc = 1;
      else if (str[*pos] == '0')
        flg->flg_zro = 1;
      else
        return (1);
    return (0);
}

int ft_catch_width(flg_stc *flg, char *str, int *pos, int *bytes)
{
    char *width;

    width = ft_strdup("\0");
    if(str[*pos] == '0')
        return (0);
    while(str[*pos] >= 48 && str[*pos] <= 57)
    {
        width = ft_strjoin(width,str[*pos++]);
        (*bytes)++;
    }
    return (atoi(width));
}

int ft_catch_press(flg_stc *flg, char *str, int *pos, int *bytes)
{
    char *press;

    press = ft_strdup("\0");
    if(str[*pos] == '0')
        return (0);
    while(str[*pos] >= 48 && str[*pos] <= 57)
    {
        press = ft_strjoin(press,str[*pos++]);
        (*bytes)++;
    }
    return (atoi(press));
}
