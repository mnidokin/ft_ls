/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:58:33 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/11 13:02:26 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int num, int flag)
{
	int res;

	res = 1;
	while ((num = num / 10))
		res++;
	return (res + flag);
}