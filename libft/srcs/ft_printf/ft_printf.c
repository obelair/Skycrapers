/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:33 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		param_info;
	t_format	form;
	int			i;

	va_start(param_info, str);
	form.nbprint = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			form.nbprint++;
			i++;
		}
		else
		{
			ft_init_struct(&param_info, &form, 1);
			i += ft_scan_str(&form, str + i + 1);
		}
	}
	va_end(param_info);
	return (form.nbprint);
}
