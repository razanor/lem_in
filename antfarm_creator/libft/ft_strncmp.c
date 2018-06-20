/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:31:53 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:09:38 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					dif;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	dif = 0;
	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	while (dif == 0 && i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		dif = str1[i] - str2[i];
		i++;
	}
	return (dif);
}
