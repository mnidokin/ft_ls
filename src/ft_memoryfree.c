/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memoryfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:54:35 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:54:36 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_free(t_file **file)
{
	t_file *next;

	while (*file)
	{
		next = (*file)->next;
		ft_strdel(&((*file)->name));
		ft_strdel(&((*file)->dname));
		ft_strdel(&((*file)->modes));
		ft_strdel(&((*file)->owner));
		ft_strdel(&((*file)->group));
		ft_strdel(&((*file)->date.day));
		ft_strdel(&((*file)->date.month));
		ft_strdel(&((*file)->date.hour));
		ft_strdel(&((*file)->date.minute));
		ft_strdel(&((*file)->date.year));
		ft_strdel(&((*file)->link_name));
		ft_memdel((void **)file);
		*file = next;
	}
}

void	ft_dir_free(t_dir **dir)
{
	t_dir *next;

	while (*dir)
	{
		next = (*dir)->next;
		if ((*dir)->sub_dirs)
		{
			ft_strdel(&((*dir)->sub_dirs->dname));
			ft_strdel(&((*dir)->sub_dirs->name));
		}
		ft_strdel(&((*dir)->name));
		if ((*dir)->dname)
			ft_strdel(&(*dir)->dname);
		ft_file_free(&((*dir)->files));
		ft_file_free(&((*dir)->self));
		ft_memdel((void **)dir);
		*dir = next;
	}
}

t_dir	*ft_dir_mall(char *path)
{
	t_dir *dir;

	if (!(dir = (t_dir*)ft_memalloc(sizeof(t_dir))))
		exit(2);
	if (!(dir->name = ft_strdup(path)))
		exit(2);
	if (!(dir->self = (t_file*)ft_memalloc(sizeof(t_file))))
		exit(2);
	if (!(dir->self->name = ft_strdup(path)))
		exit(2);
	return (dir);
}

void	ft_matrix_free(char ***mat)
{
	int i;

	i = 0;
	while ((*mat)[i])
	{
		free((*mat)[i]);
		i++;
	}
	free(*mat);
}
