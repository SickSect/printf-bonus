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

void ft_hex(unsigned long int n,flg_stc *flg, char *base)
{
  if (n < 16)
  {
    ft_putchar(base[n], flg);
  }
  else
  {
    ft_hex(n / 16, flg, base);
    ft_putchar (base[n % 16], flg);
  }
}

int ft_len(unsigned long int n)
{
      
}

void ft_void_pointer(void *ptr, flg_stc *flg, char *base)
{
  unsigned long int adress;

  adress = (unsigned long int)ptr;
  if (!adress)
      ft_putstr("(null)", flg);
  else
  {
        if(flg->mns == 1)
        {
            if(flg->press <= 0)
            {
                  ft_putstr("0x", flg);
                  ft_hex(adress, flg, base);
                  ft_filler(' ',flg->width - ft_len(adress), flg);
            }
            else
            {
                  ft_putstr("0x", flg);
                  ft_filler('0',flg->press - ft_len(adress), flg);
                  ft_hex(adress, flg, base);
                  if(flg->press < flg->width)
                        ft_filler(' ', flg->width - flg->press - 2, flg);
            }
        }
        else
        {
             if(flg->press <= 0)
             {
                  ft_filler(' ', flg->width - ft_len(adress) - 2, flg);
                  ft_putstr("0x", flg);
                  ft_hex(adress, flg, base);
             }
             else
             {
                   ft_putstr("0x", flg);
                   ft_filler('0', flg->press - ft_len(adress), flg);
                   ft_hex(adress, flg, base);
                   if(flg->press < flg->width)
                        ft_filler(' ', flg->width - flg->press - 2, flg);

             }
        }
  }
}
