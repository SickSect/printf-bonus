#include "ft_printf_bonus.h"
#include <limits.h>

int main()
{
      void *ptr;
      int a = 10;
      ptr = &a;
      printf(" %|-4p| ", 17);
      /*
      printf("2 |%18.16p|\n", ptr);
      printf("3 |%16.p|\n", ptr);
      printf("4 |%16p|\n", ptr);

      printf("5 |%-16.18p|\n", ptr);
      printf("6 |%-18.16p|\n", ptr);
      printf("7 |%-16.p|\n", ptr);
      printf("8 |%-16p|\n", ptr);

      printf("9 |%016.18p|\n", ptr);
      printf("10|%018.16p|\n", ptr);
      printf("11|%016.p|\n", ptr);
      printf("12|%016p|\n", ptr);

      printf("13|%20.25p|\n", ptr);
      printf("14|%25.20p|\n", ptr);
      printf("15|%-20.25p|\n", ptr);
      printf("16|%-25.20p|\n", ptr);
      printf("17|%20p|\n", ptr);
      printf("18|%25p|\n", ptr);

      printf("19|%-20p|\n", ptr);
      printf("20|%-25p|\n", ptr);
      printf("21|%-20.p|\n", ptr);
      printf("22|%-25.p|\n", ptr);
      */
      /*
    ft_printf(" 1|%06d|\n",-123);
    printf(" 1|%06d|\n",-123);  //-00123

    ft_printf(" 2|%-6.4d| |%-4.6d| |%-+6d| |% -6d|\n",-123,-123, 123, 123);
    printf(" 2|%-6.4d| |%-4.6d| |%-+6d| |% -6d|\n",-123,-123, 123, 123); //-123  |123  |

    ft_printf(" 3|%6.d|\n",-123);
    printf(" 3|%6.d|\n",-123);//  -123|

    ft_printf(" 4|%6.8d| |%8.6d|\n",-123, -123);
    printf(" 4|%6.8d| |%8.6d|\n",-123, -123); //-00000123|

    ft_printf(" 4.1 |%-6.8d|\n",-123);
    printf(" 4.1 |%-6.8d|\n",-123);    //     -123|

    ft_printf(" 5|%8.d|\n",-123);
    printf(" 5|%8.d|\n",-123);

    ft_printf(" 6|%-8.6d| |%8.6d| |%08d|\n",-123, -123, -123);
    printf(" 6|%-8.6d| |%8.6d| |%08d|\n",-123, -123, -123);

    ft_printf(" 7|%0d|\n",-123);
    printf(" 7|%0d|\n",-123);

    ft_printf(" 8|%-d|\n",-123);
    printf(" 8|%-d|\n",-123);
    */
  //printf("\n%#x\n",123);
  //printf("\n   %+010.10d\n",123);
  return(0);
}
