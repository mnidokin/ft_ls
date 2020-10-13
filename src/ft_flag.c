/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:48:28 by mnidokin          #+#    #+#             */
/*   Updated: 2020/02/14 12:53:48 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flag(char **av, t_flags *flag)
{
	int i;

	i = -1;
	while (av[++i])
	{
		if (av[i][0] != '-')
			break ;
		if (ft_strequ(av[i], "--"))
		{
			i++;
			break ;
		}
		if (av[i][0] == '-' && av[i][1])
			ft_flag_check(av[i], flag);
		else
			break ;
	}
	return (i > 0 ? i + 1 : 1);
}

void	ft_flag_check(char *str, t_flags *flag)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'R')
			*flag |= RECURSIVE_FLAG;
		else if (str[i] == 'a' || str[i] == 'r' || str[i] == 't')
			ft_flag_set(str[i], flag);
		else if (str[i] == 'l')
			ft_flag_set(str[i], flag);
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(str[i], 2);
			ft_putstr_fd("\nusage: ls [-altRr] [file ...]\n", 2);
			exit(2);
		}
	}
}

void	ft_flag_set(char c, t_flags *flag)
{
	if (c == 'r')
		*flag |= REVERSE_FLAG;
	else if (c == 'a')
		*flag |= ALL_FLAG;
	else if (c == 't')
		*flag |= MODIFICATION_DATE_SORT;
	else if (c == 'l')
		*flag |= LONG_LISTING_FLAG;
}
