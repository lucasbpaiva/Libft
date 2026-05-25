/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:55:57 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/25 11:19:06 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;

	if (!dest && !src)
		return (NULL);
	src_ptr = (unsigned char *)src;
	dst_ptr = (unsigned char *)dest;
	if (dst_ptr > src_ptr)
	{
		while (n > 0)
		{
			n--;
			dst_ptr[n] = src_ptr[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
