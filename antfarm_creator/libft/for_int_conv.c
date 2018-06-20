/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:02:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:05:35 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size(long long int n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*f_int_base(long long int n, int base)
{
	int						size;
	int						neg;
	char					*str;
	unsigned long long int	num;

	num = n;
	neg = 0;
	if (base == 10 && n < 0)
	{
		num = n * (-1);
		neg = 1;
	}
	size = ft_size(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (size + neg + 1))))
		return (NULL);
	str[(size--) + neg] = '\0';
	while (size + neg >= 0)
	{
		str[size + neg] = (num % base) + ((num % base) >= 10 ? 'a' - 10 : '0');
		num = num / base;
		size--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static int		ft_unsigned_size(unsigned long long int n, int base)
{
	int size;

	size = 0;
	if (n == 0 && base != 2)
		size++;
	else if (n == 0 && base == 2)
		size = 8;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	while ((size % 8) != 0 && base == 2)
		size++;
	return (size);
}

char			*f_unsigned_int(unsigned long long int n, int base)
{
	int			size;
	char		*str;
	int			spaces;

	spaces = 0;
	size = ft_unsigned_size(n, base);
	if (base == 2)
		spaces = ((size / 8) - 1);
	size += spaces;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = (n % base) + ((n % base) >= 10 ? 'a' - 10 : '0');
		if (base == 2 && ((size - spaces) % 8) == 0)
		{
			str[--size] = ' ';
			spaces--;
		}
		n = n / base;
	}
	return (str);
}
