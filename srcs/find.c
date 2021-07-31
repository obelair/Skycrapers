/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:08:53 by obelair           #+#    #+#             */
/*   Updated: 2021/07/31 14:27:52 by obelair          ###   ########lyon.fr   */
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

int	find_answer(t_sky *sky, int position)
{
	int	row;
	int	col;
	int	i;

	if (position == sky->size * sky->size)
		return (1);
	row = position / sky->size;
	col = position % sky->size;
	if (sky->cur.map[row][col])
		return (find_answer(sky, position + 1));
	i = 1;
	while (i <= sky->size)
	{
		if (!is_in_row(sky->cur.map, i, row, sky->size)
			&& !is_in_col(sky->cur.map, i, col, sky->size))
		{
			sky->cur.map[row][col] = i;
			if (check_views(sky, position))
			{
				if (find_answer(sky, position + 1))
					return (1);
			}
		}
		i++;
	}
	sky->cur.map[row][col] = 0;
	return (0);
}
