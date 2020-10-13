/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:48:41 by mnidokin          #+#    #+#             */
/*   Updated: 2020/02/14 12:48:46 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_pathjoin(char *p1, char *p2)
{
	char *tmp;
	char *res;

	res = NULL;
	if (!ft_strendswith(p1, "/"))
	{
		if (!(res = ft_strjoin(p1, "/")))
			exit(2);
		tmp = res;
		if (!(res = ft_strjoin(res, p2)))
			exit(2);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = res;
		if (!(res = ft_strjoin(p1, p2)))
			exit(2);
		ft_strdel(&tmp);
	}
	return (res);
}

char	*ft_path_to_obj_name(char *str)
{
	char	**objs;
	char	*res;
	int		i;

	if (!(objs = ft_strsplit(str, '/')))
		exit(2);
	i = -1;
	while (objs[++i])
	{
		if (!objs[i + 1])
		{
			if (!(res = ft_strdup(objs[i])))
				exit(2);
			ft_matrix_free(&objs);
			return (res);
		}
	}
	return (str);
}

int		ft_strendswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}

char	ft_file_objtype(int st_mode)
{
	if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else
		return ('-');
}

int		ft_file_islast(t_dir *file)
{
	t_dir *tmp;

	tmp = file->next;
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
