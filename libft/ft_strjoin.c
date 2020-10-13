/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:10:31 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/27 20:42:38 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		res = ft_strcpy(res, (char*)s1);
		res = ft_strcat(res, (char*)s2);
	}
	else if (s1 && !s2)
	{
		if (!(res = ft_strnew(ft_strlen(s1))))
			return (NULL);
		res = ft_strcpy(res, (char*)s1);
	}
	else if (!s1 && s2)
	{
		if (!(res = ft_strnew(ft_strlen(s2))))
			return (NULL);
		res = ft_strcpy(res, (char*)s2);
	}
	return (res);
}
