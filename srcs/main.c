/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:14:11 by obelair           #+#    #+#             */
/*   Updated: 2021/07/27 14:14:11 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapers.h"

int	main(int ac, char **ag)
{
	t_sky	sky;

	if (arg_check(&sky, ac, ag))
		return (EXIT_FAILURE);
	if (parsing_data(&sky, ag[2]))
		return (EXIT_FAILURE);
	if (init_struct(&sky))
		return (EXIT_FAILURE);
	/*
	- Error System
	- Parsing
	- Init Data
	- Backtracking
	- Print
	*/
	print_result(sky.cur.map, sky.size);
	ft_lstclear(&sky.list, free);
	return (EXIT_SUCCESS);
}
