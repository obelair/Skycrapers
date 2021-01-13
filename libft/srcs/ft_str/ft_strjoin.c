/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:43 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_str.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*cat;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(cat = malloc(sizeof(char) * (lens1 + lens2) + 1)))
		return (NULL);
	while (s1 && s1[++i])
		cat[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		cat[i + lens1] = s2[i];
	cat[lens1 + i] = '\0';
	free(s1);
	return (cat);
}
