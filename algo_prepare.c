/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:03:08 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/12 18:26:12 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    rooms_to_index(t_map *map)
{
    t_rooms *tmp;
    t_links *tmp2;
    int     len;

    len = 0;
    tmp = map->rooms;
    while (tmp)
    {
        tmp2 = map->links;
        while (tmp2)
        {
            if (ft_strcmp(tmp->room_name, tmp2->from) == 0)
                tmp2->from_index = tmp->room_index;
            else if (ft_strcmp(tmp->room_name, tmp2->to) == 0)
                tmp2->to_index = tmp->room_index;
                tmp2 = tmp2->next;
        }
        len++;
        tmp = tmp->next;
    }
    // while (map->links)
    // {
    //     printf("%d", map->links->from_index);
    //     printf("-");
    //     printf("%d\n", map->links->to_index);
    //     map->links = map->links->next;
    // }
    adjacency_matrix(map, len);
}

void    adjacency_matrix(t_map *map, int len)
{
    int **mat;
    int i;
    int j;
    t_links *tmp;

    i = 0;
    j = 0;
    mat = (int **)malloc(sizeof(int *) * len); // here
    while (i < len)
    {
        j = 0;
        while (j < len)
        {
            mat[i] = (int *)malloc(sizeof(int) * len);
            mat[i][j] = 0;
            j++;
        }
        i++;
    }
    tmp = map->links;
    while (tmp)
    {
        mat[tmp->from_index][tmp->to_index] = 1;
        mat[tmp->to_index][tmp->from_index] = 1;

        tmp = tmp->next;
    }
    i = 0;
    j = 0;
    while (i < len)
    {
        j = 0;
        while (j < len)
        {
            printf("%d", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    // here

}
