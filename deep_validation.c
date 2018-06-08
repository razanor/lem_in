/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:13:33 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/08 13:13:36 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

_Bool   unique_rooms(t_rooms **rooms)
{
    t_rooms *tmp;
    t_rooms *tmp2;

    tmp = *rooms;
    tmp2 = *rooms;
    while (tmp2)
    {
        tmp = tmp2;
        while (tmp->next)
        {
            if ((strcmp(tmp->roomName, tmp->next->roomName)) == 0 || (tmp->x == tmp->next->x && tmp->y == tmp->next->y))
                return (FALSE);
            tmp = tmp->next;
        }
        tmp2 = tmp2->next;
    }
    return (TRUE);
}


