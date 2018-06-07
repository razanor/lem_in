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

int		main(void)
{
	t_map 	map;
	int		i;

	i = 0;
	map = (t_map){0, 0, 0, 0, 0, NULL, NULL, NULL, NULL};
	while (get_next_line(0, &(map.str)))
	{
		comments_validation(&map);
		rooms_validation(&map);
		links_validation(&map);
		i++;
	}
	if ((list_size(map.validMap)) == i && map.roomsFlag == 1 && map.commandsFlag == 2 && map.startFlag == 0 && map.endFlag == 0)
		printf("OK\n");
	else
		error();
	return (0);	
}

