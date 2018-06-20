/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:55:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:55:37 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		mouse_hook(int button, int x, int y, t_win *v)
{
	if (button == LEFT_MOUSE)
	{
		if (!v->space_on)
			add_room(v, x, y);
		else if (v->space_on)
		{
			v->from_link_coords[X] = x;
			v->from_link_coords[Y] = y;
			v->mouse_on = 1;
		}
		if (v->setting_e)
			set_room(v, x, y, 'e');
		if (v->setting_s)
			set_room(v, x, y, 's');
	}
	redraw(v);
	return (0);
}

void	delete_map(t_win *v)
{
	t_link *l;
	t_room *r;

	l = v->links;
	r = v->rooms;
	while (l)
	{
		ft_strdel(&l->name1);
		ft_strdel(&l->name2);
		free(l);
		l = l->next;
	}
	while (r)
	{
		ft_strdel(&r->name);
		free(r);
		r = r->next;
	}
	param_init(v);
}

int		key_hook(int keycode, t_win *v)
{
	if (keycode == ESC)
		program_exit(v);
	if (keycode == SPACE)
		v->space_on = 1;
	if (keycode == E)
		v->setting_e = 1;
	if (keycode == S)
		v->setting_s = 1;
	if (keycode == ENTER)
		run_lemin(v);
	if (keycode == DELETE)
		delete_map(v);
	if (keycode == PLUS && (v->ants_num + 1) <= 100)
		v->ants_num++;
	if (keycode == MINUS && (v->ants_num - 1) >= 1)
		v->ants_num--;
	if (keycode == BACKSPACE)
		undo_action(v);
	redraw(v);
	return (0);
}
