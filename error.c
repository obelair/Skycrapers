/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:46:05 by obelair           #+#    #+#             */
/*   Updated: 2021/01/15 01:30:55 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

static int	sky_check_setting(t_setting *ts)
{
	if (ts->size && (ts->size > 8 || 3 > ts->size))
		return (ft_printf("Size must be between 3 and 8.(included)\n"));
	else if (!ts->size)
		ts->size = 4;
	if (ts->mode && (!ft_strcmp("normal", ts->mode)
		&& !ft_strcmp("parking", ts->mode) && !ft_strcmp("notseen", ts->mode)))
		return (ft_printf("Mode not existing![normal|parking|notseen]\n"));
	else if (!ts->mode)
		ts->mode = "normal";
	if (ts->difficulty && (ft_strcmp("easy", ts->difficulty)
		&& ft_strcmp("normal", ts->difficulty)
		&& ft_strcmp("hardcore", ts->difficulty)))
		return (ft_printf("Difficulty not existing![easy|normal|hardcore]\n"));
	else if (!ts->difficulty)
		ts->difficulty = "easy";
	return (0);
}

static int	sky_check_init(char **av, int i, t_setting *ts)
{
//	ft_printf("S : %d | Arg : %s | Cmp : %d | Dig : %d\n", !ts->size, av[i], !ft_strcmp("-s", av[i]), ft_strisdigit(av[i + 1]));
	if (!ft_strcmp("-s", av[i]) && !ft_strisdigit(av[i + 1]) && !ts->size)
	{
		if (!(ts->size = ft_atoi(av[i + 1])))
			ts->size = 1;
	}
	else if (!ft_strcmp("-s", av[i]) && ts->size)
		return (ft_printf("Size already set up!\n"));
	else if (!ft_strcmp("-s", av[i]) && ft_strisdigit(av[i + 1]))
		return (ft_printf("Size need to be a number!\n"));
//	ft_printf("M : %d | Arg : %s | Cmp : %d | Dig : %d\n", !ts->mode, av[i], !ft_strcmp("-m", av[i]), ft_strisalpha(av[i + 1]));
	if (!ft_strcmp("-m", av[i]) && !ft_strisalpha(av[i + 1]) && !ts->mode)
		ts->mode = av[i + 1];
	else if (!ft_strcmp("-m", av[i]) && ts->mode)
		return (ft_printf("Mode already set up!\n"));
	else if (!ft_strcmp("-m", av[i]) && ft_strisalpha(av[i + 1]))
		return (ft_printf("Wrong writing for the Mode!\n"));
//	ft_printf("S : %d | Arg : %s | Cmp : %d | Dig : %d\n", !ts->difficulty, av[i], !ft_strcmp("-d", av[i]), ft_strisalpha(av[i + 1]));
	if (!ft_strcmp("-d", av[i]) && !ft_strisalpha(av[i + 1]) && !ts->difficulty)
		ts->difficulty = av[i + 1];
	else if (!ft_strcmp("-d", av[i]) && ts->difficulty)
		return (ft_printf("Difficulty already set up!\n"));
	else if (!ft_strcmp("-d", av[i]) && ft_strisalpha(av[i + 1]))
		return (ft_printf("Wrong writing for the Difficulty!\n"));
	return (0);
}

int			sky_check_arg(int ac, char **av, t_setting *ts)
{
	int i;

	if (ac > 7 || 1 > ac || !(ac % 2))
		return (ft_printf("Nbrs of Arguments invalids!\n"));
	i = 1;
	sky_init_setting(ts);
	while (av[i] && i < ac - 1)
	{
		if (ft_strcmp("-s", av[i]) && ft_strcmp("-m", av[i]) && ft_strcmp("-d", av[i]))
			return (ft_printf("Argument not recognized, try these one:\
			\n\t-s [size]\n\t-m [mode]\n\t-d [difficulty]\n"));
		if (sky_check_init(av, i, ts))
			return (1);
		i += 2;
	}
	if(sky_check_setting(ts))
		return (1);
	return (0);
}