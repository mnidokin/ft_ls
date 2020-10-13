/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:20:49 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/17 13:34:08 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	bord;
	unsigned long	res;
	int				flag;

	flag = 1;
	res = 0;
	bord = (unsigned long)(FT_LONG / 10);
	while (*str && (*str == ' ' || *str == '\f' || *str == '\t' ||
				*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	flag = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((res > bord || (res == bord && (*str - 48) > 7)) && flag == 1)
			return (-1);
		else if ((res > bord || (res == bord && (*str - 48) > 8)) && flag == -1)
			return (0);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * flag);
}
