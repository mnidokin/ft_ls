/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:21:41 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:21:42 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_nonexist(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_error_unread(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

int		ft_error_lstat(char *file, t_file **cur)
{
	if (lstat(file, &(*cur)->file_info) < 0)
	{
		if (errno == ENOENT)
			(*cur)->status = IS_NONEXIST;
		else if (errno == EACCES)
			(*cur)->status = IS_UNREAD;
		return (1);
	}
	return (0);
}
