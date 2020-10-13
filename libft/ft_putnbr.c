/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:05:34 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/13 17:11:17 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int ln;

	ln = (long int)n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln = FT_ABS(ln);
	}
	if (ln >= 10)
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
	else
		ft_putchar(ln + '0');
}
