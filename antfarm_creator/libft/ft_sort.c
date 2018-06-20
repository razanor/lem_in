/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:55:50 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 11:47:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(char **str, int count)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (j < count - 1)
		{
			if (ft_strcmp(str[j], str[j + 1]) > 0)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
				j = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
