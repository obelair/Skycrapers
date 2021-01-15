/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:42:18 by obelair           #+#    #+#             */
/*   Updated: 2021/01/15 00:50:11 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_cmp.h"

int	ft_strisalpha(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && 'a' <= str[i] && str[i] < 'z')
		i++;
	if (!str || 'z' < str[i] || str[i] < 'a')
		return (1);
	return (0);
}