/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:33:36 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:10:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const char *htk, const char *ndl, size_t i, size_t len)
{
	int j;

	j = 0;
	while (htk[i] == ndl[j] && i < len)
	{
		if (ndl[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char			*ft_strnstr(const char *htk, const char *ndl, size_t len)
{
	size_t i;

	i = 0;
	if (ndl[0] == '\0')
		return ((char*)htk);
	while (i < len && htk[i] != '\0')
	{
		if (htk[i] == ndl[0])
		{
			if (ft_check(htk, ndl, i, len) == 1)
				return ((char*)&htk[i]);
		}
		i++;
	}
	return (NULL);
}
