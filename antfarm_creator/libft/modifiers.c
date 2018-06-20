/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:29:42 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 17:36:47 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_unsigned_modifier(t_out *out, int base)
{
	if (out->f.modifier == 'z')
		out->value = f_unsigned_int((size_t)out->arg, base);
	else if (out->f.modifier == 'j')
		out->value = f_unsigned_int((uintmax_t)out->arg, base);
	else if (out->f.modifier == 'L')
		out->value = f_unsigned_int((unsigned long long int)out->arg, base);
	else if (out->f.modifier == 'l' || out->f.conversion == 'U' ||
		out->f.conversion == 'O')
		out->value = f_unsigned_int((unsigned long int)out->arg, base);
	else if (out->f.modifier == 'h')
		out->value = f_unsigned_int((unsigned short int)out->arg, base);
	else if (out->f.modifier == 'H')
		out->value = f_unsigned_int((unsigned char)out->arg, base);
	else
		out->value = f_unsigned_int((unsigned int)out->arg, base);
}

void	manage_decimal_modidfier(t_out *out, int base)
{
	if (out->f.modifier == 'z')
		out->value = f_int_base((size_t)out->arg, base);
	else if (out->f.modifier == 'j')
		out->value = f_int_base((intmax_t)out->arg, base);
	else if (out->f.modifier == 'L')
		out->value = f_int_base((long long int)out->arg, base);
	else if (out->f.modifier == 'l' || out->f.conversion == 'D')
		out->value = f_int_base((long int)out->arg, base);
	else if (out->f.modifier == 'h')
		out->value = f_int_base((short int)out->arg, base);
	else if (out->f.modifier == 'H')
		out->value = f_int_base((signed char)out->arg, base);
	else
		out->value = f_int_base((int)out->arg, base);
}
