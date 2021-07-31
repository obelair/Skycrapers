/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:14:09 by obelair           #+#    #+#             */
/*   Updated: 2021/07/31 14:24:46 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	view_top(int **map, int col, int size)
{
	int	max;
	int	view;
	int	i;

	view = 0;
	max = 0;
	if (map[max][col])
		view++;
	i = max + 1;
	while (i < size)
	{
		if (map[max][col] < map[i][col])
		{
			view++;
			max = i;
		}
		i++;
	}
	return (view);
}

int	view_bot(int **map, int col, int size)
{
	int	max;
	int	view;
	int	i;

	view = 0;
	max = size - 1;
	if (map[max][col])
		view++;
	i = max - 1;
	while (i >= 0)
	{
		if (map[max][col] < map[i][col])
		{
			view++;
			max = i;
		}
		i--;
	}
	return (view);
}

int	view_left(int **map, int row, int size)
{
	int	max;
	int	view;
	int	i;

	view = 0;
	max = 0;
	if (map[row][max])
		view++;
	i = max + 1;
	while (i < size)
	{
		if (map[row][max] < map[row][i])
		{
			view++;
			max = i;
		}
		i++;
	}
	return (view);
}

int	view_right(int **map, int row, int size)
{
	int	max;
	int	view;
	int	i;

	view = 0;
	max = size - 1;
	if (map[row][max])
		view++;
	i = max - 1;
	while (i >= 0)
	{
		if (map[row][max] < map[row][i])
		{
			view++;
			max = i;
		}
		i--;
	}
	return (view);
}

int	check_views(t_sky *sky, int position)
{
	int	row;
	int	col;

	row = position / sky->size;
	col = position % sky->size;
	if (view_top(sky->cur.map, col, sky->size) <= sky->clues.top[col]
		&& view_left(sky->cur.map, row, sky->size) <= sky->clues.left[row])
	{
		if (col == sky->size - 1 && !(view_right(sky->cur.map, row, sky->size)
				<= sky->clues.right[row]))
			return (0);
		if (row == sky->size - 1
			&& !(view_bot(sky->cur.map, col, sky->size) <= sky->clues.bot[col]))
			return (0);
		return (1);
	}
	return (0);
}
