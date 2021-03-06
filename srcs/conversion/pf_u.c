/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:21:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:03:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				pf_u(t_printf *f)
{
	uintmax_t	n;

	if (f->type == 'U' && f->conv < 4)
		f->conv = 4;
	n = pf_va_uarg(f);
	f->flag.space = 0;
	f->flag.plus = 0;
	if (n == 0 && f->preci == 0)
		f->arg_len = 0;
	else
		f->arg_len = pf_max(f->preci, pf_unbr_len(n, 10));
	f->field_len = pf_max(f->arg_len, f->width);
	ufield(f, n, "0123456789");
}
