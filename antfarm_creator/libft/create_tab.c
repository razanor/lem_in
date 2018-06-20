/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:50:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:04:23 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**create_tab(int h, int w)
{
	int **tab;
	int y;

	tab = (int**)malloc(sizeof(int*) * h);
	y = -1;
	while (++y < h)
		tab[y] = (int*)ft_memalloc(sizeof(int) * w);
	return (tab);
}
