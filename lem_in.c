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

void	error() {
	ft_printf("ERROR\n");
	exit(1);
}	

void	enough_data_check(t_links **links)
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
			error();
		printf("Here will be logic soon!\n");
	exit (1);
}

int		main(void)
{
	t_map 	map;

	map = (t_map){0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL};
	while (get_next_line(0, &(map.str)))
	{
		line_analyzer(&map);
		ft_strdel(&(map.str));
	}
	while (map.validMap)
	{
		printf("%s\n", map.validMap->map);
		map.validMap = map.validMap->next;
	}
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

