/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:08:53 by obelair           #+#    #+#             */
/*   Updated: 2021/07/29 20:23:55 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	is_in_col(int **map, int value, int col, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[i][col] == value)
			return (1);
		i++;
	}
	return (0);
}

int	is_in_row(int **map, int value, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[row][i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	find_last(t_sky *sky, int value)
{
	int	row;
	int	col;
	int	find;

	row = 0;
	find = 1;
	while (row < sky->size && find)
	{
		if (!is_in_row(sky->cur.map, value, row, sky->size))
			find = 0;
		else
			row++;
	}
	col = 0;
	find = 1;
	while (col < sky->size && find)
	{
		if (!is_in_col(sky->cur.map, value, col, sky->size))
			find = 0;
		else
			col++;
	}
	pre_fill_cell(sky, row * sky->size + col, value);
}
