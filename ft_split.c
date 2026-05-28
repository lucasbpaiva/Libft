/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:53:22 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/28 11:59:51 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 1;
	while (*s)
	{
		if (new_word && *s != c)
		{
			count++;
			new_word = 0;
		}
		if (*s == c)
			new_word = 1;
		s++;
	}
	return (count);
}

static int	ft_get_word_len(char const *s, char c, int *i)
{
	int	len;

	while (s[*i] && s[*i] == c)
		(*i)++;
	len = 0;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	return (len);
}

static void	*ft_free_all(char **result, int j)
{
	while (j >= 0)
		free(result[j--]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = ft_get_word_len(s, c, &i);
		if (len > 0)
		{
			result[j] = ft_substr(s, i, len);
			if (!result[j++])
				return (ft_free_all(result, j - 2));
			i += len;
		}
	}
	result[j] = NULL;
	return (result);
}
