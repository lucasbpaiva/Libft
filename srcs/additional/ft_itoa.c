/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:22:58 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/27 14:09:28 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_digits(long num)
{
	size_t	digits;

	digits = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		digits++;
	}
	while (num > 0)
	{
		digits++;
		num = num / 10;
	}
	return (digits);
}

static void	ft_fill_result(long num, char *result, int *i)
{
	if (num < 0)
	{
		result[(*i)++] = '-';
		num *= -1;
	}
	if (num >= 10)
		ft_fill_result(num / 10, result, i);
	result[(*i)++] = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	size_t	digits;
	char	*result;

	num = (long)n;
	digits = ft_count_digits(num);
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	i = 0;
	ft_fill_result(num, result, &i);
	result[digits] = '\0';
	return (result);
}
