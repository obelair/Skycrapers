/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:11:30 by obelair           #+#    #+#             */
/*   Updated: 2021/07/29 23:07:44 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

void	pre_fill_cell(t_sky *sky, int cell, int value)
{
	int	row;
	int	col;

	row = cell / sky->size;
	col = cell % sky->size;
	if (!sky->cur.map[row][col])
	{
		sky->cur.map[row][col] = value;
		sky->cur.nb_left[value - 1]--;
	}
}

void	pre_fill_col(t_sky *sky, int col)
{
	int	i;

	i = 0;
	if (sky->clues.top[col] == sky->size || sky->clues.bot[col] == sky->size)
	{
		while (i < sky->size)
		{
			if (sky->clues.top[col] == sky->size)
				pre_fill_cell(sky, i * sky->size + col, i + 1);
			else
				pre_fill_cell(sky, i * sky->size + col, sky->size - i);
			i++;
		}
	}
	else if (sky->clues.top[col] == 1)
	{
		pre_fill_cell(sky, col, sky->size);
		if (sky->clues.bot[col] == 2)
			pre_fill_cell(sky, sky->size * (sky->size - 1) + col, sky->size - 1);
	}
	else if (sky->clues.bot[col] == 1)
	{
		pre_fill_cell(sky, sky->size * (sky->size - 1) + col, sky->size);
		if (sky->clues.top[col] == 2)
			pre_fill_cell(sky, col, sky->size - 1);
	}
	else if (sky->clues.top[col] + sky->clues.bot[col] == sky->size + 1)
		pre_fill_cell(sky, (sky->clues.top[col] - 1) * sky->size + col, sky->size);
}

void	pre_fill_row(t_sky *sky, int row)
{
	int	i;

	i = 0;
	if (sky->clues.left[row] == sky->size || sky->clues.right[row] == sky->size)
	{
		while (i < sky->size)
		{
			if (sky->clues.left[row] == sky->size)
				pre_fill_cell(sky, row * sky->size + i, i + 1);
			else
				pre_fill_cell(sky, row * sky->size + i, sky->size - i);
			i++;
		}
	}
	else if (sky->clues.left[row] == 1)
	{
		pre_fill_cell(sky, row * sky->size, sky->size);
		if (sky->clues.right[row] == 2)
			pre_fill_cell(sky, sky->size * row + (sky->size - 1), sky->size - 1);
	}
	else if (sky->clues.right[row] == 1)
	{
		pre_fill_cell(sky, sky->size * row + (sky->size - 1), sky->size);
		if (sky->clues.left[row] == 2)
			pre_fill_cell(sky, row * sky->size, sky->size - 1);
	}
	else if (sky->clues.left[row] + sky->clues.right[row] == sky->size + 1)
		pre_fill_cell(sky, row * sky->size + (sky->clues.left[row] - 1), sky->size);
}

void	fill_last_row(t_sky *sky, int size, int row)
{
	int	i;
	int	col;
	int	value;

	value = 0;
	col = -1;
	i = 0;
	while (i < size && (!value || col == -1))
	{
		if (!ft_count(sky->cur.map[row], i + 1, size) && !value)
			value = i + 1;
		if (!sky->cur.map[row][i] && col == -1)
			col = i;
		i++;
	}
	pre_fill_cell(sky, row * size + col, value);
}

void	fill_last_col(t_sky *sky, int size, int col)
{
	int	i;
	int	row;
	int	value;

	value = 0;
	row = -1;
	i = 0;
	while (i < size && (!value || row == -1))
	{
		if (!ft_count_col(sky->cur.map, i + 1, size, col) && !value)
			value = i + 1;
		if (!sky->cur.map[i][col] && row == -1)
			row = i;
		i++;
	}
	pre_fill_cell(sky, row * size + col, value);
}

void	pre_fill(t_sky *sky)
{
	int	i;
	int	j;

	i = 0;
	while (i < sky->size)
	{
		pre_fill_col(sky, i);
		pre_fill_row(sky, i);
		i++;
	}
	while (--i >= 0)
	{
		j = i;
		while (j >= 0)
		{
			if (sky->cur.nb_left[j] == 1)
				find_last(sky, j + 1);
			j--;
		}
		while (++j < sky->size)
		{
			if (ft_count(sky->cur.map[j], 0, sky->size) == 1)
				fill_last_row(sky, sky->size, j);
			if (ft_count_col(sky->cur.map, 0, sky->size, j) == 1)
				fill_last_col(sky, sky->size, j);
		}
	}
}
