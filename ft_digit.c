#include "ft_printf_bonus.h"

int ft_numlen(int n)
{
    int len;
    int num;

    if (n < 0)
        num = n * -1;
    else
        num = n;
    len = 0;
    while (num / 10)
    {
        len++;
        num /= 10;
    }
    return(len + 1);
}
void ft_putsign(flg_stc *flg, int n, char *sign)
{
    if (n < 0)
        *sign = '-';
    else
    {
        if (flg->flg_spc == 1)
            *sign = ' ';
        if (flg->flg_pls == 1)
            *sign = '+';
    }
}

void ft_digit(int n, int *bytes,flg_stc *flg)
{
    char sign;
    ft_putsign(flg, n, &sign);
    if(flg->press == -1)
    {
        if(flg->flg_mns == 1)
        {

        }
    }
    else if(flg->press >= 0)
    {

    }
    (void)n;
    (void)bytes;
    (void)flg;
    (void)sign;
}
