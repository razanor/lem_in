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

void	unique_rooms(t_rooms **rooms)
{
	t_rooms		*tmp;
	t_rooms		*tmp2;

	tmp = *rooms;
	tmp2 = *rooms;
	if (tmp2->x < 0 || tmp2->y < 0)
		error();
	while (tmp2)
	{
		tmp = tmp2->next;
		while (tmp)
		{
			if ((strcmp(tmp2->room_name, tmp->room_name)) == 0 || (tmp2->x ==
			tmp->x && tmp2->y == tmp->y) || (tmp2->x < 0 || tmp2->y < 0))
				error();
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

_Bool	is_rooms(char *str, t_rooms *rooms)
{
	char	**table;
	int		flag;

	flag = 0;
	table = ft_strsplit(str, '-');
	if (table[0] && table[1] && strcmp(table[0], table[1]) == 0)
		return (FALSE);
	while (rooms && table[0] && table[1])
	{
		if (strcmp(rooms->room_name, table[0]) == 0)
			flag++;
		if (strcmp(rooms->room_name, table[1]) == 0)
			flag++;
		rooms = rooms->next;
	}
	if (flag == 2)
		return (TRUE);
	return (FALSE);
}
