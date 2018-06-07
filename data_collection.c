/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:32:41 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/07 20:32:43 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    collect_rooms(char *str, t_rooms **rooms, int start, int end)
{
    char    **table;
    t_rooms *tmp;

    table = ft_strsplit(str, ' ');

	if (!(*rooms))
	{
	     *rooms = (t_rooms*)malloc(sizeof(t_rooms));
		(*rooms)->roomName = ft_strdup(table[0]);
        (*rooms)->x = ft_atoi(table[1]);
        (*rooms)->y = ft_atoi(table[2]);
		(*rooms)->isStart = start;
        (*rooms)->isEnd = end;
        (*rooms)->next = NULL;
        //here
	}
	else
	{
		tmp = *rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_rooms*)malloc(sizeof(t_rooms));
		tmp->next->roomName = ft_strdup(table[0]);
        tmp->next->x = ft_atoi(table[1]);
        tmp->next->y = ft_atoi(table[2]);
        tmp->next->isStart = start;
        tmp->next->isEnd = end;
		tmp->next->next = NULL;
	}

}
