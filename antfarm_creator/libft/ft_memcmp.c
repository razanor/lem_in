/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:05:41 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:02:25 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					dif;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	dif = 0;
	while (dif == 0 && n > 0)
	{
		dif = *str1 - *str2;
		str1++;
		str2++;
		n--;
	}
	return (dif);
}
