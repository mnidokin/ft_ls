/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:36:30 by mnidokin          #+#    #+#             */
/*   Updated: 2020/08/25 14:36:35 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int		i;
	t_dir	*dir;
	t_flags	flag;

	(void)ac;
	i = 0;
	i = ft_flag(av + 1, &flag);
	dir = ft_dir(av + i, flag);
	ft_not_printf(flag, dir);
	ft_dir_free(&dir);
	exit(0);
}
