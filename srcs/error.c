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

static int	sum_check(int *tab1, int *tab2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab1[i] + tab2[i] < 3 || tab1[i] + tab2[i] > size + 1)
			return (1);
		i++;
	}
	return (0);
}

int	clues_check(t_sky *sky)
{
	if (ft_count(sky->clues.top, 1, sky->size) > 1
		|| ft_count(sky->clues.top, sky->size, sky->size) > 1
		|| ft_count(sky->clues.bot, 1, sky->size) > 1
		|| ft_count(sky->clues.bot, sky->size, sky->size) > 1
		|| ft_count(sky->clues.left, 1, sky->size) > 1
		|| ft_count(sky->clues.left, sky->size, sky->size) > 1
		|| ft_count(sky->clues.right, 1, sky->size) > 1
		|| ft_count(sky->clues.right, sky->size, sky->size) > 1)
		return (printf("Clues\n"));
	if (sum_check(sky->clues.top, sky->clues.bot, sky->size)
		|| sum_check(sky->clues.left, sky->clues.right, sky->size))
		return (1);
	return (0);
}
