/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:26 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/21 14:07:28 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str_one_more(t_out *out, char *time, int size)
{
	while (size > 8)
	{
		time[--size] = ((int)out->time.day % 10) + 48;
		out->time.day /= 10;
	}
	time[--size] = '-';
	while (size > 5)
	{
		time[--size] = ((int)out->time.month % 10) + 48;
		out->time.month /= 10;
	}
	time[--size] = '-';
	while (size > 0)
	{
		time[--size] = ((int)out->time.year % 10) + 48;
		out->time.year /= 10;
	}
	return (time);
}

char	*get_time_str(t_out *out)
{
	char	*time;
	int		size;

	size = 16;
	time = (char*)malloc(sizeof(char) * (size + 1));
	time[size] = '\0';
	while (size > 14)
	{
		time[--size] = ((int)out->time.min % 10) + 48;
		out->time.min /= 10;
	}
	time[--size] = ':';
	while (size > 11)
	{
		time[--size] = ((int)out->time.hour % 10) + 48;
		out->time.hour /= 10;
	}
	time[--size] = 'T';
	return (get_str_one_more(out, time, size));
}

void	time_conversion(t_out *out, va_list ar, t_flags *oper)
{
	long long int	date;
	int				in_year;

	oper = 0;
	date = va_arg(ar, long long int);
	in_year = (date / 31556926);
	out->time.year = in_year + 1970;
	out->time.month = (date / 2629743.83) - in_year * 12 + 1;
	out->time.day = (date / 86400) - in_year * 365.24 - 30;
	out->time.hour = (date / 60 / 60) % 24 + 2;
	out->time.min = (date / 60) % 60;
	out->value = get_time_str(out);
	out->value_len = ft_strlen(out->value);
	write(1, out->value, out->value_len);
	out->out_len += out->value_len;
}
