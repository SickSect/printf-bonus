#ifndef PRINTF_H
#define PRINTF_H

#define HEX "0123456789abcdef"
#define HEX_X "0123456789ABCDEF"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void ft_bzero(void *s, size_t n);
void ft_string(char *str,int *bytes);
void ft_putchar(int c, int *bytes);
void ft_digit(int n, int *bytes);
int ft_printf(const char *, ...);
void ft_linker(va_list arg,char type,int *bytes);
void ft_unsigned(unsigned int n,int *bytes);
void ft_hex(unsigned long int n, int *bytes);
void ft_hex_X(unsigned long int n, int *bytes);
void ft_void_pointer(void *ptr, int *bytes);


#endif
