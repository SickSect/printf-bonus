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

void ft_void_pointer(void *ptr, flg_stc *flg, char *base)
{
  unsigned long int adress;
  int len;

  adress = (unsigned long int)ptr;
  if (!adress)
    ft_string("(null)", flg);
  else
  {
    if(flg->mns == 1)
    {

    }
    else if (flg->zro == 1)
    {
      ft_putstr("0x", flg);
      if(flg->press > 0)
        ft_filler('0',)
    }
  }
}

void ft_hex(unsigned long int n, flg_stc *flg, char *base)
{
  if (n < 16)
{
  ft_putchar(base[n],bytes);
}
else
{
  ft_hex(n / 16, bytes);
  ft_putchar (base[n % 16], bytes);
}
}
