/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:20:39 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:52:35 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_padding(t_out *out)
{
	int length;

	length = 0;
	if ((out->left_justify || out->f.precision))
		return ;
	if (out->f.width > out->value_len)
	{
		length = out->f.width - out->value_len -
		out->prefix - out->space - out->plus_sign;
	}
	out->out_len += (length + out->plus_sign + out->space);
	if (out->minus_sign && !(out->left_justify))
		write(1, "-", 1);
	else if (out->plus_sign)
		write(1, "+", 1);
	else if (out->space)
		write(1, " ", 1);
	while (length-- > 0)
		write(1, "0", 1);
	if (out->value != NULL)
		write(1, &out->value[out->minus_sign],
			out->value_len - out->minus_sign);
}

void	sign_production(t_out *out)
{
	if (out->plus_sign && !(out->minus_sign) &&
		!(out->pointer) && !(out->zero_pad) &&
		out->value != NULL)
	{
		write(1, "+", 1);
		out->out_len++;
	}
}

void	space_production(t_out *out)
{
	if (out->space && out->f.conversion != '%' &&
		out->f.conversion != 0 && out->f.conversion != 'c' &&
		!(out->plus_sign) && !(out->zero_pad))
	{
		write(1, " ", 1);
		out->out_len++;
	}
}

void	alternative_output(t_out *out)
{
	if (out->prefix || out->pointer)
	{
		write(1, "0", 1);
		out->out_len++;
	}
	if (out->prefix == 2 || out->pointer)
	{
		write(1, &out->f.conversion, 1);
		out->out_len++;
	}
	if (out->pointer && out->zero_pad)
		zero_padding(out);
}
