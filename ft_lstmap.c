/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:26:02 by lbalderr          #+#    #+#             */
/*   Updated: 2026/06/01 11:07:05 by lbalderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(t_list **lst, void (*del)(void *), void *content)
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

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
		if (!new_content)
			return (ft_free_all(&mapped_list, del, NULL));
		mapped_node = ft_lstnew(new_content);
		if (!mapped_node)
			return (ft_free_all(&mapped_list, del, new_content));
		ft_lstadd_back(&mapped_list, mapped_node);
		lst = lst->next;
	}
	return (mapped_list);
}
