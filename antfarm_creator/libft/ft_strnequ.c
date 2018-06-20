/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:35:18 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:10:14 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((i < n || j < n) && (s1[i] != '\0' || s2[j] != '\0'))
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
