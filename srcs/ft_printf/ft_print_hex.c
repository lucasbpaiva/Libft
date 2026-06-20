/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:54:47 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/11 18:05:28 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_count(unsigned int num, int *count, char *hex)
{
	if (num >= 16)
		ft_puthex_count(num / 16, count, hex);
	ft_putchar_fd(hex[num % 16], 1);
	*count += 1;
}

int	ft_print_hex(unsigned int n, char sp)
{
	int		count;
	char	*hex;

	hex = HEX_LOWER;
	if (sp == 'X')
		hex = HEX_UPPER;
	count = 0;
	ft_puthex_count(n, &count, hex);
	return (count);
}
