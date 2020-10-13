/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:02:14 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/09 16:14:46 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	size_t			count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i])
		i++;
	while (s2[j] && count < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
		count++;
	}
	s1[i] = '\0';
	return (s1);
}
