/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:30:28 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		check_from_hitting(t_win *v, t_room *r, int x, int y)
{
	if (v->from_link_coords[X] == x &&
		v->from_link_coords[Y] == y && !v->to_check)
	{
		v->from_link_coords[X] = r->coords[X];
		v->from_link_coords[Y] = r->coords[Y];
		v->name1 = r->name;
		v->to_check = 1;
		return (1);
	}
	return (0);
}

static int		to_hitting(t_win *v, t_room *r)
{
	v->to_link_coords[X] = r->coords[X];
	v->to_link_coords[Y] = r->coords[Y];
	v->name2 = r->name;
	return (1);
}

int				is_room(t_win *v, int r_x, int r_y)
{
	t_room	*r;
	int		x;
	int		y;
	int		ret;

	r = v->rooms;
	ret = 0;
	v->to_check = 0;
	while (r)
	{
		y = r->coords[Y] - ROOM_SIZE / 2 - 10;
		while (++y < r->coords[Y] + ROOM_SIZE / 2 + 10)
		{
			x = r->coords[X] - ROOM_SIZE / 2 - 10;
			while (++x < r->coords[X] + ROOM_SIZE / 2 + 10)
			{
				ret += check_from_hitting(v, r, x, y);
				if (r_x == x && r_y == y)
					ret += to_hitting(v, r);
			}
		}
		r = r->next;
	}
	ret = (ret == 2) ? 1 : 0;
	return (ret);
}
