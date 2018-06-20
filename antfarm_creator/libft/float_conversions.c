/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:11:16 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:50:35 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long double arg;

	if (out->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!out->f.precision && !(out->precision))
		out->f.precision = 6;
	if (!(check_float_values(out, arg, out->f.conversion)))
		out->value = for_f_conv(out, arg);
	out->value_len = ft_strlen(out->value);
	out->f.precision = 0;
	out->precision = 0;
	if (out->apostr)
		apostr_f_production(out);
	manage_operations(out, oper);
}

void	e_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long double	arg;

	if (out->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!out->f.precision && !(out->precision))
		out->f.precision = 6;
	if (!(check_float_values(out, arg, out->f.conversion)))
		out->value = for_e_conv(out, arg);
	out->value_len = ft_strlen(out->value);
	out->f.precision = 0;
	out->precision = 0;
	manage_operations(out, oper);
}

void	g_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long double	arg;
	int			i;

	if (out->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!(out->f.precision) && !(out->precision))
		out->f.precision = 6;
	else if (!(out->f.precision) && out->precision)
		out->f.precision = 1;
	i = ft_strlen(out->f.flags);
	while (--i >= 0)
		if (out->f.flags[i] == '#')
			out->prefix = 1;
	if (!(check_float_values(out, arg, out->f.conversion)))
		out->value = for_g_conv(out, arg);
	out->value_len = ft_strlen(out->value);
	out->f.precision = 0;
	out->precision = 0;
	out->prefix = 0;
	manage_operations(out, oper);
}

void	a_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long double	arg;
	int			i;

	if (out->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	put_marks(out, ft_strlen(out->f.flags), out->f.conversion);
	(out->zero_pad && (out->f.precision < out->f.width)) ? out->zero_pad :
					(out->zero_pad = 0);
	i = ft_strlen(out->f.flags);
	while (--i >= 0)
		if (out->f.flags[i] == '#')
			out->prefix = 1;
	if (!(check_float_values(out, arg, out->f.conversion)))
		out->value = for_a_conv(out, arg);
	out->value_len = ft_strlen(out->value);
	out->f.precision = 0;
	out->precision = 0;
	out->prefix = 0;
	manage_operations(out, oper);
}
