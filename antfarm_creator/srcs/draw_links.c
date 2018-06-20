/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:52:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:33:26 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_linking(t_win *v)
{
	t_ln	line;
	char	*num;

	line.font = -2;
	redraw(v);
	while (++line.font < 2)
	{
		line.x1 = v->from_link_coords[X];
		line.y1 = v->from_link_coords[Y];
		line.x2 = v->to_link_coords[X];
		line.y2 = v->to_link_coords[Y];
		draw_line(&line, v);
	}
	mlx_put_image_to_window(v->p.mlx_ptr, v->p.win_ptr, v->p.img_ptr, 0, 0);
	put_room_names(v);
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, 50, 50, 0xffffff, "ANTS");
	num = ft_itoa(v->ants_num);
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, 50, 80, 0xffffff, num);
	ft_strdel(&num);
}

void	draw_links(t_win *v)
{
	t_link	*l;
	t_ln	line;

	l = v->links;
	while (l)
	{
		line.font = -2;
		while (++line.font < 2)
		{
			line.x1 = l->from_link_coords[X];
			line.y1 = l->from_link_coords[Y];
			line.x2 = l->to_link_coords[X];
			line.y2 = l->to_link_coords[Y];
			draw_line(&line, v);
		}
		l = l->next;
	}
}
