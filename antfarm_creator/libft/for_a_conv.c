/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_a_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:53:38 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:37:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*a_str(t_out *out, char *str, int size, char hex)
{
	while (out->d.exp_size-- > 0)
	{
		str[--size] = (out->d.exp % 10) + 48;
		out->d.exp /= 10;
	}
	str[--size] = out->d.exp_sign;
	str[--size] = out->f.conversion + 15;
	while (out->d.fr_size-- > 0)
	{
		str[--size] = (out->d.fr_part % 16) +
			((out->d.fr_part % 16) >= 10 ? (hex - 10) : '0');
		out->d.fr_part /= 16;
	}
	out->d.dec_point ? str[--size] = '.' : size;
	while (out->d.i_size-- > 0)
	{
		str[--size] = (out->d.i_part % 16) +
			((out->d.i_part % 16) >= 10 ? (hex - 10) : '0');
		out->d.i_part /= 16;
	}
	(out->zero_pad) ? (str[--size] = '0') : size;
	str[--size] = out->f.conversion + 23;
	return (str);
}

char	*for_a_conv(t_out *out, long double num)
{
	char	*str;
	int		size;

	if (num < 0.0)
	{
		num *= (-1);
		out->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent_for_a(out, num) : 0;
	(out->d.exp == 0) ? (out->d.exp_sign = '+') : 0;
	separate_num_for_a(out, out->d.num);
	exp_size(out, out->d.exp, out->f.conversion);
	check_dec_point(out, num, out->f.conversion);
	a_size(out);
	size = out->d.i_size + out->d.fr_size + out->d.exp_size + out->d.dec_point +
		out->minus_sign + out->zero_pad + 4;
	str = (char*)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	(out->f.conversion == 'a') ? (str = a_str(out, str, size, 'a')) :
								(str = a_str(out, str, size, 'A'));
	str[out->minus_sign] = '0';
	out->minus_sign ? str[0] = '-' : 0;
	return (str);
}
