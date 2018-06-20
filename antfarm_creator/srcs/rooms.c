/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:41:46 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:15:38 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_room	*create_room(t_win *v, int x, int y)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_itoa(v->room_nb);
	room->coords[X] = x;
	room->coords[Y] = y;
	room->type = 'n';
	room->next = NULL;
	return (room);
}

void	add_room_to_list(t_room **rooms, t_room *new)
{
	t_room *temp;

	temp = *rooms;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	add_room(t_win *v, int x, int y)
{
	if (overlapping(v, x, y))
		return ;
	if (!v->rooms)
		v->rooms = create_room(v, x, y);
	else
		add_room_to_list(&v->rooms, create_room(v, x, y));
	v->room_nb++;
	add_action(v, ADD_ROOM);
}
