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

static 	void	error() {
	ft_printf("ERROR\n");
	exit(1);
}	

void	enough_data_check(t_links **links)
{
		while (*links)
	{
		printf("%s", (*links)->from);
		printf("-");
		printf("%s\n", (*links)->to);
		*links = (*links)->next;
	}
	printf("Here will be logic soon!\n");
	exit (1);
}

int		main(void)
{
	t_map 	map;
	int		i;

	i = 0;
	map = (t_map){0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL};
	while (get_next_line(0, &(map.str)))
	{
		comments_validation(&map);
		rooms_validation(&map);
		if (map.linksFlag == 1)
		{
			if (!links_validation(&map))
				enough_data_check(&(map.links));
		}
		ft_strdel(&(map.str));
		i++;
	}
	if ((list_size(map.validMap)) == i && map.roomsFlag == 1 && map.commandsFlag == 2 && map.startFlag == 0 && map.endFlag == 0)
		printf("OK\n");
	else
		error();
	// while (map.rooms)
	// {
	// 	printf("name: %s\n", map.rooms->roomName);
	// 	printf("x: %d\n", map.rooms->x);
	// 	printf("y: %d\n", map.rooms->y);
	// 	printf("start: %d\n", map.rooms->isStart);
	// 	printf("end: %d\n", map.rooms->isEnd);
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

