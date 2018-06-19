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

void			map_saver(t_map *map)
{
	t_valid_map *tmp;

	if (!(map->valid_map))
	{
		map->valid_map = (t_valid_map*)malloc(sizeof(t_valid_map));
		map->valid_map->map = ft_strdup(map->str);
		map->valid_map->next = NULL;
	}
	else
	{
		tmp = map->valid_map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_valid_map*)malloc(sizeof(t_valid_map));
		tmp->next->map = ft_strdup(map->str);
		tmp->next->next = NULL;
	}
}

static void		collect_rooms2(int s, int end, t_map *map, char **table)
{
	t_rooms *tmp;

	tmp = map->rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_rooms*)malloc(sizeof(t_rooms));
	tmp->next->room_name = ft_strdup(table[0]);
	tmp->next->x = ft_atoi(table[1]);
	tmp->next->y = ft_atoi(table[2]);
	tmp->next->is_start = s;
	tmp->next->is_end = end;
	tmp->next->room_index = tmp->room_index + 1; 
	tmp->next->next = NULL;
}

void			collect_rooms(t_map *map, int start, int end)
{
	char	**table;

	table = ft_strsplit(map->str, ' ');
	if (!(atoi(table[1]) >= 0 && (atoi(table[2]) >= 0) && is_digit(table[1])
	&& is_digit(table[2])))
		free_all(map, 'e');
	if (!(map->rooms))
	{
		map->rooms = (t_rooms*)malloc(sizeof(t_rooms));
		map->rooms->room_name = ft_strdup(table[0]);
		map->rooms->x = ft_atoi(table[1]);
		map->rooms->y = ft_atoi(table[2]);
		map->rooms->is_start = start;
		map->rooms->is_end = end;
		map->rooms->room_index = 0;
		map->rooms->next = NULL;
	}
	else
		collect_rooms2(start, end, map, table);
	table_clean(table);
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
	table_clean(table);
}
