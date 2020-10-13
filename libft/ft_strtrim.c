/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:42 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/13 13:40:37 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	len_tmp;
	size_t	len_res;
	size_t	start;

	if (!s)
		return (NULL);
	len_res = 0;
	start = 0;
	if ((len_tmp = ft_strlen(s)) == (size_t)(-1))
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (len_tmp && (s[len_tmp - 1] == ' ' ||
				s[len_tmp - 1] == '\n' || s[len_tmp - 1] == '\t'))
		len_tmp--;
	if (!(res = ft_strnew((len_tmp > start) ? len_tmp - start : 0)))
		return (res);
	while (start < len_tmp)
		res[len_res++] = s[start++];
	res[len_res] = '\0';
	return (res);
}
