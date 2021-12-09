#include "ft_printf_bonus.h"

void ft_catch_flg(va_list arg,flg_stc *flg, const char *str)
{
  ft_flagger(flg, str);
  if (str[flg->id] == '*')
  {
        flg->width = va_arg(arg,int);
        flg->id += 1;
  }
  else
      flg->width = ft_catch_wp(str,flg);
  if(str[flg->id] == '.')
  {
      if(str[++flg->id] == '*')
      {
            flg->press = va_arg(arg,int);
            flg->id += 1;
      }
        else
            flg->press = ft_catch_wp(str, flg);
  }
  flg->type = ft_find_type(str[flg->id]);
  //printf("%d %d %d %d %d %c\n", flg->zro, flg->mns, flg->spc, flg->okt, flg->pls, flg->type);
}

void ft_linker(flg_stc *flg)
{
  if(flg->type == 'd')
    ft_digit(va_arg(flg->arg, int), flg);
}

int ft_printf(const char *stroke, ...)
{
  flg_stc *flg;
  long bytes;

  flg = malloc(sizeof(flg_stc));
  va_start (flg->arg,stroke);
  flg->id = 0;
  flg->bytes = 0;
  while(stroke[flg->id] != '\0')
  {
    if(stroke[flg->id] == '%' && stroke[++flg->id])
    {
      ft_bzero_flg(flg);
      ft_catch_flg(flg->arg, flg, stroke);
      ft_linker(flg);
    }
    else
      ft_putchar(stroke[flg->id],flg);
    flg->id++;
  }
  bytes = flg->bytes;
  free(flg);
  va_end(flg->arg);
  //printf(" BYTES: %ld", flg->bytes);
  return(bytes);
}
