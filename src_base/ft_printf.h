/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:13:12 by ugina             #+#    #+#             */
/*   Updated: 2021/10/16 20:17:11 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef HEX
#  define HEX "0123456789abcdef"
# endif
# ifndef HEX_X
#  define HEX_X "0123456789ABCDEF"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_bzero(void *s, size_t n);
void	ft_string(char *str, int *bytes);
void	ft_putchar(int c, int *bytes);
void	ft_digit(int n, int *bytes);
int		ft_printf(const char *, ...);
void	ft_linker(va_list arg, char type, int *bytes);
void	ft_unsigned(unsigned int n, int *bytes);
void	ft_hex(unsigned long int n, int *bytes);
void	ft_hex_x(unsigned long int n, int *bytes);
void	ft_void_pointer(void *ptr, int *bytes);

#endif
