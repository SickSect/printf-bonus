#include "ft_printf_bonus.h"

void ft_catch_flg(int *bytes,flg_stc *flg, const char *str,int *pos)
{
  int cycle;

  cycle = 0;
  while(cycle == 0)
  {
      cycle = ft_catch_flgs(flg, str[*pos]);
      (*pos)++;
      (*bytes)++;
  }
  (*pos)--;
  flg->width = ft_catch_width(str, pos, bytes);
  if(str[++(*pos) == '.'])
  {
    flg->press = ft_catch_press(str, pos, bytes);
    (*pos)++;
  }
  flg->type = ft_find_type(str[++(*pos)]);
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
      ft_catch_flg (&bytes, &flg, stroke, &i);
      // обработка вывода
      ft_bzero_flg(&flg);
    }
    else
      ft_putchar(stroke[i]);
    i++;
  }
  printf("\nFLAGS : MNS %d PLS %d OKT %d SPC %d ZRO %d\n Width: %d",
  flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro,flg.width);
  va_end(arg);
  return(bytes);
}
