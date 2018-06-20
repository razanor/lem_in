/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:43:32 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:44:29 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_width(t_out *out, int length)
{
	if (out->zero_pad && !(out->left_justify) && !(out->f.precision))
		return ;
	length = out->f.width - out->value_len - out->prefix -
		out->plus_sign - out->space;
	if ((out->value_len - out->minus_sign) < out->f.precision &&
		out->f.width > out->f.precision)
		length = out->f.width - (out->f.precision +
		out->minus_sign + out->plus_sign + out->space);
	if (out->f.precision > out->f.width ||
		(out->f.width < (out->value_len + out->prefix)))
		length = 0;
	if ((out->f.conversion == 's') && out->f.precision)
	{
		if (out->value_len < out->f.precision)
			length = out->f.width - out->value_len;
		else if (out->value_len > out->f.precision)
			length = out->f.width - out->f.precision;
	}
	out->out_len += length;
	while (length-- > 0)
		write(1, " ", 1);
}

void	manage_max_precision(t_out *out)
{
	int length;

	length = 0;
	if (out->value_len > out->f.width && out->f.precision < out->f.width)
		length = out->f.width - out->f.precision;
	if (out->value_len > out->f.precision)
		out->value_len = out->f.precision;
	out->out_len += length;
	while (length-- > 0)
		write(1, " ", 1);
	write(1, out->value, out->value_len);
	out->out_len += out->value_len;
}

void	manage_min_precision(t_out *out)
{
	int length;

	length = 0;
	if ((out->value_len - out->minus_sign) < out->f.precision)
	{
		if (out->minus_sign)
			write(1, "-", 1);
		length = out->f.precision - out->value_len + out->minus_sign;
		if (out->prefix == 1)
			length -= out->prefix;
		out->out_len += length;
		while (length-- > 0)
			write(1, "0", 1);
		write(1, &out->value[out->minus_sign],
			out->value_len - out->minus_sign);
	}
	else
		write(1, out->value, out->value_len);
	out->out_len += out->value_len;
}
