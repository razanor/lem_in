/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:48:57 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:46:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_for_min_precision(char conv)
{
	if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'o' ||
		conv == 'O' || conv == 'u' || conv == 'U' || conv == 'x' ||
		conv == 'X')
		return (1);
	return (0);
}

void	manage_flags(t_out *out, t_flags *oper, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (out->zero_pad && out->pointer)
			++i;
		oper[(int)out->f.flags[i]](out);
	}
}

void	left_justify_operations(t_out *out, t_flags *oper, int i)
{
	manage_flags(out, oper, i);
	if ((out->f.precision && out->value && out->precision))
	{
		if (out->f.conversion == 's')
			manage_max_precision(out);
		else if (is_for_min_precision(out->f.conversion))
			manage_min_precision(out);
	}
	else if ((!(out->f.precision) && out->precision && !(out->flags)))
	{
		write(1, "\0", 1);
		out->out_len += 1;
	}
	else
	{
		write(1, out->value, out->value_len);
		out->out_len += out->value_len;
	}
	if (out->value_len < out->f.width)
		manage_width(out, 0);
}

void	non_justify_operations(t_out *out, t_flags *oper, int i)
{
	if (out->value_len < out->f.width)
		manage_width(out, 0);
	manage_flags(out, oper, i);
	if (out->precision && out->value)
	{
		if (out->f.conversion == 's')
			manage_max_precision(out);
		else if (is_for_min_precision(out->f.conversion))
			manage_min_precision(out);
	}
	else if ((!(out->f.precision) && out->precision && !(out->flags)))
	{
		write(1, "\0", 1);
		out->out_len += 1;
	}
	else
	{
		if (!(out->zero_pad))
			write(1, out->value, out->value_len);
		out->out_len += out->value_len;
	}
}

void	manage_operations(t_out *out, t_flags *oper)
{
	put_marks(out, ft_strlen(out->f.flags), out->f.conversion);
	if (out->left_justify)
		left_justify_operations(out, oper, ft_strlen(out->f.flags));
	else
		non_justify_operations(out, oper, ft_strlen(out->f.flags));
}
