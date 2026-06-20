/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:54:29 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:54 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_count(unsigned long long num, int *count)
{
	if (num >= 16)
		ft_puthex_count(num / 16, count);
	ft_putchar_fd(HEX_LOWER[num % 16], 1);
	*count += 1;
}

int	ft_print_ptr(void *p)
{
	unsigned long long	address;
	int					count;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long long)p;
	count = 2;
	ft_putstr_fd("0x", 1);
	ft_puthex_count(address, &count);
	return (count);
}
