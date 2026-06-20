/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:24:46 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/12 22:34:33 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_dispatch(char specifier, va_list *args);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *p);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
int	ft_print_hex(unsigned int n, char sp);

#endif