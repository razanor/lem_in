/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:55:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:32:11 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_square(t_win *v, int x_center, int y_center, int color)
{
	int x;
	int y;

	y = y_center - (ROOM_SIZE / 2 - 1);
	while (++y < y_center + (ROOM_SIZE / 2))
	{
		x = x_center - (ROOM_SIZE / 2 - 1);
		while (++x < x_center + (ROOM_SIZE / 2))
			put_img_pixel(v, x, y, color);
	}
}

void	put_room_names(t_win *v)
{
	t_room *r;

	r = v->rooms;
	while (r)
	{
		if (r->type == 's')
			mlx_string_put(v->p.mlx_ptr, v->p.win_ptr,
			r->coords[X] - ROOM_SIZE / 2.8,
			r->coords[Y] - ROOM_SIZE / 1.8, 0xffffff, "s");
		else if (r->type == 'e')
			mlx_string_put(v->p.mlx_ptr, v->p.win_ptr,
			r->coords[X] - ROOM_SIZE / 2.8,
			r->coords[Y] - ROOM_SIZE / 1.8, 0xffffff, "e");
		else
			mlx_string_put(v->p.mlx_ptr, v->p.win_ptr,
			r->coords[X] - ROOM_SIZE / 2.8,
			r->coords[Y] - ROOM_SIZE / 1.8, 0xffffff, r->name);
		r = r->next;
	}
}

void	draw_room(t_win *v)
{
	t_room *r;

	r = v->rooms;
	while (r)
	{
		if (r->type == 's')
			draw_square(v, r->coords[X], r->coords[Y], START);
		else if (r->type == 'e')
			draw_square(v, r->coords[X], r->coords[Y], END);
		else
			draw_square(v, r->coords[X], r->coords[Y], ROOM);
		r = r->next;
	}
}
