/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:01:28 by obelair           #+#    #+#             */
/*   Updated: 2021/01/14 22:01:28 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"
#include <stdio.h>

int     main(int ac, char **av)
{
	t_setting	ts;

	if(sky_check_arg(ac, av, &ts))
		return(0);
	ft_printf("All is fine! Let's get started!\n\tSize --> %d\n\tMode --> %s\n\tDifficulty --> %s\n", ts.size, ts.mode, ts.difficulty);
    return (0);
}