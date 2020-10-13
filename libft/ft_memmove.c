/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:38:09 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/14 14:54:14 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_src;
	unsigned char	*p_dst;

	if (dst == src || len == 0)
		return (dst);
	i = 1;
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (p_src < p_dst)
	{
		while (i <= len)
		{
			p_dst[len - i] = p_src[len - i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			*(p_dst++) = *(p_src++);
	}
	return (dst);
}
