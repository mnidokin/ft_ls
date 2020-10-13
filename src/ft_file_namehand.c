/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_namehand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:54:22 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:54:24 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_dname(struct dirent *dr, t_file **file)
{
	if (ft_file_nonprint(dr->d_name, ft_strlen(dr->d_name)))
	{
		(*file)->nonprint_flag = 1;
		(*file)->dname = ft_displname(dr->d_name, ft_strlen(dr->d_name));
	}
	if (!((*file)->name = ft_strdup(dr->d_name)))
		exit(2);
}

char	*ft_file_filename(t_file **cur, char *name_dir)
{
	char *file;
	char *tmp;

	file = NULL;
	if ((*cur)->is_dir_info)
	{
		if (!(file = ft_strdup((*cur)->name)))
			exit(2);
	}
	else
	{
		tmp = file;
		if (!(file = ft_pathjoin(name_dir, (*cur)->name)))
			exit(2);
		ft_strdel(&tmp);
	}
	return (file);
}

void	ft_file_unreadname(t_dir **dir)
{
	(*dir)->is_unread = 1;
	ft_strdel(&(*dir)->dname);
	if (!((*dir)->dname = ft_path_to_obj_name((*dir)->name)))
		exit(2);
}
