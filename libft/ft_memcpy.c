/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:36:53 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/14 14:51:20 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (dst == src || n == 0)
		return (dst);
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (n-- > 0)
		*(pdst++) = *(psrc++);
	return (dst);
}
