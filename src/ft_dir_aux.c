/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:27:24 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:27:26 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dir_islast(t_dir *dir)
{
	t_dir *tmp;

	tmp = dir->next;
	while (tmp)
	{
		if (tmp->status == IS_DIR)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_dir	*ft_dir_revers(t_dir *dir)
{
	t_dir *next;
	t_dir *prev;
	t_dir *cur;

	prev = NULL;
	cur = dir;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	dir = prev;
	return (dir);
}

void	ft_dir_add(t_dir **dir, t_dir *new)
{
	t_dir *head;
	t_dir *tmp;

	tmp = *dir;
	head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*dir = head;
}
