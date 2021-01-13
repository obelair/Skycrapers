/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:28:10 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_str.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!(n[i]))
		return ((char *)h);
	while (i < len && h[i])
	{
		j = 0;
		if (h[i] == n[j])
			while (h[i + j] == n[j] && i + j < len && h[i + j] && n[j])
				j++;
		if (!(n[j]))
			return ((char *)&h[i]);
		i++;
	}
	return (0);
}
