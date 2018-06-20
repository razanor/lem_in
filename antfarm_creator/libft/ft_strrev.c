/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:27:31 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 11:46:51 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*srev;

	j = 0;
	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	srev = (char*)malloc(sizeof(char) * (i + 1));
	if (srev == NULL)
		return (NULL);
	while (i - 1 >= 0)
	{
		srev[j] = str[i - 1];
		j++;
		i--;
	}
	srev[j] = '\0';
	return (srev);
}
