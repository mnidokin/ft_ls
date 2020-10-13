/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <mnidokin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:33:43 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/26 19:33:45 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char(char const *s1, char c)
{
	int		i;
	char	*res;

	i = -1;
	if (!s1 || !c)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s1) + 2)))
		return (NULL);
	while (++i < (int)ft_strlen(s1))
		res[i] = s1[i];
	res[i] = c;
	res[++i] = '\0';
	return (res);
}
