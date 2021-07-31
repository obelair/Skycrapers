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

int	ft_exit(t_list **list, int exit)
{
	ft_lstclear(list, free);
	return (exit);
}

int	main(int ac, char **ag)
{
	t_sky	sky;
	int		i;

	sky.list = ft_lstnew(NULL);
	if (arg_check(&sky, ac, ag))
		return (ft_exit(&sky.list, EXIT_FAILURE));
	set_as_null(&sky);
	if (parsing_data(&sky, ag[2]) || clues_check(&sky))
		return (ft_exit(&sky.list, EXIT_FAILURE));
	if (init_current(&sky))
		return (ft_exit(&sky.list, EXIT_FAILURE));
	// printf("-------------------------------------\n");
	// printf("Hauteur tour \t| Nb restant a placer\n");
	// printf("-------------------------------------\n");
	// i = 0;
	// while (i < sky.size)
	// {
	// 	printf("\t%d\t|\t %d \t\n", i + 1, sky.cur.nb_left[i]);
	// 	i++;
	// }
	// printf("-------------------------------------\n");
	// print_result(&sky, sky.cur.map, sky.size);
	pre_fill(&sky);
	find_answer(&sky, 0);
	/*
	- Error System
	- Parsing
	- Init Data
	- Backtracking
	- Print
	*/
	printf("-------------------------------------\n");
	printf("Hauteur tour \t| Nb restant a placer\n");
	printf("-------------------------------------\n");
	i = 0;
	while (i < sky.size)
	{
		printf("\t%d\t|\t %d \t\n", i + 1, sky.cur.nb_left[i]);
		i++;
	}
	printf("-------------------------------------\n");
	print_result(&sky, sky.cur.map, sky.size);
	return (ft_exit(&sky.list, EXIT_SUCCESS));
}
