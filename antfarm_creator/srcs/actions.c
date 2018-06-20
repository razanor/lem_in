/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:41:46 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:32:49 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	add_action(t_win *v, int type)
{
	int i;

	i = 0;
	while (v->actions[i] != -1)
		i++;
	v->actions[i] = type;
}

void	remove_room(t_win *v)
{
	t_room *r;
	t_room *prev;

	r = v->rooms;
	if (!r)
		return ;
	prev = r;
	while (r->next)
	{
		prev = r;
		r = r->next;
	}
	prev->next = NULL;
	if (v->rooms == r)
		v->rooms = NULL;
	if (r)
	{
		ft_strdel(&r->name);
		free(r);
		r = NULL;
	}
	v->room_nb--;
}

void	remove_link(t_win *v)
{
	t_link *l;
	t_link *prev;

	l = v->links;
	if (!l)
		return ;
	prev = l;
	while (l->next)
	{
		prev = l;
		l = l->next;
	}
	prev->next = NULL;
	if (v->links == l)
		v->links = NULL;
	if (l)
	{
		ft_strdel(&l->name1);
		ft_strdel(&l->name2);
		free(l);
		l = NULL;
	}
}

void	undo_action(t_win *v)
{
	int i;

	i = 0;
	while (v->actions[i] != -1)
		i++;
	if (i - 1 < 0)
		return ;
	if (v->actions[i - 1] == ADD_ROOM)
		remove_room(v);
	else if (v->actions[i - 1] == ADD_LINK)
		remove_link(v);
	else if (v->actions[i - 1] == SET_START)
		v->start->type = 'n';
	else if (v->actions[i - 1] == SET_END)
		v->end->type = 'n';
	v->actions[i - 1] = -1;
}
