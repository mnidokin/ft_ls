/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:48:23 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 18:48:25 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_not_printf(t_flags flag, t_dir *dir)
{
	t_dir	*tmp;

	ft_not_prints_nonexist(dir);
	if (flag & REVERSE_FLAG)
		dir = ft_dir_revers(dir);
	ft_not_printf_nodir(dir, flag);
	tmp = dir;
	while (tmp)
	{
		if (tmp->status == IS_DIR)
		{
			tmp->files = ft_file(tmp, flag);
			if (flag & REVERSE_FLAG)
				tmp->files = ft_file_revers(tmp->files);
			ft_not_printf_dir(flag, dir, &tmp);
			tmp->next = ft_dir_subdir(tmp->next, &(tmp->sub_dirs), flag);
			if (!ft_dir_islast(tmp))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void	ft_not_printf_dir(t_flags flag, t_dir *dir, t_dir **tmp)
{
	t_file	*tmp_file;

	tmp_file = (*tmp)->files;
	if (dir->next)
	{
		ft_putstr((*tmp)->name);
		ft_putstr(":\n");
	}
	if ((*tmp)->is_unread)
	{
		ft_error_unread((*tmp)->dname);
		return ;
	}
	ft_pr_total(flag, tmp_file, *tmp);
	while (tmp_file)
	{
		ft_pr_nondir(flag, tmp_file);
		tmp_file = tmp_file->next;
	}
	if (!(flag & LONG_LISTING_FLAG))
		ft_putchar('\n');
}

void	ft_not_prints_nonexist(t_dir *dir)
{
	t_dir *tmp;

	tmp = dir;
	while (tmp)
	{
		if (tmp->status == IS_NONEXIST)
			ft_error_nonexist(tmp->name);
		tmp = tmp->next;
	}
}

void	ft_not_printf_nodir(t_dir *dir, t_flags flag)
{
	t_dir *tmp;

	ft_file_nondir(&dir, flag);
	tmp = dir;
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
		{
			if (flag & LONG_LISTING_FLAG)
				ft_not_printf_ll(tmp->self);
			else
				ft_pr_notdir(tmp);
			if (ft_file_islast(tmp))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void	ft_not_printf_ll(t_file *file)
{
	char *tmp;

	ft_putstr(file->modes);
	ft_putchar(' ');
	tmp = ft_itoa(file->link);
	ft_putstr(tmp);
	free(tmp);
	ft_pr_owner_group(file);
	if (file->device_file_flag)
		ft_pr_minor_major(file);
	else
		ft_pr_size(file);
	ft_pr_dt(file);
	ft_not_printf_date(file->date);
	ft_putstr(file->name);
	if (file->link_file_flag)
	{
		ft_putstr(" -> ");
		ft_putstr(file->link_name);
	}
	ft_putchar('\n');
}
