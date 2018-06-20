/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:16 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:46:22 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pointer_conversions(t_out *out, va_list ar, t_flags *oper)
{
	int i;

	out->arg = va_arg(ar, void*);
	out->value = f_unsigned_int((unsigned long)out->arg, 16);
	out->value_len = ft_strlen(out->value);
	i = ft_strlen(out->f.flags);
	out->f.conversion = 'x';
	out->f.flags[i] = '#';
	out->pointer = 1;
	manage_operations(out, oper);
}

void		persentage(t_out *out, va_list ar, t_flags *oper)
{
	ar = 0;
	out->value = ft_strdup("%");
	out->value_len = 1;
	manage_operations(out, oper);
}

void		no_conversion(t_out *out, va_list ar, t_flags *oper)
{
	ar = 0;
	if (out->value[0] != '\0')
		out->value_len = 1;
	put_marks(out, ft_strlen(out->f.flags), out->f.conversion);
	manage_operations(out, oper);
}

void		int_ptr_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long int *arg;

	oper = 0;
	arg = va_arg(ar, long int*);
	*arg = (long int)out->out_len;
}
