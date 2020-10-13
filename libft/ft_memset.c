/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:27:17 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/11 13:24:40 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *c_b;

	c_b = (unsigned char *)b;
	while (len > 0)
	{
		*c_b = (unsigned char)c;
		len--;
		c_b++;
	}
	return (b);
}
