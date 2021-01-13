/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:16:27 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 14:11:22 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_str.h"

size_t	ft_strlen(const char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (1);
	return (ft_strlen(str + 1) + 1);
}