/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:23:52 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:23:53 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_dir_mergesort(t_dir **dir, t_flags flag)
{
	t_dir	*head;
	t_dir	*a;
	t_dir	*b;

	head = *dir;
	if (!head || !head->next)
		return ;
	ft_dir_listsplit(head, &a, &b);
	ft_dir_mergesort(&a, flag);
	ft_dir_mergesort(&b, flag);
	*dir = ft_dir_sortedmerge(a, b, flag);
}

void	ft_dir_listsplit(t_dir *source, t_dir **front, t_dir **back)
{
	t_dir	*fast;
	t_dir	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

t_dir	*ft_dir_sortedmerge(t_dir *a, t_dir *b, t_flags flag)
{
	t_dir *res;

	res = NULL;
	if (a == NULL)
	{
		return (b);
	}
	else if (b == NULL)
	{
		return (a);
	}
	if (ft_dir_sort_alpha(a, b, flag))
	{
		res = a;
		res->next = ft_dir_sortedmerge(a->next, b, flag);
	}
	else
	{
		res = b;
		res->next = ft_dir_sortedmerge(a, b->next, flag);
	}
	return (res);
}

int		ft_dir_sort_alpha(t_dir *a, t_dir *b, t_flags flag)
{
	int comp;

	comp = ft_strcmp(a->name, b->name) <= 0;
	if (flag & MODIFICATION_DATE_SORT)
	{
		comp = a->date.sec >= b->date.sec;
		if (a->date.sec == b->date.sec)
		{
			comp = a->date.nsec >= b->date.nsec;
			if (a->date.nsec == b->date.nsec)
				comp = ft_strcmp(a->name, b->name) < 0;
		}
	}
	return (comp);
}
