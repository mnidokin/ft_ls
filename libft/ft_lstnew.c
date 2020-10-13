/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:45:01 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/16 13:55:08 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	if (!(node = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(node->content = ft_memalloc(content_size)))
		{
			free(node);
			return (NULL);
		}
		node->content = ft_memcpy(node->content,
				((const void *)content), content_size);
		node->content_size = content_size;
	}
	else if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	return (node);
}
