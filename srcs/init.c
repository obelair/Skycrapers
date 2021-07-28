/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:32:04 by obelair           #+#    #+#             */
/*   Updated: 2021/07/28 16:04:59 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	init_struct(t_sky *sky)
{
	int	i;

	i = 0;
	sky->nb_sol = 0;
	sky->list_sol = NULL;
	sky->cur.nb_left = ft_calloc(sky->size, sizeof(int));
	if (ft_lstadd_void(&sky->list, sky->cur.nb_left, 0))
		return (printf("Init\n"));
	sky->cur.map = ft_calloc(sky->size, sizeof(int *));
	if (ft_lstadd_void(&sky->list, sky->cur.map, 0))
		return (printf("Init\n"));
	while (i < sky->size)
	{
		sky->cur.nb_left[i] = sky->size;
		sky->cur.map[i] = ft_calloc(sky->size, sizeof(int));
		if (ft_lstadd_void(&sky->list, sky->cur.map[i], 0))
			return (printf("Init\n"));
		i++;
	}
	if (ft_lstadd_dbl(&sky->list, (void **)sky->cur.map, sky->size, 0))
		return (printf("Init\n"));
	return (0);
}
