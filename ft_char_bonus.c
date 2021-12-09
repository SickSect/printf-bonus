#include "ft_printf_bonus.h"

int ft_char(int ch,flg_stc *flg)
{
    if(flg->mns == 1)
    {
        ft_putchar(ch, flg);
        ft_filler(' ', flg->width - 1, flg);
    }
    else
    {
        ft_filler(' ', flg->width - 1, flg);
        ft_putchar(ch, flg);
    }
    return(0);
}

int ft_string(char *str, flg_stc *flg)
{
    int len;

    if(flg->press == -1)
        len = ft_strlen(str);
    else
        len = flg->width - flg->press;
    if(flg->mns == 1)
    {
        ft_putstr(str, flg);
        ft_filler(' ', flg->width - len, flg);
    }
    else
    {
        ft_filler(' ', flg->width - len, flg);
        ft_putstr(str, flg);
    }
    return(0);
}
