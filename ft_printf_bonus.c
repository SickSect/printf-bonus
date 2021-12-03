#include "ft_printf_bonus.h"

void ft_catch_flg(va_list arg,flg_stc *flg, const char *str,int *pos)
{
  int cycle;

  cycle = 0;
  while(cycle == 0)
        cycle = ft_catch_flgs(flg, str[(*pos)++]);
  (*pos)--;
  if (str[*pos] == '*')
  {
        flg->width = va_arg(arg,int);
        (*pos)++;
  }
  else
      flg->width = ft_catch_wp(str, pos);
  if(str[(*pos)++] == '.')
  {
        if(str[*pos] == '*')
        {
            flg->press = va_arg(arg,int);
            (*pos)++;
        }
        else
            flg->press = ft_catch_wp(str, pos);
  }
  flg->type = ft_find_type(str[*pos]);
}

int ft_printf(const char *stroke, ...)
{
  int i;
  int bytes;
  va_list arg;
  flg_stc flg;
  va_start (arg,stroke);

  ft_bzero_flg(&flg);
  i = 0;
  bytes = 0;
  while(stroke[i] != '\0')
  {
    if(stroke[i] == '%')
    {
      i++;
      ft_catch_flg (arg, &flg, stroke, &i);
      printf("\nFLAGS : MNS %d PLS %d OKT %d SPC %d ZRO %d\n Width: %d Press: %d Bytes: %d Type: %c\n",
      flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro,flg.width,flg.press,bytes,flg.type);
      // обработка вывода
      ft_bzero_flg(&flg);
    }
    else
      ft_putchar(stroke[i],&bytes);
    i++;
  }
  //printf("\nCLEAR FLAGS : MNS %d PLS %d OKT %d SPC %d ZRO %d\n Width: %d Press: %d\n",
  //flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro,flg.width,flg.press);
  va_end(arg);
  return(bytes);
}
