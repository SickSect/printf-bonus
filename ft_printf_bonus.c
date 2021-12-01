#include "ft_printf_bonus.h"

void ft_catch_flg (int *bytes,flg_stc *flg, const char *str,int pos)
{
  int i;
  int cycle;
  char *width;

  i = pos;
  cycle = 0;
  width = ft_strdup("\0");
  // check flags
  while(cycle == 0)
  {
    if(str[i] == '-')
      flg->flg_mns = '1';
    else if(str[i] == '+')
      flg->flg_pls = '1';
    else if(str[i] == '#')
      flg->flg_okt = '1';
    else if(str[i] == ' ')
      flg->flg_spc = '1';
    else if (str[i] == '0')
      flg->flg_zro = '1';
    else
      cycle = 1;
    i++;
    (*bytes)++;
  }
  cycle = 0;
  while(cycle == 0)
  {
        if(str[i] >= 49 && str[i] <= 57)
        {

        }
        else
        {

        }
  }


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
      ft_catch_flg (&bytes, &flg, stroke, i);
    }
    else
      ft_putchar(stroke[i]);
    i++;
  }
  printf("\nFLAGS : MNS %c PLS %c OKT %c SPC %c ZRO %c\n",
  flg.flg_mns,flg.flg_pls,flg.flg_okt,flg.flg_spc,flg.flg_zro);
  va_end(arg);
  return(bytes);
}
