/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_printf_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:56:29 by mnidokin          #+#    #+#             */
/*   Updated: 2020/09/21 11:56:31 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_pr_minor_major(t_file *file)
{
	ft_putstr(ft_itoa(file->major));
	ft_putstr(", ");
	ft_putstr(ft_itoa(file->minor));
	ft_putchar(' ');
}

void	ft_pr_size(t_file *file)
{
	char *tmp;

	tmp = ft_itoa(file->size);
	ft_putstr(tmp);
	free(tmp);
	ft_putchar(' ');
}

void	ft_pr_dt(t_file *file)
{
	ft_putstr(file->date.month);
	ft_putchar(' ');
	ft_putstr(file->date.day);
	ft_putchar(' ');
}

void	ft_pr_owner_group(t_file *file)
{
	ft_putchar(' ');
	ft_putstr(file->owner);
	ft_putchar(' ');
	ft_putstr(file->group);
	ft_putchar(' ');
}

void	ft_not_printf_date(t_date date)
{
	time_t				timer;
	unsigned long long	months;
	unsigned long long	time_cur;

	time(&timer);
	months = 15778476;
	time_cur = date.sec;
	if (time_cur <= (timer - months) || time_cur >= (timer + months))
		ft_putstr(date.year);
	else
	{
		ft_putstr(date.hour);
		ft_putstr(":");
		ft_putstr(date.minute);
	}
	ft_putchar(' ');
}
