/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:13:43 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/12 22:35:05 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			printed_chars += ft_dispatch(*format, &args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
