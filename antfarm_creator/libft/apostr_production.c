/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apostr_production.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:00 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:52:37 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_apostr(t_out *out, char *str, int value_len, int size)
{
	int	ap;

	ap = 0;
	str[size] = '\0';
	while (size > out->minus_sign)
	{
		str[--size] = out->value[--value_len];
		ap++;
		if (ap == 3)
		{
			str[--size] = ',';
			ap = 0;
		}
	}
	out->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

void	apostr_production(t_out *out)
{
	char	*str;
	int		size;
	int		ap;

	ap = 0;
	out->value_len -= out->minus_sign;
	(out->value_len != 3) ? (ap = out->value_len / 3) : ap;
	((out->value_len % 3) == 0 && (out->value_len != 3)) ? (ap -= 1) : ap;
	out->value_len += out->minus_sign;
	size = out->value_len + ap;
	str = (char*)malloc(sizeof(char) * (size + 1));
	str = str_apostr(out, str, out->value_len, size);
	free(out->value);
	out->value = str;
	out->value_len = ft_strlen(out->value);
}

char	*str_f_apostr(t_out *out, char *str, int size)
{
	int ap;

	ap = 0;
	str[size] = '\0';
	while (out->d.fr_size-- > 0)
		str[--size] = out->value[out->d.fr_size + out->d.i_size];
	while (size > out->minus_sign)
	{
		str[--size] = out->value[--out->d.i_size];
		ap++;
		if (ap == 3)
		{
			str[--size] = ',';
			ap = 0;
		}
	}
	out->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

void	apostr_f_production(t_out *out)
{
	char	*str;
	int		size;
	int		ap;

	ap = 0;
	out->d.i_size = 0;
	while (out->value[out->d.i_size] != '.' &&
			out->value[out->d.i_size] != '\0')
		out->d.i_size++;
	out->d.fr_size = 0;
	while (out->value[out->d.i_size + out->d.fr_size] != '\0')
		out->d.fr_size++;
	out->d.i_size -= out->minus_sign;
	(out->d.i_size != 3) ? (ap = out->d.i_size / 3) : ap;
	((out->d.i_size % 3) == 0 && (out->d.i_size != 3)) ? (ap -= 1) : ap;
	out->d.i_size += out->minus_sign;
	size = out->d.i_size + out->d.fr_size + ap;
	str = (char*)malloc(sizeof(char) * (size + 1));
	str = str_f_apostr(out, str, size);
	free(out->value);
	out->value = str;
	out->value_len = ft_strlen(out->value);
}
