/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:07:26 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:02:06 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*str;
	unsigned char			t;

	i = 0;
	str = (const unsigned char*)s;
	t = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == t)
			return ((void*)&str[i]);
		i++;
	}
	return (NULL);
}
