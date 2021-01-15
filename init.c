/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:07:12 by obelair           #+#    #+#             */
/*   Updated: 2021/01/14 22:13:25 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	sky_init_setting(t_setting *ts)
{
	ts->size = 0;
	ts->mode = 0;
	ts->difficulty = 0;
}

void	sky_init_hint(t_hint *th)
{
	th->bot = 0;
	th->left = 0;
	th->right = 0;
	th->top = 0;
}