/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:06:38 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/26 14:28:12 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(sizeof(char) * total_size);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, total_size);
	ft_strlcat(joined_str, s2, total_size);
	return (joined_str);
}
