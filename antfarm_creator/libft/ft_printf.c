/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:20:24 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:49:46 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_out	output;
	va_list	args_ptr;

	output = p_initialise();
	va_start(args_ptr, format);
	ret = output_length(format, args_ptr, &output);
	va_end(args_ptr);
	return (ret);
}
