/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_conv_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:05:30 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:54:25 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_fract_for_a(t_out *out)
{
	while (out->d.fr_size-- > out->f.precision)
	{
		((out->d.fr_part % 16) > 8) ?
			(out->d.fr_part = out->d.fr_part / 16 + 1) : (out->d.fr_part /= 16);
	}
	out->d.fr_size = out->f.precision;
}

void	round_ipart_for_a(t_out *out)
{
	out->f.precision = 1;
	round_fract_for_a(out);
	if ((out->d.fr_part % 16) > 8)
		out->d.i_part = out->d.i_part + 1;
	out->d.fr_size = 0;
	out->d.dec_point = 0;
	out->f.precision = 0;
}

void	a_size(t_out *out)
{
	i_part_size(out, out->d.i_part, 16);
	f_part_size(out, out->d.fr_part, 16);
	if (out->f.precision)
		round_fract_for_a(out);
	while ((out->d.fr_part % 16) == 0 && out->d.fr_part != 0 &&
		out->d.fr_size > 0 && !(out->f.precision))
	{
		out->d.fr_part /= 16;
		out->d.fr_size--;
	}
	if ((!(out->f.precision) && out->precision) || out->d.fr_part == 0)
		round_ipart_for_a(out);
}

void	separate_num_for_a(t_out *out, long double num)
{
	long double fract_part;
	int			pres;

	out->d.i_part = (unsigned long int)num;
	fract_part = num - out->d.i_part;
	out->d.fr_part = 0;
	pres = 0;
	out->d.zero_fr = 0;
	while (pres < 52)
	{
		fract_part *= 2.0;
		out->d.fr_part = (unsigned long int)(fract_part + 0.1);
		if ((int)(fract_part) == 0)
			out->d.zero_fr++;
		pres++;
	}
	(out->d.fr_part == 0) ? (out->d.zero_fr = 0) : (out->d.zero_fr /= 4);
}

void	get_exponent_for_a(t_out *out, long double num)
{
	out->d.exp = 0;
	if (num >= 1.99)
	{
		while (num >= 1.99)
		{
			out->d.exp++;
			num /= 2;
		}
		out->d.exp_sign = '+';
	}
	else if (num <= 1.0)
	{
		while (num < 1.0)
		{
			out->d.exp++;
			num *= 2;
		}
		out->d.exp_sign = '-';
	}
	out->d.num = num;
}
