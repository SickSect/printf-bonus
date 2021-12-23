#include "ft_printf.h"

void ft_linker(va_list arg,char type, int *bytes)
{
  if (type == 'c')
    ft_putchar(va_arg(arg, int), bytes);
  else if (type == 's')
    ft_string(va_arg(arg,char *), bytes);
  else if(type == 'd' || type == 'i')
      ft_digit(va_arg(arg,int), bytes);
  else if (type == 'u')
    ft_unsigned(va_arg(arg,int),bytes);
  else if(type == '%')
    ft_putchar('%',bytes);
  else if (type == 'x')
    ft_hex(va_arg(arg,unsigned int),bytes);
  else if (type == 'X')
    ft_hex_X(va_arg(arg,unsigned int),bytes);
  else if (type == 'p')
    ft_void_pointer(va_arg(arg,void *),bytes);
}

int ft_printf(const char *stroke, ...)
{
  int i;
  int bytes;
  va_list arg;
  va_start (arg,stroke);

  i = 0;
  bytes = 0;
  while(stroke[i] != '\0')
  {
    if(stroke[i] == '%')
      ft_linker(arg,stroke[++i],&bytes);
    else
      ft_putchar(stroke[i],&bytes);
    i++;
  }
  va_end(arg);
  return(bytes);
}
