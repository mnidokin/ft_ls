/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:36:08 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/16 18:45:06 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *head, size_t nbr)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	if (!tmp)
		return (head);
	i = 0;
	while (tmp->next && i++ < nbr)
		tmp = tmp->next;
	if (i == nbr)
	{
		head = tmp;
		return (head);
	}
	else if (i != nbr && !tmp->next)
		return (tmp->next);
	return (head);
}
