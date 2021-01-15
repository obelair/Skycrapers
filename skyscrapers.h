/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:54:24 by obelair           #+#    #+#             */
/*   Updated: 2021/01/13 22:54:24 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H

# include "libft/incs/ft_cmp.h"
# include "libft/incs/ft_put.h"
# include "libft/incs/ft_int.h"
# include "libft/incs/ft_str.h"
# include "libft/incs/ft_printf.h"

typedef struct	s_setting
{
	int			size;
	char		*mode;
	char		*difficulty;
}				t_setting;

typedef struct	s_hint
{
	char		*top;
	char		*bot;
	char		*left;
	char		*right;
}				t_hint;

int				sky_check_arg(int ac, char **av, t_setting *ts);
void			sky_init_setting(t_setting *ts);
void			sky_init_hint(t_hint *th);

#endif