/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:04:31 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:04:32 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_file_nonprint(char *str, int str_len)
{
	int i;

	i = -1;
	while (++i < str_len && str[i])
		if ((str[i] <= ' ') || (str[i] >= '~'))
			return (1);
	return (0);
}

char	*ft_displname(char *file_name, int len)
{
	char	*res;
	char	file_name_chr;
	int		i;

	if (!(res = ft_strnew(ft_strlen(file_name))))
		exit(2);
	i = -1;
	while (++i < len && file_name[i])
	{
		if ((file_name[i] <= ' ') || (file_name[i] >= '~'))
		{
			if (file_name[i] == '\r')
				file_name_chr = '?';
			else
				file_name_chr = ' ';
		}
		res[i] = file_name_chr;
	}
	return (res);
}

void	ft_file_date(t_date *file_date, struct stat file)
{
	time_t timer;

	file_date->sec = (unsigned long long)file.st_mtime;
	timer = file_date->sec;
	ft_file_date_parse(file_date, timer);
	file_date->nsec = (unsigned long long)file.st_mtimespec.tv_nsec;
}

void	ft_file_date_parse(t_date *file_date, time_t timer)
{
	char **time_matr;
	char **hh_mm_ss;

	if (!(time_matr = ft_strsplit(ctime(&timer), ' ')))
		exit(2);
	if (!(file_date->day = ft_strdup(time_matr[2])))
		exit(2);
	if (!(file_date->year = ft_strsub(time_matr[4], 0, 4)))
		exit(2);
	if (!(file_date->month = ft_strdup(time_matr[1])))
		exit(2);
	if (!(hh_mm_ss = ft_strsplit(time_matr[3], ':')))
		exit(2);
	if (!(file_date->hour = ft_strdup(hh_mm_ss[0])))
		exit(2);
	if (!(file_date->minute = ft_strdup(hh_mm_ss[1])))
		exit(2);
	ft_matrix_free(&hh_mm_ss);
	ft_matrix_free(&time_matr);
}
