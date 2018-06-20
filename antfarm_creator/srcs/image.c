/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/26 17:32:55 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	clear_image(t_win *v)
{
	ft_bzero(v->p.image, (size_t)(WIDTH * HEIGHT * v->p.bpp));
}

void	redraw(t_win *v)
{
	char *num;

	clear_image(v);
	draw_links(v);
	draw_room(v);
	if (!v->mouse_on)
	{
		mlx_put_image_to_window(v->p.mlx_ptr, v->p.win_ptr, v->p.img_ptr, 0, 0);
		put_room_names(v);
		mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, 50, 50, 0xffffff, "ANTS");
		num = ft_itoa(v->ants_num);
		mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, 50, 80, 0xffffff, num);
		ft_strdel(&num);
	}
}

void	put_img_pixel(t_win *v, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int*)(v->p.image + (x + y * WIDTH) * v->p.bpp) = color;
}
