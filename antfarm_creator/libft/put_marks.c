/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_marks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:32:18 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:43:54 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	capital_hex(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= 97 && s[i] <= 102)
			s[i] -= 32;
	}
}

int		is_signed_conversion(char conv)
{
	if (conv == 'i' || conv == 'd' || conv == 'D' || conv == 'F' ||
		conv == 'f' || conv == 'e' || conv == 'E' || conv == 'g' ||
		conv == 'G' || conv == 'a' || conv == 'A')
		return (1);
	return (0);
}

int		is_unsigned_conversion(char conv)
{
	if (conv == 'x' || conv == 'X' || conv == 'o' || conv == 'O' ||
		conv == 'u' || conv == 'U')
		return (1);
	return (0);
}

void	put_marks2(t_out *out, char conv)
{
	if ((conv == 'x' || conv == 'X') && out->value[0] == '0' &&
		!(out->f.precision))
		out->flags = 0;
	else if ((conv == 'c' || conv == 'C' || conv == '%' || conv == 0 ||
		(conv == 's' && out->value_len == 0)) && out->precision)
	{
		out->f.precision = 0;
		out->precision = 0;
	}
	if ((!(out->f.precision) && out->precision) &&
		((is_unsigned_conversion(conv) && !(out->flags)) || (conv == 's')))
	{
		out->value_len = 0;
		out->precision = 0;
	}
}

void	put_marks(t_out *out, int i, char conv)
{
	while (--i >= 0)
	{
		if (out->f.flags[i] == '-')
			out->left_justify = 1;
		else if (out->f.flags[i] == '+' && is_signed_conversion(conv) &&
				!(out->minus_sign))
			out->plus_sign = 1;
		else if ((out->f.flags[i] == ' ' || out->f.flags[i] == '+') &&
			is_signed_conversion(conv) && !(out->minus_sign) && !(out->pointer))
			out->space = 1;
		else if (out->f.flags[i] == '#')
		{
			if ((conv == 'o' || conv == 'O') && out->value[0] != '0')
				out->prefix = 1;
			else if (((conv == 'x' || conv == 'X') &&
				out->value[0] != '0') || out->pointer)
				out->prefix = 2;
		}
		else if (out->f.flags[i] == '0')
			out->zero_pad = 1;
	}
	put_marks2(out, conv);
}
