/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:07:47 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/05 17:36:38 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	enough_data_check(t_links **links, t_map *map)
{
	if (!(*links))
		free_all(map, 'e');
	else
	{
		adjacency_matrix(map);
		shortest_way(map);
	}
}

int		main(void)
{
	t_map	map;

	map = (t_map){0, 0, 0, 0, 0, 0, 0, 0, 0,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	while (get_next_line(0, &(map.str)) == 1)
	{
		line_analyzer(&map);
		ft_strdel(&(map.str));
	}
	if (map.links_end == 0 || map.links_start == 0)
		free_all(&map, 'e');
	adjacency_matrix(&map);
	shortest_way(&map);
	return (0);
}
