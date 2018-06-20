/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:28:55 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:46:36 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fmt_flags(char f)
{
	if (f == '-' || f == '0' || f == '+' || f == ' ' || f == '#' ||
		f == 39)
		return (1);
	return (0);
}

int		fmt_field_width(char f)
{
	if ((f >= '0' && f <= '9') || f == '*')
		return (1);
	return (0);
}

int		fmt_precision(char f)
{
	if (f == '.')
		return (1);
	return (0);
}

int		fmt_size_modifier(char f)
{
	if (f == 'z' || f == 'j' || f == 'l' || f == 'h' || f == 'L')
		return (1);
	return (0);
}

int		fmt_conversion(char f)
{
	if (f == 'c' || f == 'C' || f == 's' || f == 'S' || f == '%' ||
		f == 'd' || f == 'i' || f == 'o' || f == 'u' || f == 'x' ||
		f == 'D' || f == 'O' || f == 'U' || f == 'X' || f == 'p' ||
		f == 'f' || f == 'F' || f == 'e' || f == 'E' || f == 'g' ||
		f == 'G' || f == 'a' || f == 'A' || f == 'n' || f == 'b' ||
		f == 'r' || f == 'k')
		return (1);
	return (0);
}
