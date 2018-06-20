/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:10:15 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:03:28 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	t;
	char			*str;

	i = 0;
	t = c;
	str = b;
	while (i < len)
	{
		str[i] = t;
		i++;
	}
	return ((void*)str);
}
