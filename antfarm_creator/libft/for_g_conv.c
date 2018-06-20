/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_g_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:13:18 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 14:55:39 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*exponent_g_str(t_out *out, char *str, int size)
{
	str[size] = '\0';
	while (out->d.exp_size-- > 0)
	{
		str[--size] = (out->d.exp % 10) + 48;
		out->d.exp /= 10;
	}
	str[--size] = out->d.exp_sign;
	str[--size] = out->f.conversion - 2;
	while (out->d.fr_size-- > 0)
	{
		str[--size] = (out->d.fr_part % 10) + 48;
		out->d.fr_part /= 10;
	}
	out->d.dec_point ? str[--size] = '.' : size;
	while (out->d.i_size-- > 0)
	{
		str[--size] = (out->d.i_part % 10) + 48;
		out->d.i_part /= 10;
	}
	out->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

char	*for_e_notation(t_out *out)
{
	char	*str;
	int		size;

	separate_num(out, out->d.num);
	exp_size(out, out->d.exp, out->f.conversion);
	g_size(out);
	size = out->d.fr_size + out->d.i_size + out->minus_sign +
			out->d.exp_size + out->d.dec_point + 2;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = exponent_g_str(out, str, size);
	return (str);
}

char	*for_f_notation(t_out *out, long double num)
{
	char	*str;
	int		size;

	out->d.exp = 0;
	separate_num(out, num);
	g_size(out);
	if (out->f.precision > out->d.i_size && out->prefix && out->d.i_part != 0)
		out->d.fr_size = out->f.precision - out->d.i_size;
	size = out->d.fr_size + out->d.i_size + out->minus_sign + out->d.dec_point;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (out->d.fr_size-- > 0)
	{
		str[--size] = (out->d.fr_part % 10) + 48;
		out->d.fr_part /= 10;
	}
	out->d.dec_point ? str[--size] = '.' : size;
	while (out->d.i_size-- > 0)
	{
		str[--size] = (out->d.i_part % 10) + 48;
		out->d.i_part /= 10;
	}
	out->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

char	*for_g_conv(t_out *out, long double num)
{
	char	*str;

	if (num < 0.0 || num < -0.0)
	{
		num *= (-1);
		out->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent(out, num) : 0;
	check_dec_point(out, num, out->f.conversion);
	if ((out->d.exp > 4 && out->d.exp_sign == '-' && out->f.precision > 1) ||
			(out->d.exp >= out->f.precision && out->d.exp_sign == '+'))
		str = for_e_notation(out);
	else
	{
		if (out->f.precision == 1 && out->d.exp > 4 && out->d.exp_sign == '-')
			out->f.precision = out->d.exp;
		str = for_f_notation(out, num);
	}
	return (str);
}
