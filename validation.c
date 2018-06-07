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

static void		mapSaver(t_map **map)
{
	t_validMap *tmp;

	if (!((*map)->validMap))
	{
		(*map)->validMap = (t_validMap*)malloc(sizeof(t_validMap));
		(*map)->validMap->map = ft_strdup((*map)->str);
		(*map)->validMap->next = NULL;
	}
	else
	{
		tmp = (*map)->validMap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_validMap*)malloc(sizeof(t_validMap));
		tmp->next->map = ft_strdup((*map)->str);
		tmp->next->next = NULL;
	}
}

void    comments_validation(t_map *map)
{
	if (*(map->str) == '#' && strcmp(map->str, "##start") 
		 && strcmp(map->str, "##end") && *(map->str + 1) != ' ')
			mapSaver(&map);
}

void    rooms_validation(t_map *map)
{
	if (atoi(map->str) && atoi(map->str) > 0 && !ft_strchr(map->str, ' ') && !ft_strchr(map->str, '-'))
		{ 
			map->ants = atoi(map->str);
			mapSaver(&map);
		}
		if (strcmp(map->str, "##start") == 0)
		{
			if (map->ants)
				mapSaver(&map);
			map->commandsFlag++;
			map->startFlag++;;
		}
		if ((ft_count_w(map->str, ' ')) == 3 && ft_count_char(map->str, ' ') == 2 
			&& *(map->str) != '#' && *(map->str) != 'L')
			{
				if (map->startFlag == 1 && map->endFlag != 1) // перевірка на випадок ##start ##end один за одним без кімнат між ними   
				{
					printf("%s\n", map->str);
					map->startFlag--;
				}
				if (map->endFlag == 1)
				{
					printf("%s\n", map->str);
					map->endFlag--;
				}
				mapSaver(&map);
				map->roomsFlag = 1;
			}
		if (strcmp(map->str, "##end") == 0)
		{
			mapSaver(&map);
			map->commandsFlag++;
			map->endFlag++;
		}
	// map->commandsFlag - перевірка чи були ##start i ##end по одному разу на карті
	// map->roomsFlag - перевірка чи є кімнати на карті
	// map->startFlag i map->endFlag служать для фіксації start або end кімнати яка йде після одної з команд на випадок якщо після команди йдуть коментарі
}

void    links_validation(t_map *map)
{
	if (ft_count_char(map->str, '-') == 1)
		mapSaver(&map);
}
