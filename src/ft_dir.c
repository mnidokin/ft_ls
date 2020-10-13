/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:23:57 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:23:59 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*ft_dir(char **av, t_flags flag)
{
	t_dir	*dir;
	int		i;
	int		*stat_def;

	i = -1;
	if (!(stat_def = (int*)malloc(sizeof(int) * 2)))
		exit(2);
	stat_def[0] = IS_DIR;
	stat_def[1] = 1;
	dir = ft_dir_new(".", 0, flag, stat_def);
	if (av[++i])
		ft_dir_free(&dir);
	i = -1;
	while (av[++i])
	{
		ft_dir_av(av[i], &dir, NULL, flag);
	}
	ft_dir_mergesort(&dir, flag);
	free(stat_def);
	return (dir);
}

t_dir	*ft_dir_new(char *path, char *sub_name, t_flags flag, int *stat_def)
{
	t_dir	*dir;
	DIR		*dir_cur;

	dir = ft_dir_mall(path);
	if (stat_def[0] == IS_LINK)
	{
		if (!(dir_cur = opendir(dir->name)) || flag & LONG_LISTING_FLAG)
			stat_def[0] = IS_NOTDIR;
		else
			stat_def[0] = IS_DIR;
		if (dir_cur)
			closedir(dir_cur);
	}
	dir->is_default = stat_def[1];
	ft_dir_init(dir, stat_def[0], path, sub_name);
	return (dir);
}

void	ft_dir_init(t_dir *dir, int stat, char *path, char *sub_name)
{
	struct stat file;

	if (stat != IS_NONEXIST)
	{
		lstat(dir->name, &file);
		dir->date.sec = (unsigned long long)file.st_mtime;
		dir->date.nsec = (unsigned long long)file.st_mtimespec.tv_nsec;
		if (!(dir->self->dname = ft_strdup(path)))
			exit(2);
		dir->self->is_dir_info = 1;
		if (sub_name)
			if (!(dir->dname = ft_strdup(sub_name)))
				exit(2);
	}
	dir->status = stat;
	dir->is_unread = 0;
	dir->total_blocks = 0;
	dir->next = NULL;
}

void	ft_dir_av(char *str, t_dir **dir, char *sub_name, t_flags flag)
{
	t_dir		*new;
	int			*stat;
	struct stat	file;

	if (!(stat = ft_memalloc(sizeof(int) * 2)))
		exit(2);
	stat[0] = IS_DIR;
	if (lstat(str, &file) == -1)
	{
		if (errno == 2)
			stat[0] = IS_NONEXIST;
	}
	else if (!S_ISDIR(file.st_mode))
		stat[0] = IS_NOTDIR;
	if (S_ISLNK(file.st_mode))
		stat[0] = IS_LINK;
	stat[1] = 0;
	new = ft_dir_new(str, sub_name, flag, stat);
	if (!*dir || (*dir)->is_default)
		*dir = new;
	else
		ft_dir_add(dir, new);
	free(stat);
}

t_dir	*ft_dir_subdir(t_dir *dir, t_dir **sub, t_flags flag)
{
	t_dir *tmp;

	if (!*sub)
		return (dir);
	ft_dir_mergesort(sub, flag);
	tmp = *sub;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = dir;
	return (*sub);
}
