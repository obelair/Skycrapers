/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:02:46 by obelair           #+#    #+#             */
/*   Updated: 2021/07/27 14:02:46 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYCRAPERS_H
# define SKYCRAPERS_H

# include <stdio.h>
# include "libft.h"

typedef struct s_current
{
	int	*nb_left;
	int	**map;
}	t_current;

typedef struct s_clues
{
	int	*top;
	int	*bot;
	int	*left;
	int	*right;
}	t_clues;

typedef struct s_soluce
{
	int	**result;
}	t_soluce;

typedef struct s_sky
{
	int			size;
	t_clues		clues;
	t_current	cur;
	int			nb_sol;
	t_soluce	*list_sol;
	t_list		*list;
}	t_sky;

int		arg_check(t_sky *sky, int ac, char **ag);
int		clues_check(t_sky *sky);

int		parsing_data(t_sky *sky, char *clues);

void	set_as_null(t_sky *sky);
int		init_current(t_sky *sky);

void	print_result(t_sky *sky, int **map, int size);

void	pre_fill_cell(t_sky *sky, int cell, int value);
void	pre_fill(t_sky *sky);

int		is_in_col(int **map, int value, int col, int size);
int		is_in_row(int **map, int value, int row, int size);
void	find_last(t_sky *sky, int value);
int		find_answer(t_sky *sky, int position);

int		check_views(t_sky *sky, int position);

int		ft_count(int *tab, int nb, int size);
int		ft_count_col(int **tab, int nb, int size, int col);

#endif