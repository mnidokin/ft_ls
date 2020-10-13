/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:24:06 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/16 15:20:25 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_erase(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *cur;
	t_list *elem;

	head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(elem = f(lst)))
		{
			if (head)
				ft_lstdel(&head, &ft_erase);
			return (NULL);
		}
		if (!head)
		{
			head = elem;
			cur = head;
		}
		else
			ft_lstadd_back(&cur, elem);
		lst = lst->next;
	}
	return (head);
}
