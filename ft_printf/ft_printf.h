/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:20:37 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/16 15:49:40 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int ch);
int	ft_putnumber(int number, int count);
int	ft_putstr(char *s);
int	ft_print_ptr(unsigned long n, int firstCall, int number);
int	ft_print_hex(unsigned long n, char ch, int number);
int	ft_print_unsigned(unsigned int n, int number);
int	ft_printf(const char *format, ...);
#endif