/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:54:44 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/11 15:12:32 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_uint_count(unsigned int num, int *count)
{
	if (num >= 10)
		ft_put_uint_count(num / 10, count);
	ft_putchar_fd((num % 10) + '0', 1);
	*count += 1;
}

int	ft_print_uint(unsigned int n)
{
	int	count;

	count = 0;
	ft_put_uint_count(n, &count);
	return (count);
}
