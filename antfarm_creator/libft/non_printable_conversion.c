/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:45 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/21 14:07:47 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_non_printable(char c)
{
	if (c == '\0' || c == '\a' || c == '\b' ||
		c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == '\e')
		return (1);
	return (0);
}

void	write_non_pritable(char *ch, char c)
{
	if (is_non_printable(*ch))
		c = 92;
	write(1, &c, 1);
	if ((*ch >= 1 && *ch <= 6) || (*ch >= 14 && *ch <= 31))
		c = *ch + 64;
	else if (*ch == '\0')
		c = '0';
	else if (*ch == '\a')
		c = 'a';
	else if (*ch == '\b')
		c = 'b';
	else if (*ch == '\t')
		c = 't';
	else if (*ch == '\n')
		c = 'n';
	else if (*ch == '\v')
		c = 'v';
	else if (*ch == '\f')
		c = 'f';
	else if (*ch == '\r')
		c = 'r';
	else if (*ch == '\e')
		c = 'e';
	write(1, &c, 1);
}

void	non_print_conversion(t_out *out, va_list ar, t_flags *oper)
{
	char	*str;
	int		len;
	int		n;

	oper = 0;
	len = 0;
	str = va_arg(ar, char*);
	n = -1;
	while (str[++n])
		((str[n] >= 0 && str[n] <= 31) || str[n] == 127 ||
			str[n + 1] == 0) ? (len += 1) : len;
	len += n;
	n++;
	out->out_len += len;
	while (n-- > 0)
	{
		if (*str >= 0 && *str <= 31)
			write_non_pritable(str, 94);
		else
			write(1, &*str, 1);
		str++;
	}
}
