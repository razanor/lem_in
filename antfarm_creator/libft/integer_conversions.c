/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:06:43 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:49:24 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(char conv)
{
	if (conv == 'x' || conv == 'X')
		return (16);
	else if (conv == 'o' || conv == 'O')
		return (8);
	else if (conv == 'b')
		return (2);
	return (10);
}

void	unsigned_conversions(t_out *out, va_list ar, t_flags *oper)
{
	out->arg = va_arg(ar, void*);
	manage_unsigned_modifier(out, get_base(out->f.conversion));
	out->value_len = ft_strlen(out->value);
	if (out->apostr && (out->f.conversion == 'u'))
		apostr_production(out);
	if (out->f.conversion == 'X')
		capital_hex(out->value);
	manage_operations(out, oper);
}

void	signed_conversions(t_out *out, va_list ar, t_flags *oper)
{
	out->arg = va_arg(ar, void*);
	manage_decimal_modidfier(out, 10);
	if (out->value[0] == '-')
		out->minus_sign = 1;
	out->value_len = ft_strlen(out->value);
	if (!(out->f.precision) && out->precision)
	{
		if (out->value[0] == '0')
			out->value_len = 0;
		if (!(out->flags))
			out->precision = 0;
	}
	if (out->apostr)
		apostr_production(out);
	manage_operations(out, oper);
}
