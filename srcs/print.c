/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:31:26 by obelair           #+#    #+#             */
/*   Updated: 2021/07/28 23:04:55 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

void	print_result(t_sky *sky, int **map, int size)
{
	int	i;
	int	j;

	i = 0;
	printf(" |");
	while (i < size)
	{
		printf("%d|", sky->clues.top[i]);
		i++;
	}
	printf(" \n");
	i = 0;
	while (i < size)
	{
		j = 0;
		printf("%d|", sky->clues.left[i]);
		while (j < size - 1)
		{
			printf("%d ", map[i][j]);
			j++;
		}
		printf("%d|%d\n", map[i][j], sky->clues.right[i]);
		i++;
	}
	i = 0;
	printf(" |");
	while (i < size)
	{
		printf("%d|", sky->clues.bot[i]);
		i++;
	}
	printf(" \n");
}
