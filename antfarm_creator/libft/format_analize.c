/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_analize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:45:28 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:50:08 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_format2(t_out *out, const char *format, int j)
{
	int i;

	i = -1;
	while (i++ < 2 && fmt_size_modifier(format[j]))
		j++;
	if (i != -1)
	{
		i == 1 ? (out->f.modifier = format[--j]) :
		(out->f.modifier = format[--j] - 32);
		j++;
	}
	if (fmt_conversion(format[j]))
		out->f.conversion = format[j];
	return (j);
}

int		write_width(t_out *out, const char *format, va_list ar, int j)
{
	while (fmt_field_width(format[j]))
	{
		if (format[j] == '*')
		{
			if ((out->f.width = va_arg(ar, int)) < 0)
				out->left_justify = 1;
			out->f.width = ABS(out->f.width);
			j++;
		}
		else
		{
			out->f.width = ft_atoi(&format[j]);
			while (fmt_field_width(format[j]) && format[j] != '*')
				j++;
		}
	}
	return (j);
}

int		write_precision(t_out *out, const char *format, va_list ar, int j)
{
	if (fmt_precision(format[j]))
	{
		out->precision = 1;
		if (format[++j] == '*')
		{
			if ((out->f.precision = va_arg(ar, int)) < 0)
			{
				out->f.precision = 0;
				out->precision = 0;
			}
		}
		else
			out->f.precision = ft_atoi(&format[j]);
		while (fmt_field_width(format[j]))
			j++;
	}
	return (j);
}

int		write_format(t_out *out, const char *format, va_list ar, int j)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (fmt_flags(format[j]))
	{
		while (c-- > 0)
			while (out->f.flags[c] == format[j])
				j++;
		if (format[j] == 39)
		{
			out->apostr = 1;
			j++;
		}
		else if (fmt_flags(format[j]))
		{
			out->f.flags[i++] = format[j++];
			out->flags = 1;
			c = i;
		}
	}
	j = write_width(out, format, ar, j);
	j = write_precision(out, format, ar, j);
	return (write_format2(out, format, j));
}
