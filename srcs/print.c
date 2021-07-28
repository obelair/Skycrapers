/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:31:26 by obelair           #+#    #+#             */
/*   Updated: 2021/07/28 15:54:15 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

void	print_result(int **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			printf("%d ", map[i][j]);
			j++;
		}
		printf("%d\n", map[i][j]);
		i++;
	}
}
