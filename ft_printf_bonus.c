#include "ft_printf_bonus.h"

void ft_catch_flg(int *bytes,flg_stc *flg, const char *str,int *pos)
{
  char *width;
  char *press;

  width = ft_strdup("\0");
  press = ft_strdup("\0");
  // check flags
  while(ft_catch_flgs(flg,str[*pos]) == 0)
  {
      (*pos)++;
      (*bytes)++;
  }
  (*pos)++;
  flg->width = ft_catch_width(flg, str, pos, bytes);
  if(str[++(*pos) == '.'])
  {
    flg->press = ft_catch_press(flg, str, pos, bytes);
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
  printf("\nFLAGS : MNS %c PLS %c OKT %c SPC %c ZRO %c\n Width: %d",
  flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro,flg.width);
  va_end(arg);
  return(bytes);
}
