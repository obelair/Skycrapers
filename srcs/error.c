/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:18:10 by obelair           #+#    #+#             */
/*   Updated: 2021/07/27 14:18:10 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	arg_check(t_sky *sky, int ac, char **ag)
{
	if (ac != 3)
		return (printf("Error\n"));
	sky->size = ft_atoi(ag[1]);
	if (9 < sky->size && sky->size < 3)
		return (printf("Error\n"));
	if ((int)ft_strlen(ag[2]) != sky->size * 8 - 1)
		return (printf("Error\n"));
	return (0);
}
