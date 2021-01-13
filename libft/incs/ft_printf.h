/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:03:22 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_cmp.h"
# include "ft_str.h"
# include "ft_int.h"
# include "ft_put.h"

# define FALSE	0
# define TRUE	1
# define B8		"01234567"
# define B10	"0123456789"
# define B16L	"0123456789abcdef"
# define B16U	"0123456789ABCDEF"

typedef struct	s_format
{
	va_list		*ap;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	int			point;
	char		spec;
	int			wprec;
	int			width;
	int			lenvar;
	char		*base;
	int			fd;
	int			nbprint;
}				t_format;

int				ft_printf(const char *str,
					...) __attribute__((format(printf,1,2)));
int				ft_scan_str(t_format *tf, const char *str);
void			ft_init_struct(va_list *ap, t_format *tf, int fd);
void			ft_displ_int(t_format *tf, char *base);
void			ft_displ_addr(t_format *tf, char *base);
void			ft_displ_nbr(t_format *tf, unsigned long long val);
void			ft_displ_spc(t_format *tf, int i);
void			ft_displ_zero(t_format *tf, int i);
void			ft_displ_pre(t_format *tf, long long *val);
void			ft_displ_chr(t_format *tf);
void			ft_displ_str(t_format *tf);
void			ft_nptr(t_format *tf);
void			ft_lencmp(t_format *tf, long long val);

#endif
