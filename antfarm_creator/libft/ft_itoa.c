/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:52:17 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 12:58:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int p)
{
	size_t size;

	size = 0;
	if (p <= 0)
		size++;
	while (p != 0)
	{
		p = p / 10;
		size++;
	}
	return (size);
}

static void		ft_result(char *s, int n, int size)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = n;
	if (n < 0)
	{
		s[i++] = '-';
		num = n * (-1);
	}
	while (size - 1 >= i)
	{
		s[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	int			size;
	char		*str;

	size = ft_size(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_result(str, n, size);
	str[size] = '\0';
	return (str);
}
