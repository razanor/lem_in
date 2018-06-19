/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:13:24 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/19 14:13:26 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	rooms_clean(t_rooms **rooms)
{
	t_rooms *tmp;

	while (*rooms)
	{
		ft_strdel(&((*rooms)->room_name));
		tmp = *rooms;
		*rooms = (*rooms)->next;
		free(tmp);
	}
}

static	void	map_clean(t_valid_map **valid_map)
{
	t_valid_map *tmp;

	while (*valid_map)
	{
		ft_strdel(&((*valid_map)->map));
		tmp = *valid_map;
		*valid_map = (*valid_map)->next;
		free(tmp);
	}
}

static	void	links_clean(t_links **links)
{
	t_links *tmp;

	while (*links)
	{
		ft_strdel(&((*links)->from));
		ft_strdel(&((*links)->to));
		tmp = *links;
		*links = (*links)->next;
		free(tmp);
	}
}

static void		mat_clean(int **mat, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void			free_all(t_map *map, char flag)
{
	if (map->str)
		ft_strdel(&(map->str));
	if (map->rooms)
		rooms_clean(&(map->rooms));
	if (map->links)
		links_clean(&(map->links));
	if (map->valid_map)
		map_clean(&(map->valid_map));
	if (map->mat)
		mat_clean(map->mat, map->mat_len);
	if (map->visited)
		free(map->visited);
	if (map->queue)
		free(map->queue);
	if (flag == 'e')
		ft_printf("ERROR\n");
	exit(1);
}
