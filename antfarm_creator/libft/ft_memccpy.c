/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:23:30 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:01:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			t;
	unsigned char			*cdst;
	const unsigned char		*csrc;

	i = 0;
	t = (unsigned char)c;
	cdst = (unsigned char*)dst;
	csrc = (const unsigned char*)src;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == t)
			return (cdst + i + 1);
		i++;
	}
	return (NULL);
}
