/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:46:32 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/12 17:42:14 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*p_s;
	size_t	i;

	if (!f || !s || !(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	p_s = (char *)s;
	i = 0;
	while (*p_s)
	{
		res[i] = f(*(p_s));
		i++;
		p_s++;
	}
	res[i] = '\0';
	return (res);
}
