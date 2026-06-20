/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:53:29 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/12 22:34:10 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_uint(va_arg(*args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), specifier));
	if (specifier == '%')
		return (ft_print_char('%'));
	ft_putchar_fd(specifier, 1);
	return (1);
}
