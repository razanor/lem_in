/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:48:29 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/07 19:48:42 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ants_validation(t_map *map)
{
	if (!(map->ants))
	{
		map->ants = atoi(map->str);
		map_saver(map);
	}
	else
		free_all(map, 'e');
}

static	void	start_validation(t_map *map)
{
	if (map->ants)
	{
		map_saver(map);
		map->com_start_flag++;
		map->start_flag = 2;
		if (map->com_start_flag > 1)
			free_all(map, 'e');
	}
	else
		free_all(map, 'e');
}

static	void	rooms_validation(t_map *map)
{
	int start;
	int end;

	start = 0;
	end = 0;
	if (map->start_flag == 2 && map->end_flag != 2)
	{
		start = 1;
		map->start_flag--;
	}
	if (map->end_flag == 2)
	{
		end = 1;
		map->end_flag--;
	}
	map_saver(map);
	map->rooms_flag = 1;
	collect_rooms(map, start, end);
	unique_rooms(&(map->rooms), map);
}

static	void	links_validation(t_map *map)
{
	if (is_rooms(map->str, map->rooms, &(map->links_start), &(map->links_end)))
	{
		collect_links(map->str, &(map->links));
		map_saver(map);
	}
	else if (map->start_flag == 1 && map->end_flag == 1)
		enough_data_check(&(map->links), map);
}

void			line_analyzer(t_map *map)
{
	if (*(map->str) == '#' && strcmp(map->str, "##start")
	&& strcmp(map->str, "##end") && *(map->str + 1) != ' ')
		map_saver(map);
	else if (atoi(map->str) && atoi(map->str) > 0 && !ft_strchr(map->str, ' ')
	&& !ft_strchr(map->str, '-'))
		ants_validation(map);
	else if (strcmp(map->str, "##start") == 0)
		start_validation(map);
	else if ((ft_count_w(map->str, ' ')) == 3 &&
	ft_c_char(map->str, ' ') == 2 && *(map->str) != '#'
	&& *(map->str) != 'L' && map->ants && *(map->str) != '-')
		rooms_validation(map);
	else if (strcmp(map->str, "##end") == 0)
	{
		map_saver(map);
		map->com_end_flag++;
		map->end_flag = 2;
		if (map->com_end_flag > 1)
			free_all(map, 'e');
	}
	else if (ft_c_char(map->str, '-') == 1 && !ft_c_char(map->str, ' ') &&
	map->rooms_flag == 1 && map->com_start_flag == 1 && map->com_end_flag == 1)
		links_validation(map);
	else
		enough_data_check(&(map->links), map);
}
