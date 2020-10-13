/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:31:47 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:31:48 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_stat(t_file **cur, t_dir *dir, char *file)
{
	struct stat	file_info;
	char		buf[1024];
	int			len;

	file_info = (*cur)->file_info;
	len = 0;
	ft_file_perm(cur, file_info);
	(*cur)->link = file_info.st_nlink;
	if (!((*cur)->owner = ft_strdup(getpwuid(file_info.st_uid)->pw_name)))
		exit(2);
	if (!((*cur)->group = ft_strdup(getgrgid(file_info.st_gid)->gr_name)))
		exit(2);
	(*cur)->user_id = (int)file_info.st_uid;
	(*cur)->group_id = (int)file_info.st_gid;
	(*cur)->size = file_info.st_size;
	if (S_ISCHR(file_info.st_mode) || S_ISBLK(file_info.st_mode))
		ft_file_chr_blk(cur, file_info, dir);
	if (S_ISLNK(file_info.st_mode))
		ft_file_lnk(cur, file, buf);
	ft_file_date(&((*cur)->date), file_info);
}

void	ft_file_chr_blk(t_file **cur, struct stat file_info, t_dir *dir)
{
	(*cur)->major = (long)major(file_info.st_rdev);
	(*cur)->minor = (long)minor(file_info.st_rdev);
	(*cur)->device_file_flag = 1;
	if (!(dir->device_file_flag_in))
		dir->device_file_flag_in = 1;
}

void	ft_file_lnk(t_file **cur, char *file, char *buf)
{
	int len;

	len = 0;
	(*cur)->link_file_flag = 1;
	if ((len = readlink(file, buf, 256)) < 0)
		exit(2);
	if (ft_file_nonprint(buf, len))
	{
		if (!((*cur)->link_name = ft_displname(buf, len)))
			exit(2);
	}
	else
	{
		if (!((*cur)->link_name = ft_strndup(buf, len)))
			exit(2);
	}
}

void	ft_file_perm(t_file **cur, struct stat file_info)
{
	(*cur)->modes[0] = ft_file_objtype(file_info.st_mode);
	(*cur)->modes[1] = (file_info.st_mode & S_IRUSR) ? 'r' : '-';
	(*cur)->modes[2] = (file_info.st_mode & S_IWUSR) ? 'w' : '-';
	(*cur)->modes[3] = (file_info.st_mode & S_IXUSR) ? 'x' : '-';
	(*cur)->modes[4] = (file_info.st_mode & S_IRGRP) ? 'r' : '-';
	(*cur)->modes[5] = (file_info.st_mode & S_IWGRP) ? 'w' : '-';
	(*cur)->modes[6] = (file_info.st_mode & S_IXGRP) ? 'x' : '-';
	(*cur)->modes[7] = (file_info.st_mode & S_IROTH) ? 'r' : '-';
	(*cur)->modes[8] = (file_info.st_mode & S_IWOTH) ? 'w' : '-';
	(*cur)->modes[9] = (file_info.st_mode & S_IXOTH) ? 'x' : '-';
	ft_file_perm_extra(cur, file_info);
}

void	ft_file_perm_extra(t_file **cur, struct stat file_info)
{
	if (file_info.st_mode & S_ISUID)
	{
		if ((*cur)->modes[3] == '-')
			(*cur)->modes[3] = 'S';
		else
			(*cur)->modes[3] = 's';
	}
	if (file_info.st_mode & S_ISGID)
	{
		if ((*cur)->modes[6] == '-')
			(*cur)->modes[6] = 'S';
		else
			(*cur)->modes[6] = 's';
	}
	if (file_info.st_mode & S_ISVTX)
	{
		if ((*cur)->modes[9] == '-')
			(*cur)->modes[9] = 'T';
		else
			(*cur)->modes[9] = 't';
	}
}
