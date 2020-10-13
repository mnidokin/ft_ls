/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:23:12 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/16 17:03:24 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle)
		{
			j = 0;
			while (needle[j] && (haystack[i + j] == needle[j]) &&
					((i + j) < len))
				j++;
			if (needle[j] == '\0')
				return (((char *)&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
