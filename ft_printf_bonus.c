#include "ft_printf_bonus.h"

void ft_catch_flg (int *bytes,flg_stc *flg, const char *str,int *pos)
{
  int cycle;
  char *width;

  cycle = 0;
  width = ft_strdup("\0");
  // check flags
  while(cycle == 0)
  {
    if(str[*pos] == '-')
      flg->flg_mns = '1';
    else if(str[*pos] == '+')
      flg->flg_pls = '1';
    else if(str[*pos] == '#')
      flg->flg_okt = '1';
    else if(str[*pos] == ' ')
      flg->flg_spc = '1';
    else if (str[*pos] == '0')
      flg->flg_zro = '1';
    else
      cycle = 1;
    (*pos)++;
    (*bytes)++;
  }
  (*pos)--;
  cycle = 0;
  while(cycle == 0)
  {
        if(str[*pos] >= 49 && str[*pos] <= 57)
        {
          width = ft_strjoin(width,str[*pos]);
          //printf("\nwrite width %s\n",width);
        }
        else
          cycle = 1;
      (*pos)++;
  }
  if(width)
    flg->width = atoi(width);
  else
    flg->width = 0;
  //printf("\nalready write width %d",flg->width);
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
    }
    else
      ft_putchar(stroke[i]);
    i++;
  }
  printf("\nFLAGS : MNS %c PLS %c OKT %c SPC %c ZRO %c\n Width: %d",
  flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro,flg.width);
  va_end(arg);
  ft_bzero_flg(&flg);
  return(bytes);
}
