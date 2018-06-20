/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_f_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:52:19 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 15:04:48 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	separate_num(t_out *out, long double num)
{
	long double fract_part;
	int			n;

	out->d.i_part = (unsigned long int)num;
	fract_part = num - out->d.i_part;
	out->d.zero_fr = 0;
	n = 0;
	while (n < out->f.precision)
	{
		fract_part *= 10.0000;
		out->d.fr_part = (unsigned long int)(fract_part + 0.5);
		if ((int)fract_part == 0)
			out->d.zero_fr++;
		n++;
	}
}

char	*f_str(t_out *out, char *str, int size)
{
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

char	*for_f_conv(t_out *out, long double num)
{
	char	*str;
	int		size;

	if (num < 0)
	{
		num *= (-1);
		out->minus_sign = 1;
	}
	separate_num(out, num);
	(!(out->f.precision) && out->precision) ? 0 : (out->d.dec_point = 1);
	out->d.fr_size = out->f.precision;
	i_part_size(out, out->d.i_part, 10);
	if (out->prefix)
		out->d.dec_point = 1;
	size = out->d.i_size + out->d.fr_size + out->minus_sign + out->d.dec_point;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = f_str(out, str, size);
	return (str);
}
