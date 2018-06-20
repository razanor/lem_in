/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:33:36 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:11:22 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const char *haystack, const char *needle, int i)
{
	int j;

	j = 0;
	while (haystack[i] == needle[j])
	{
		if (needle[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check(haystack, needle, i) == 1)
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
