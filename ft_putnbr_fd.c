/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:58:52 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/27 22:10:03 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd("-", fd);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr_fd((int)(num / 10), fd);
	ft_putchar_fd((num % 10) + '0', fd);
}
