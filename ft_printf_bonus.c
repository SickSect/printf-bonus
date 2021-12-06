#include "ft_printf_bonus.h"

int ft_catch_flg(va_list arg,flg_stc *flg, const char *str,int *pos)
{
  int cycle;

  cycle = 0;
  while(cycle == 0)
  {
      if(str[*pos] == '-')
        flg->flg_mns = 1;
      else if(str[*pos] == '+')
        flg->flg_pls = 1;
      else if(str[*pos] == '#')
        flg->flg_okt = 1;
      else if(str[*pos] == ' ')
        flg->flg_spc = 1;
      else if (str[*pos] == '0')
        flg->flg_zro = 1;
      else
        cycle = 1;
    (*pos)++;
  }

  (*pos)--;
  if (str[*pos] == '*')
  {
        flg->width = va_arg(arg,int);
        (*pos)++;
  }
  else
      flg->width = ft_catch_wp(str, pos);
  if(str[*pos] == '.')
  {
      flg->prs = ' ';
      if(str[++(*pos)] == '*')
      {
            flg->press = va_arg(arg,int);
            (*pos)++;
      }
        else
            flg->press = ft_catch_wp(str, pos);
  }
  flg->type = ft_find_type(str[*pos]);
  //printf("TYPE %c\n",flg->type);
  return (0);
}

void ft_output(va_list arg, flg_stc *flg, int *bytes)
{
    //printf("TYPE %c\n",flg->type);
    ft_digit(va_arg(arg,int),bytes, flg);
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
      //printf("\nMNS -%2d PLS -%2d OKT -%2d SPC -%2d ZRO -%2d W: %2d P: %2d B: %2d T: %c\n",
      //flg.flg_mns, flg.flg_pls, flg.flg_okt, flg.flg_spc, flg.flg_zro, flg.width, flg.press, bytes, flg.type);
      ft_output(arg, &flg, &bytes);
      ft_bzero_flg(&flg);
    }
    else
      ft_putchar(stroke[i],&bytes);
    i++;
  }
  va_end(arg);
  return(bytes);
}
