/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_e_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:54:26 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 15:00:54 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_exponent(t_out *out, long double num)
{
	out->d.exp = 0;
	if (num >= 9.99)
	{
		while (num > 9.99)
		{
			out->d.exp++;
			num /= 10;
		}
		out->d.exp_sign = '+';
	}
	else if (num <= 1.0)
	{
		while (num < 1.0)
		{
			out->d.exp++;
			num *= 10;
		}
		out->d.exp_sign = '-';
	}
	out->d.num = num;
}

char	*e_str(t_out *out, char *str, int size)
{
	str[size] = '\0';
	while (out->d.exp_size-- > 0)
	{
		str[--size] = (out->d.exp % 10) + 48;
		out->d.exp /= 10;
	}
	str[--size] = out->d.exp_sign;
	str[--size] = out->f.conversion;
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

char	*for_e_conv(t_out *out, long double num)
{
	char	*str;
	int		size;

	if (num < 0)
	{
		num *= (-1);
		out->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent(out, num) : 0;
	(out->d.exp == 0) ? (out->d.exp_sign = '+') : 0;
	separate_num(out, out->d.num);
	exp_size(out, out->d.exp, out->f.conversion);
	out->d.fr_size = out->f.precision;
	i_part_size(out, out->d.i_part, 10);
	(!(out->f.precision) && out->precision) ? 0 : (out->d.dec_point = 1);
	if (out->prefix)
		out->d.dec_point = 1;
	size = out->d.i_size + out->d.fr_size + out->minus_sign + out->d.dec_point +
			out->d.exp_size + 2;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = e_str(out, str, size);
	return (str);
}
