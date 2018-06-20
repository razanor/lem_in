/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:50:48 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:14:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_float_values(t_out *out, long double arg, char conv)
{
	if ((arg == 1.0 / 0.0) && (conv == 'f' ||
		conv == 'a' || conv == 'g' || conv == 'e'))
		out->value = ft_strdup("inf");
	else if ((arg == 1.0 / 0.0) && (conv == 'F' || conv == 'A' ||
		conv == 'G' || conv == 'E'))
		out->value = ft_strdup("INF");
	else if ((arg == -(1.0 / 0.0)) && (conv == 'f' || conv == 'a' ||
		conv == 'g' || conv == 'e'))
		out->value = ft_strdup("-inf");
	else if ((arg == -(1.0 / 0.0)) && (conv == 'F' || conv == 'A' ||
		conv == 'G' || conv == 'E'))
		out->value = ft_strdup("-INF");
	else if ((arg != arg) && (conv == 'f' || conv == 'a' ||
		conv == 'g' || conv == 'e'))
		out->value = ft_strdup("nan");
	else if ((arg != arg) && (conv == 'F' || conv == 'A' ||
		conv == 'G' || conv == 'E'))
		out->value = ft_strdup("NAN");
	else
		return (0);
	return (1);
}
