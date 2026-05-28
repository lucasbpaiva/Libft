/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:26:02 by lbalderr          #+#    #+#             */
/*   Updated: 2026/05/28 18:03:43 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*mapped_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	mapped_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		mapped_node = ft_lstnew(new_content);
		if (!mapped_node)
		{
			del(new_content);
			ft_lstclear(&mapped_list, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_list, mapped_node);
		lst = lst->next;
	}
	return (mapped_list);
}
