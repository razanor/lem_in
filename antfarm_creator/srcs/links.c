/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:23:17 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_link	*create_link(t_win *v)
{
	t_link *link;

	link = (t_link*)malloc(sizeof(t_link));
	link->name1 = ft_strdup(v->name1);
	link->name2 = ft_strdup(v->name2);
	link->from_link_coords[X] = v->from_link_coords[X];
	link->from_link_coords[Y] = v->from_link_coords[Y];
	link->to_link_coords[X] = v->to_link_coords[X];
	link->to_link_coords[Y] = v->to_link_coords[Y];
	link->next = NULL;
	return (link);
}

void	add_link_to_list(t_link **links, t_link *new)
{
	t_link *temp;

	temp = *links;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	add_link(t_win *v, int x, int y)
{
	if (!(is_room(v, x, y)) || ft_strequ(v->name2, v->name1))
		return ;
	if (!v->links)
		v->links = create_link(v);
	else
		add_link_to_list(&v->links, create_link(v));
	add_action(v, ADD_LINK);
}
