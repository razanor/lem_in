/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sizes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:04:06 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:51:48 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	exp_size(t_out *out, int exp, char conv)
{
	out->d.exp_size = 0;
	if (exp == 0)
		out->d.exp_size++;
	while (exp != 0)
	{
		exp /= 10;
		out->d.exp_size++;
	}
	if (out->d.exp_size < 2 && (conv != 'a' && conv != 'A'))
		out->d.exp_size = 2;
}

void	i_part_size(t_out *out, unsigned long i_p, int base)
{
	out->d.i_size = 0;
	if (i_p == 0)
		out->d.i_size++;
	while (i_p != 0)
	{
		i_p /= base;
		out->d.i_size++;
	}
}

void	f_part_size(t_out *out, unsigned long f_p, int base)
{
	out->d.fr_size = 0;
	out->d.fr_size += out->d.zero_fr;
	while (f_p != 0)
	{
		f_p /= base;
		out->d.fr_size++;
	}
}

void	check_dec_point(t_out *out, long double num, char conv)
{
	if (conv == 'g' || conv == 'G')
	{
		if (out->f.precision != 1 || num != 0.0 || out->prefix)
			out->d.dec_point = 1;
	}
	else if (conv == 'a' || conv == 'A')
	{
		if ((num != 0.0 && out->d.fr_part != 0) ||
				out->f.precision || out->prefix)
			out->d.dec_point = 1;
	}
}
