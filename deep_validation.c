/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:13:33 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/08 13:13:36 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	unique_rooms(t_rooms **rooms, t_map *map)
{
	t_rooms		*tmp;
	t_rooms		*tmp2;

	tmp2 = *rooms;
	if (tmp2->x < 0 || tmp2->y < 0)
		free_all(map, 'e');
	while (tmp2)
	{
		tmp = tmp2->next;
		while (tmp)
		{
			if ((strcmp(tmp2->room_name, tmp->room_name)) == 0 || (tmp2->x ==
			tmp->x && tmp2->y == tmp->y) || (tmp2->x < 0 || tmp2->y < 0))
				free_all(map, 'e');
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

static void	check_rooms(t_rooms *rooms, char **table, int *s, int *e)
{
	if (rooms->is_start == 1 && (!strcmp(table[0], rooms->room_name)
		|| !strcmp(table[1], rooms->room_name)))
			(*s)++;
	if (rooms->is_end == 1 && (!strcmp(table[0], rooms->room_name)
		|| !strcmp(table[1], rooms->room_name)))
			(*e)++;
}

static void same_rooms(t_rooms *rooms, char **table, int *flag)
{
	if (strcmp(rooms->room_name, table[0]) == 0)
		(*flag)++;
	if (strcmp(rooms->room_name, table[1]) == 0)
		(*flag)++;
}

_Bool	is_rooms(char *str, t_rooms *rooms, int *s, int *e)
{
	char	**table;
	int		flag;

	flag = 0;
	table = ft_strsplit(str, '-');
	if (table[0] && table[1] && strcmp(table[0], table[1]) == 0)
	{
		table_clean(table);
		return (FALSE);
	}
	while (rooms && table[0] && table[1])
	{
		check_rooms(rooms, table, s, e);
		same_rooms(rooms, table, &flag);
		rooms = rooms->next;
	}
	if (flag == 2)
	{
		table_clean(table);
		return (TRUE);
	}
	table_clean(table);
	return (FALSE);
}
