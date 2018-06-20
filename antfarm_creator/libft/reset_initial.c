/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_initial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:49:03 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:44:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_values(t_out *out)
{
	ft_bzero(out->f.flags, 5);
	out->value_len = 0;
	out->value = NULL;
	out->f.modifier = 0;
	out->f.conversion = 0;
	out->f.width = 0;
	out->f.precision = 0;
	out->minus_sign = 0;
	out->apostr = 0;
	out->plus_sign = 0;
	out->left_justify = 0;
	out->prefix = 0;
	out->zero_pad = 0;
	out->pointer = 0;
	out->precision = 0;
	out->space = 0;
	out->flags = 0;
	out->d.i_part = 0;
	out->d.fr_part = 0;
	out->d.zero_fr = 0;
	out->d.dec_point = 0;
	out->d.exp = 0;
	out->d.num = 0;
}

t_out	p_initialise(void)
{
	t_out out;

	out.out_len = 0;
	reset_values(&out);
	return (out);
}
