#include "ft_printf_bonus.h"

int main()
{
    ft_printf(" 1|%06d|\n",-123);
    printf(" 1|%06d|\n",-123);

    ft_printf(" 2|%-6d|\n",-123);
    printf(" 2|%-6d|\n",-123);

    ft_printf(" 3|%6.d|\n",-123);
    printf(" 3|%6.d|\n",-123);

    ft_printf(" 4|%6.8d|\n",-123);
    printf(" 4|%6.8d|\n",-123);

    ft_printf(" 4.1 |%-6.8d|\n",-123);
    printf(" 4.1 |%-6.8d|\n",-123);

    ft_printf(" 5|%8.d|\n",-123);
    printf(" 5|%8.d|\n",-123);

    ft_printf(" 6|%-8.6d|\n",-123);
    printf(" 6|%-8.6d|\n",-123);

    ft_printf(" 7|%0d|\n",-123);
    printf(" 7|%0d|\n",-123);

    ft_printf(" 8|%-d|\n",-123);
    printf(" 8|%-d|\n",-123);

  //printf("\n%#x\n",123);
  //printf("\n   %+010.10d\n",123);
  return(0);
}
