/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:07:51 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/05 15:53:05 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					char_to_int(int c)
{
	char	s[12];
	char	*hex;
	int		i;
	int		result;

	i = 0;
	result = 0;
	hex = ft_memmove(s, "aAbBcCdDeEfF", 12);
	while (result == 0 && hex[i] != '\0')
	{
		if (hex[i] == c)
			result = 10 + (i / 2);
		i++;
	}
	return (result);
}

unsigned int		ft_atoi_hex(char *s)
{
	unsigned int	value;
	int				i;

	i = 0;
	value = 0;
	while (s[i] != 'x' && s[i])
		i++;
	if (s[i] == 'x')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			value = (value * 16) + (s[i] - '0');
		else
			value = (value * 16) + char_to_int(s[i]);
		i++;
	}
	return (value);
}
