/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_printf_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:56:29 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:56:31 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_pr_notdir(t_dir *tmp)
{
	if (tmp->self->nonprint_flag)
	{
		ft_putstr(tmp->self->dname);
		if (tmp->next)
			ft_putchar(' ');
	}
	else
	{
		ft_putstr(tmp->self->name);
		if (tmp->next)
			ft_putchar(' ');
	}
}

void	ft_pr_total(t_flags flag, t_file *tmp_file, t_dir *tmp)
{
	char *tmp_str;

	if ((flag & LONG_LISTING_FLAG) && tmp_file && tmp->valid_files)
	{
		ft_putstr("total ");
		tmp_str = ft_itoa(tmp->total_blocks);
		ft_putstr(tmp_str);
		ft_strdel(&tmp_str);
		ft_putchar('\n');
	}
}

int		ft_pr_unr_nonex(t_file *tmp_file)
{
	if (tmp_file->status == IS_UNREAD)
	{
		if (tmp_file->nonprint_flag)
			ft_error_unread(tmp_file->dname);
		else
			ft_error_unread(tmp_file->name);
		return (1);
	}
	else if (tmp_file->status == IS_NONEXIST)
	{
		if (tmp_file->nonprint_flag)
			ft_error_nonexist(tmp_file->dname);
		else
			ft_error_nonexist(tmp_file->name);
		return (1);
	}
	return (0);
}

void	ft_pr_nonll(t_file *tmp_file)
{
	if (tmp_file->nonprint_flag)
		ft_putstr(tmp_file->dname);
	else
		ft_putstr(tmp_file->name);
	if (tmp_file->next)
		ft_putchar(' ');
}

void	ft_pr_nondir(t_flags flag, t_file *tmp_file)
{
	if (ft_pr_unr_nonex(tmp_file))
		;
	else
	{
		if (flag & LONG_LISTING_FLAG)
			ft_not_printf_ll(tmp_file);
		else
			ft_pr_nonll(tmp_file);
	}
}
