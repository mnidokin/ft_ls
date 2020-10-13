/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:12:37 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:12:39 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_file(t_dir *dir, t_flags flag)
{
	DIR				*dir_dir;
	t_file			*file;
	t_file			**tmp;
	struct dirent	*dr;

	file = NULL;
	tmp = &file;
	if (!(dir_dir = opendir(dir->name)))
	{
		ft_file_unreadname(&dir);
		return (NULL);
	}
	while ((dr = readdir(dir_dir)))
	{
		if (!(flag & ALL_FLAG) && dr->d_name[0] == '.')
			continue;
		if (!((*tmp) = (t_file *)ft_memalloc(sizeof(t_file))))
			exit(2);
		ft_file_dname(dr, tmp);
		ft_file_add(tmp, &dir, flag);
		tmp = &((*tmp)->next);
	}
	closedir(dir_dir);
	ft_file_mergesort(&file, flag);
	return (file);
}

void	ft_file_add(t_file **cur, t_dir **dir, t_flags flag)
{
	char	*file;
	char	*dir_name;

	if (!(dir_name = ft_strdup((*dir)->name)))
		exit(2);
	file = NULL;
	file = ft_file_filename(cur, dir_name);
	if (ft_error_lstat(file, cur))
		return ;
	(*dir)->valid_files = 1;
	if (!((*cur)->modes = ft_strnew(11)))
		exit(2);
	ft_file_stat(cur, *dir, file);
	free(file);
	if (!((*cur)->is_dir_info) && (flag & LONG_LISTING_FLAG))
		if ((*dir)->status == IS_DIR)
			(*dir)->total_blocks += (*cur)->file_info.st_blocks;
	if (S_ISDIR((*cur)->file_info.st_mode) && (flag & RECURSIVE_FLAG) &&
		!ft_strequ((*cur)->name, "..") && !ft_strequ((*cur)->name, "."))
	{
		file = ft_pathjoin(dir_name, (*cur)->name);
		ft_dir_av(file, &((*dir)->sub_dirs), (*cur)->name, flag);
		ft_strdel(&file);
	}
	ft_strdel(&dir_name);
}

t_file	*ft_file_revers(t_file *file)
{
	t_file *next;
	t_file *prev;
	t_file *cur;

	prev = NULL;
	cur = file;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	file = prev;
	return (file);
}

void	ft_file_nondir(t_dir **dir, t_flags flag)
{
	t_dir *tmp;

	tmp = *dir;
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
		{
			ft_file_add(&tmp->self, &tmp, flag);
		}
		tmp = tmp->next;
	}
}
