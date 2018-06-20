/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:50:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:03:16 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_spaces(char *line)
{
	int i;
	int spaces;

	spaces = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			spaces++;
	}
	return (spaces);
}
