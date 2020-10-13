/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:25:03 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/11 16:42:25 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		flag;
	int		dig;

	flag = 0;
	if (n < 0)
		flag = 1;
	else if (n >= 0)
		flag = 0;
	len = ft_numlen(n, flag);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[len--] = '\0';
	while (len >= flag)
	{
		dig = n % 10;
		dig = FT_ABS(dig);
		res[len] = dig + '0';
		n = n / 10;
		len--;
	}
	if (flag)
		res[0] = '-';
	return (res);
}
