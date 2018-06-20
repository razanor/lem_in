/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:50:10 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 12:57:21 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '0')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	value;

	i = 0;
	value = 0;
	sign = 1;
	i = ft_skip(str, i);
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		value = ((value * 10) + (str[i] - 48));
		i++;
	}
	if (value > 9223372036854775807 && sign == 1)
		return (-1);
	if (value > 9223372036854775807 && sign == -1)
		return (0);
	return (value * sign);
}
