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

int		parsing_data(t_sky *sky, char *clues);

int		init_struct(t_sky *sky);

void	print_result(int **map, int size);

#endif