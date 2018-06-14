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

void	error(t_map *map) 
{
	if (map->str)
		ft_strdel(&(map->str));
	if (map->rooms)
		rooms_clean(&(map->rooms));
	if (map->links)
		links_clean(&(map->links));
	if (map->valid_map)
		map_clean(&(map->valid_map));
	ft_printf("ERROR\n");
	exit(1);
}	

void	enough_data_check(t_links **links, t_map *map)
{
	t_links *tmp;

	tmp = *links;
		while (tmp)
		{
			printf("%s", tmp->from);
			printf("-");
			printf("%s\n", tmp->to);
			tmp = tmp->next;
		}
		if (!(*links))
			error(map);
		printf("Here will be logic soon!\n");
	exit (1);
}

int		main(void)
{
	t_map 	map;

	map = (t_map){0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL};
	while (get_next_line(0, &(map.str)))
	{
		line_analyzer(&map);
		ft_strdel(&(map.str));
	}
	if (map.links_end == 0 || map.links_start == 0)
		error(&map);
	adjacency_matrix(&map);
	int i = 0;
	int	j = 0;
    while (i < map.mat_len)
    {
        j = 0;
        while (j < map.mat_len)
        {
            printf("%d", map.mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
	// here
	if (map.valid_map)
		printf("Ok\n");
	// while (map.rooms)
	// {
	// 	printf("name: %s\n", map.rooms->room_name);
	// 	printf("room_index: %d\n", map.rooms->room_index);
	// 	printf("x: %d\n", map.rooms->x);
	// 	printf("y: %d\n", map.rooms->y);
	// 	printf("startFLag: %d\n", map.rooms->is_start);
	// 	printf("endFlag: %d\n", map.rooms->is_end);
	// 	map.rooms = map.rooms->next;
	// }
	// 	while (map.links)
	// {
	// 	printf("%s", map.links->from);
	// 	printf("-");
	// 	printf("%s\n", map.links->to);
	// 	map.links = map.links->next;
	// }
	return (0);	
}

