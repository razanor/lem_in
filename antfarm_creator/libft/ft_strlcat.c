/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:16:06 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:08:12 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lendst;
	size_t lensrc;
	size_t i;
	size_t j;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	j = lendst;
	if (dstsize < lendst)
		return (lensrc + dstsize);
	while ((j < dstsize - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (lendst + lensrc);
}
