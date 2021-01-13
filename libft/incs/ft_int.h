/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:26:26 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 13:12:33 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <stdlib.h>
# include "ft_cmp.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_intblen(long long n, long long base);
int		ft_uintblen(unsigned long long n, unsigned long long base);

#endif
