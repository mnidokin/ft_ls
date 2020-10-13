/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:08:11 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/19 19:08:13 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_mergesort(t_file **file_list, t_flags flag)
{
	t_file *head;
	t_file *a;
	t_file *b;

	head = *file_list;
	if (!head || !head->next)
		return ;
	ft_file_split(head, &a, &b);
	ft_file_mergesort(&a, flag);
	ft_file_mergesort(&b, flag);
	*file_list = ft_file_merge(a, b, flag);
}

void	ft_file_split(t_file *src, t_file **front, t_file **back)
{
	t_file *fast;
	t_file *slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}

t_file	*ft_file_merge(t_file *a, t_file *b, t_flags flag)
{
	t_file *res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_file_sort(a, b, flag))
	{
		res = a;
		res->next = ft_file_merge(a->next, b, flag);
	}
	else
	{
		res = b;
		res->next = ft_file_merge(a, b->next, flag);
	}
	return (res);
}

int		ft_file_sort(t_file *a, t_file *b, t_flags flag)
{
	int cmp;

	cmp = ft_strcmp(a->name, b->name) <= 0;
	if (flag & MODIFICATION_DATE_SORT)
	{
		cmp = a->date.sec >= b->date.sec;
		if (a->date.sec == b->date.sec)
		{
			cmp = a->date.nsec >= b->date.nsec;
			if (a->date.nsec == b->date.nsec)
				cmp = ft_strcmp(a->name, b->name) < 0;
		}
	}
	return (cmp);
}
