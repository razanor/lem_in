/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:32:41 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/07 20:32:43 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

static void		collect_rooms2(int s, int end, t_rooms **rooms, char **table)
{
	t_rooms *tmp;

	tmp = *rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_rooms*)malloc(sizeof(t_rooms));
	tmp->next->roomName = ft_strdup(table[0]);
	tmp->next->x = ft_atoi(table[1]);
	tmp->next->y = ft_atoi(table[2]);
	tmp->next->isStart = s;
	tmp->next->isEnd = end;
	tmp->next->next = NULL;
}

void			map_saver(t_map *map)
{
	t_validMap *tmp;

	if (!(map->validMap))
	{
		map->validMap = (t_validMap*)malloc(sizeof(t_validMap));
		map->validMap->map = ft_strdup(map->str);
		map->validMap->next = NULL;
	}
	else
	{
		tmp = map->validMap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_validMap*)malloc(sizeof(t_validMap));
		tmp->next->map = ft_strdup(map->str);
		tmp->next->next = NULL;
	}
}

void			collect_rooms(char *str, t_rooms **rooms, int start, int end)
{
	char	**table;

	table = ft_strsplit(str, ' ');
	if (!(atoi(table[1]) >= 0 && (atoi(table[2]) >= 0) && is_digit(table[1])
	&& is_digit(table[2])))
		error();
	if (!(*rooms))
	{
		*rooms = (t_rooms*)malloc(sizeof(t_rooms));
		(*rooms)->roomName = ft_strdup(table[0]);
		(*rooms)->x = ft_atoi(table[1]);
		(*rooms)->y = ft_atoi(table[2]);
		(*rooms)->isStart = start;
		(*rooms)->isEnd = end;
		(*rooms)->next = NULL;
	}
	else
		collect_rooms2(start, end, rooms, table);
}

void			collect_links(char *str, t_links **links)
{
	char	**table;
	t_links	*tmp;

	table = ft_strsplit(str, '-');
	if (!(*links))
	{
		*links = (t_links*)malloc(sizeof(t_links));
		(*links)->from = ft_strdup(table[0]);
		(*links)->to = ft_strdup(table[1]);
		(*links)->next = NULL;
	}
	else
	{
		tmp = *links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_links*)malloc(sizeof(t_links));
		tmp->next->from = ft_strdup(table[0]);
		tmp->next->to = ft_strdup(table[1]);
		tmp->next->next = NULL;
	}
}
