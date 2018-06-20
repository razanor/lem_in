/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:12:09 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:04:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(int **tab, int h, int w)
{
	int y;
	int x;

	y = -1;
	x = -1;
	ft_printf("    ");
	while (++x < w)
		ft_printf("{blue}%i  {eoc}", x);
	ft_printf("\n");
	while (++y < h)
	{
		x = -1;
		ft_printf("{blue}%-3i{eoc}| ", y);
		while (++x < w)
			ft_printf("%i ", tab[y][x]);
		ft_printf("|\n");
	}
}
