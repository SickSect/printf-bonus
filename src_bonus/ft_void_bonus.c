#include "ft_printf_bonus.h"

void ft_void_null(flg_stc *flg)
{
  if(flg->mns == 1)
    {
      ft_putstr("(nil)", 5, flg); // MAKE NULL
      if(flg->press > flg->width)
        ft_filler(' ', flg->press - flg->width - 6, flg);
      else
        ft_filler(' ', flg->width - flg->press - 6, flg);
      return ;
    }
    else
    {
      if(flg->press > flg->width)
        ft_filler(' ', flg->press - flg->width - 6, flg);
      else
        ft_filler(' ', flg->width - flg->press - 6, flg);
      ft_putstr("(nil)", 5, flg); // MAKE NULL
      return ;
    }
}

void ft_void_mns(unsigned long int adress, flg_stc *flg, char *base)
{
    if(flg->press <= 0)
    {
        ft_putstr("0x", 2, flg);
        ft_ohex(adress, flg, base);
        ft_filler(' ',flg->width - ft_xlen(adress) - 2, flg); 
    }
    else
    {
        ft_putstr("0x", 2,flg);
        ft_filler('0',flg->press - ft_xlen(adress), flg);
        ft_ohex(adress, flg, base);
        if(flg->press < flg->width)
            ft_filler(' ', flg->width - flg->press - 2, flg);  
    }
}

void ft_void_base(unsigned long int adress, flg_stc *flg, char *base)
{

    if(flg->press <= 0)
    {
        ft_filler(' ', flg->width - ft_xlen(adress) - 2, flg);
        ft_putstr("0x", 2, flg);
        ft_ohex(adress, flg, base);
    }
    else
    {
        ft_putstr("0x", 2, flg);
        ft_filler('0', flg->press - ft_xlen(adress), flg);
        ft_ohex(adress, flg, base);
        if(flg->press < flg->width)
            ft_filler(' ', flg->width - flg->press - 2, flg);
    }
}

void ft_void_pointer(void *ptr, flg_stc *flg, char *base)
{
  unsigned long int adress;

  adress = (unsigned long int)ptr;
  if (!adress)
    ft_void_null(flg);
  else
  {
    if(flg->mns == 1)
      ft_void_mns(adress, flg, base);
    else
      ft_void_base(adress, flg, base);
  }
}
