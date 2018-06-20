/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_conv_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:14:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:49:03 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_fpart_for_g(t_out *out)
{
	int n;

	n = out->f.precision - out->d.i_size;
	if (out->d.i_part == 0)
		n++;
	out->d.fr_size = n;
	while (n++ < out->f.precision)
		((out->d.fr_part % 10) > 5) ?
			(out->d.fr_part = out->d.fr_part / 10 + 1) : (out->d.fr_part /= 10);
	if (out->d.fr_part == 0)
	{
		if (!(out->prefix))
			out->d.dec_point = 0;
		out->d.fr_size = 0;
	}
}

void	round_ipart_for_g(t_out *out)
{
	if (out->f.precision < out->d.i_size)
	{
		while (out->d.i_size-- > out->f.precision)
			((out->d.i_part % 10) > 5) ?
				(out->d.i_part = out->d.i_part / 10 + 1) :
				(out->d.i_part /= 10);
	}
	else if (out->f.precision == 1)
	{
		out->f.precision = 2;
		round_fpart_for_g(out);
		if (out->d.fr_part > 5)
			out->d.i_part += 1;
		else if (out->d.i_part > 5)
			out->d.i_part = 1;
	}
	else if (out->prefix || out->d.exp)
	{
		if (out->d.fr_part > 5)
			out->d.i_part += 1;
	}
	if (!(out->prefix))
		out->d.dec_point = 0;
	out->d.fr_size = 0;
}

void	g_size(t_out *out)
{
	while ((out->d.fr_part % 10) == 0 && out->d.fr_part != 0 &&
		!(out->prefix) && !(out->d.exp))
		out->d.fr_part /= 10;
	i_part_size(out, out->d.i_part, 10);
	f_part_size(out, out->d.fr_part, 10);
	if (out->d.fr_size > (out->f.precision - out->d.i_size))
		round_fpart_for_g(out);
	if (out->d.i_size >= out->f.precision || out->prefix)
		round_ipart_for_g(out);
	if (out->d.exp && (out->d.i_size + out->d.fr_size) > out->f.precision)
		round_ipart_for_g(out);
}
