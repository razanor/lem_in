/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:06:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:52:03 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wchar_conversions(t_out *out, va_list ar, t_flags *oper)
{
	if ((out->arg = va_arg(ar, void*)) == NULL && (out->f.conversion == 's' ||
		out->f.conversion == 'S'))
	{
		out->out_len += write(1, "(null)", 6);
		return ;
	}
	put_marks(out, ft_strlen(out->f.flags), out->f.conversion);
	if (out->left_justify)
	{
		if (out->f.width && !(out->precision))
			out->f.width -= get_value_len(out);
		out->value_len = 0;
		get_wide_char(out);
		if (!(out->f.precision) && !(out->precision))
			manage_operations(out, oper);
	}
	if (!(out->left_justify))
	{
		if (out->f.width && !(out->precision))
			out->f.width -= get_value_len(out);
		out->value_len = 0;
		if (!(out->f.precision) && !(out->precision))
			manage_operations(out, oper);
		get_wide_char(out);
	}
}

void	char_conversions(t_out *out, va_list ar, t_flags *oper)
{
	out->value_len = 1;
	if (out->f.modifier == 'l')
	{
		out->value_len = 0;
		wchar_conversions(out, ar, oper);
		return ;
	}
	else if ((out->arg = va_arg(ar, void*)) == NULL && out->f.conversion == 's')
	{
		out->value = ft_strdup("(null)");
		out->value_len = 6;
	}
	else if (out->f.conversion == 's')
	{
		out->value = ft_strdup((char*)out->arg);
		out->value_len = ft_strlen(out->value);
	}
	else if (out->f.conversion == 'c')
		out->value = ft_strdup((char*)&out->arg);
	manage_operations(out, oper);
}
