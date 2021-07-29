/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 23:21:17 by obelair           #+#    #+#             */
/*   Updated: 2021/07/29 22:58:09 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	ft_count(int *tab, int nb, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			count++;
		i++;
	}
	return (count);
}

int	ft_count_col(int **tab, int nb, int size, int col)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tab[i][col] == nb)
			count++;
		i++;
	}
	return (count);
}