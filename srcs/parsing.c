/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:20:03 by obelair           #+#    #+#             */
/*   Updated: 2021/07/28 16:25:50 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

static int	parsing_clue(t_list **list, int *int_clue, char *clues, int size)
{
	int	i;

	int_clue = ft_calloc(size / 2, sizeof(int));
	if (ft_lstadd_void(list, int_clue, 0))
		return (printf("Parsing1\n"));
	i = 0;
	while (clues[i] && i < size)
	{
		if (!ft_isdigit(clues[i]))
			return (printf("Parsing2\n"));
		int_clue[i / 2] = ft_atoi(clues + i);
		i++;
		if (clues[i] != ' ' && clues[i])
			return (printf("Parsing3\n"));
		i++;
	}
	if (!i)
		return (printf("Parsing4\n"));
	return (0);
}

int	parsing_data(t_sky *sky, char *clues)
{
	if (parsing_clue(&sky->list, sky->clues.top, clues, sky->size * 2)
		|| parsing_clue(&sky->list, sky->clues.bot,
			clues + (sky->size * 2), sky->size * 2)
		|| parsing_clue(&sky->list, sky->clues.left,
			clues + (sky->size * 4), sky->size * 2)
		|| parsing_clue(&sky->list, sky->clues.right,
			clues + (sky->size * 6), sky->size * 2))
		return (printf("Parsing\n"));
	return (0);
}
