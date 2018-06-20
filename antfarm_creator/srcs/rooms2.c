/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:41:46 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:24:23 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	check_type(t_win *v, t_room *r, char type)
{
	if (type == 's')
	{
		r->type = type;
		v->start = r;
		add_action(v, SET_START);
	}
	else if (type == 'e')
	{
		r->type = type;
		v->end = r;
		add_action(v, SET_END);
	}
}

int			overlapping(t_win *v, int r_x, int r_y)
{
	t_room	*r;
	int		x;
	int		y;

	r = v->rooms;
	while (r)
	{
		y = r->coords[Y] - (ROOM_SIZE / 2 - 1) - (ROOM_SIZE * 2);
		while (++y < r->coords[Y] + ROOM_SIZE / 2 + (ROOM_SIZE * 2))
		{
			x = r->coords[X] - (ROOM_SIZE / 2 - 1) - (ROOM_SIZE * 2);
			while (++x < r->coords[X] + ROOM_SIZE / 2 + (ROOM_SIZE * 2))
			{
				if (r_x == x && r_y == y)
					return (1);
			}
		}
		r = r->next;
	}
	return (0);
}

void		set_room(t_win *v, int r_x, int r_y, char type)
{
	t_room	*r;
	int		x;
	int		y;

	r = v->rooms;
	while (r)
	{
		y = r->coords[Y] - (ROOM_SIZE / 2 - 1);
		while (++y < r->coords[Y] + ROOM_SIZE / 2)
		{
			x = r->coords[X] - (ROOM_SIZE / 2 - 1);
			while (++x < r->coords[X] + ROOM_SIZE / 2)
			{
				if (r_x == x && r_y == y)
				{
					check_type(v, r, type);
					return ;
				}
			}
		}
		r = r->next;
	}
}
