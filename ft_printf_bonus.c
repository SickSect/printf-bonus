#include "ft_printf_bonus.h"

int ft_flagger(flg_stc *flg, const char *str, int cycle)
{
  while(cycle == 0)
  {
    if(str[flg->id] == '-' && flg->mns == 0)
      flg->mns += 1;
    else if(str[flg->id] == '+' && flg->pls == 0)
      flg->pls += 1;
    else if(str[flg->id] == '#' && flg->okt == 0)
      flg->okt += 1;
    else if(str[flg->id] == ' ' && flg->spc == 0)
      flg->spc += 1;
    else if (str[flg->id] == '0' && flg->zro == 0)
      flg->zro += 1;
    else
      cycle = 1;
    flg->id += 1;
  }
  flg->id -= 1;
  return (0);
}

int ft_catch_flg(va_list arg,flg_stc *flg, const char *str)
{
  ft_flagger(flg, str, 0);
  if((ft_check_errflg(flg)) == 1)
    return (1);
  ft_catch_width(arg, flg, str);
  if(str[flg->id] == '-')
    return(1);
  ft_catch_press(arg, flg, str);
  flg->type = ft_find_type(str[flg->id]);
  if (flg->type == 'Q')
    return (1);
  return (0);
}

void  ft_linker(flg_stc *flg)
{
  if (flg->type == 'd' || flg->type == 'i')
    ft_digit(va_arg(flg->arg, int), flg);
  else if (flg->type == 'c')
    ft_char(va_arg(flg->arg, int), flg);
  else if (flg->type == 's')
    ft_string(va_arg(flg->arg, char *), flg);
  else if (flg->type == 'p')
    ft_void_pointer(va_arg(flg->arg, void *), flg, "0123456789abcdef");
  else if (flg->type == 'u')
    ft_utoi(va_arg(flg->arg, unsigned int), flg);
  else if (flg->type == 'x')
    ft_htoi(va_arg(flg->arg, unsigned int), flg, "0123456789abcdef0x");
  else if (flg->type == 'X')
    ft_htoi(va_arg(flg->arg, unsigned int), flg, "0123456789ABCDEF0X");
  else if (flg->type == '%')
    ft_putchar('%', flg);
}

int ft_printf(const char *stroke, ...)
{
  flg_stc *flg;
  long     bytes;
  int check;

  check = 0;
  flg = malloc(sizeof(flg_stc));
  va_start (flg->arg,stroke);
  flg->id = 0;
  flg->bytes = 0;
  while(stroke[flg->id] != '\0')
  {
    if(stroke[flg->id] == '%' && stroke[++flg->id])
    {
      ft_bzero_flg(flg);
      check = ft_catch_flg(flg->arg, flg, stroke);
      if (check == 0)
        ft_linker(flg);
      else
        {
          free (flg);
          return (0);
        }
    }
    else
      ft_putchar(stroke[flg->id],flg);
    flg->id++;
  }
  bytes = flg->bytes;
  va_end(flg->arg);
  free(flg);
  return(bytes);
}
