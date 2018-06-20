/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_analize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:53:22 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_color(const char *format, int j, int i)
{
	char	color[100];

	while (format[++j] != '}')
		color[i++] = format[j];
	color[i] = '\0';
	if (!(ft_strcmp(color, "white")))
		write(1, WHITE_TEXT, 8);
	else if (!(ft_strcmp(color, "red")))
		write(1, RED_TEXT, 8);
	else if (!(ft_strcmp(color, "green")))
		write(1, GREEN_TEXT, 8);
	else if (!(ft_strcmp(color, "yellow")))
		write(1, YELLOW_TEXT, 8);
	else if (!(ft_strcmp(color, "blue")))
		write(1, BLUE_TEXT, 8);
	else if (!(ft_strcmp(color, "magneta")))
		write(1, MAGNETA_TEXT, 8);
	else if (!(ft_strcmp(color, "cyan")))
		write(1, CYAN_TEXT, 8);
	else if (!(ft_strcmp(color, "eoc")))
		write(1, EOC, 5);
	else
		return (0);
	return (i + 2);
}

int		output_length(const char *format, va_list ar, t_out *out)
{
	int		j;
	int		format_len;

	j = -1;
	format_len = ft_strlen(format);
	while (++j < format_len)
	{
		(format[j] == '{') ? (j += check_color(format, j, 0)) : j;
		if (format[j] == '%')
		{
			j = write_format(out, format, ar, ++j);
			(!(out->f.conversion)) ? (out->value = ft_strdup(&format[j])) : 0;
			output_analize(out, ar);
			reset_values(out);
		}
		else
		{
			write(1, &format[j], 1);
			out->out_len++;
		}
	}
	return (out->out_len);
}
