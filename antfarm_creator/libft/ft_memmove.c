/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:56:45 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:03:14 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*cdst;
	const char	*csrc;

	i = 0;
	cdst = dst;
	csrc = src;
	if (cdst > csrc && (csrc + len) > cdst)
	{
		while (len > 0)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (cdst);
}
