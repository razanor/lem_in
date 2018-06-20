/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:14:51 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	additional_array_of_analizers(t_analizer *analizer)
{
	analizer['e'] = &e_conversion;
	analizer['E'] = &e_conversion;
	analizer['f'] = &f_conversion;
	analizer['F'] = &f_conversion;
	analizer['g'] = &g_conversion;
	analizer['G'] = &g_conversion;
	analizer['a'] = &a_conversion;
	analizer['A'] = &a_conversion;
	analizer['n'] = &int_ptr_conversion;
	analizer['b'] = &unsigned_conversions;
	analizer['k'] = &time_conversion;
	analizer['r'] = &non_print_conversion;
}

void	array_ot_analizers(t_analizer *analizer)
{
	analizer[0] = &no_conversion;
	analizer['%'] = &persentage;
	analizer['s'] = &char_conversions;
	analizer['S'] = &wchar_conversions;
	analizer['p'] = &pointer_conversions;
	analizer['d'] = &signed_conversions;
	analizer['D'] = &signed_conversions;
	analizer['i'] = &signed_conversions;
	analizer['o'] = &unsigned_conversions;
	analizer['O'] = &unsigned_conversions;
	analizer['u'] = &unsigned_conversions;
	analizer['U'] = &unsigned_conversions;
	analizer['x'] = &unsigned_conversions;
	analizer['X'] = &unsigned_conversions;
	analizer['c'] = &char_conversions;
	analizer['C'] = &wchar_conversions;
	additional_array_of_analizers(analizer);
}

void	array_ot_flags(t_flags *flag_operation)
{
	flag_operation['-'] = &zero_padding;
	flag_operation['0'] = &zero_padding;
	flag_operation['+'] = &sign_production;
	flag_operation[' '] = &space_production;
	flag_operation['#'] = &alternative_output;
}

void	output_analize(t_out *out, va_list ar)
{
	static t_analizer	*analizer = NULL;
	static t_flags		*flags = NULL;

	if (analizer == NULL && flags == NULL)
	{
		analizer = (t_analizer*)malloc(sizeof(t_analizer) * 256);
		flags = (t_flags*)malloc(sizeof(t_flags) * 256);
		array_ot_analizers(analizer);
		array_ot_flags(flags);
	}
	analizer[(int)out->f.conversion](out, ar, flags);
	if (out->value != NULL)
		free(out->value);
}
