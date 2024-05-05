/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:35:48 by rmei              #+#    #+#             */
/*   Updated: 2024/05/05 20:29:02 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Iterates a singly-linked list and applies 'f' on the content of each node.
 * Returns a new singly-linked list with the result, or NULL. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*node;

	lst2 = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&lst2, del);
			break ;
		}
		ft_lstadd_back(&lst2, node);
		lst = lst->next;
	}
	return (lst2);
}