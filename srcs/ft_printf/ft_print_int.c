/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:54:40 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/10 23:10:44 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_count(long num, int *count)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		*count += 1;
	}
	if (num >= 10)
		ft_putnbr_count(num / 10, count);
	ft_putchar_fd((num % 10) + '0', 1);
	*count += 1;
}

int	ft_print_int(int n)
{
	int	count;

	count = 0;
	ft_putnbr_count((long)n, &count);
	return (count);
}
