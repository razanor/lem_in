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
		error();
}

static	void	start_validation(t_map *map)
{
	if (map->ants)
	{
		map_saver(map);
		map->comStartFlag++;
		map->startFlag = 2;
		if (map->comStartFlag > 1)
			error();
	}
	else
		error();
}

static	void	rooms_validation(t_map *map)
{
	int start;
	int end;

	start = 0;
	end = 0;
	if (map->startFlag == 2 && map->endFlag != 2) // перевірка на випадок ##start ##end один за одним без кімнат між ними   
	{
		start = 1;
		map->startFlag--;
	}
	if (map->endFlag == 2)
	{
		end = 1;
		map->endFlag--;
	}
	map_saver(map);
	map->roomsFlag = 1;
	collect_rooms(map->str, &(map->rooms), start, end);
	unique_rooms(&(map->rooms));
}

static	void	links_validation(t_map *map)
{
	if (is_rooms(map->str, map->rooms))
	{
		collect_links(map->str, &(map->links));
		map_saver(map);
	}
	else if (map->startFlag == 1 && map->endFlag == 1)
		enough_data_check(&(map->links));
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
	ft_count_char(map->str, ' ') == 2 && *(map->str) != '#'
	&& *(map->str) != 'L' && map->ants && *(map->str) != '-')
		rooms_validation(map);
	else if (strcmp(map->str, "##end") == 0)
	{
		map_saver(map);
		map->comEndFlag++;
		map->endFlag = 2;
		if (map->comEndFlag > 1)
			error();
	}
	else if (ft_count_char(map->str, '-') == 1 && !ft_count_char(map->str, ' ')
	&& map->roomsFlag == 1 && map->comStartFlag == 1 && map->comEndFlag == 1)
		links_validation(map);
	else
		error();
	// map->commandsFlag - перевірка чи були ##start i ##end по одному разу на карті
	// map->roomsFlag - перевірка чи є кімнати на карті
	// map->startFlag i map->endFlag служать для фіксації start або end кімнати яка йде після одної з команд на випадок якщо після команди йдуть коментарі
}
