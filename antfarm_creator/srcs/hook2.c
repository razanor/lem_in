/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:55:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:26:52 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		program_exit(t_win *v)
{
	(void)v;
	exit(0);
}

int		key_off(int keycode, t_win *v)
{
	if (keycode == SPACE)
		v->space_on = 0;
	if (keycode == E)
		v->setting_e = 0;
	if (keycode == S)
		v->setting_s = 0;
	return (0);
}

int		mouse_off(int button, int x, int y, t_win *v)
{
	int i;
	int j;

	i = x;
	j = y;
	if (button == 1 && v->space_on)
	{
		v->mouse_on = 0;
		add_link(v, x, y);
	}
	return (0);
}

int		mouse_move(int x, int y, t_win *v)
{
	if (v->mouse_on && v->space_on)
	{
		v->to_link_coords[X] = x;
		v->to_link_coords[Y] = y;
		draw_linking(v);
	}
	return (0);
}
