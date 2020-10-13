/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:53:22 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/14 18:22:04 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	wc(const char *str, char c)
{
	size_t res;

	res = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			res++;
			while (*str && *str != c)
				str++;
		}
	}
	return (res);
}

static size_t	word_len(const char *str, char c)
{
	size_t res;

	res = 0;
	while (*str == c)
		str++;
	while (*str && *str != c)
	{
		res++;
		str++;
	}
	return (res);
}

static void		free_arr(char **str, size_t res)
{
	while (res--)
		ft_strdel(&str[res]);
	free(*str);
}

static char		**word_write(char *str, char c)
{
	char	**res;
	int		row;
	size_t	col;
	size_t	wc_res;

	wc_res = wc(str, c);
	row = -1;
	if (!str || !(res = (char **)malloc(sizeof(char *) * (wc_res + 1))))
		return (NULL);
	while (++row < (int)wc_res)
	{
		if (!(res[row] = (char *)malloc(sizeof(char) * (word_len(str, c)))))
		{
			free_arr(res, row);
			return (NULL);
		}
		col = 0;
		while (*str == c)
			str++;
		while (*str && *str != c)
			res[row][col++] = *str++;
		res[row][col] = '\0';
	}
	res[row] = NULL;
	return (res);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**res;

	if (!str || !c)
		return (NULL);
	res = word_write((char *)str, c);
	return (res);
}
