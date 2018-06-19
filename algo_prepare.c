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

static void initialized_matrix(int **mat, t_links *links)
{
     while (links)
    {
        mat[links->from_index][links->to_index] = 1;
        mat[links->to_index][links->from_index] = 1;
        links = links->next;
    }
}

void    adjacency_matrix(t_map *map)
{
    t_rooms *tmp;
    t_links *tmp2;

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
        map->mat_len++;
        tmp = tmp->next;
    }
    map->mat = create_matrix(map->mat_len);
    initialized_matrix(map->mat, map->links);
}
 
static void  intit_variables(t_map *map, t_queue *params)
{
    map->visited = init_array(map->visited, map->mat_len, '-');
    map->queue = init_array(map->queue, map->mat_len, '0');
    params->start = start_end_node(map->rooms, 's');
    params->end = start_end_node(map->rooms, 'e'); 
    map->visited[params->start] = __INT_MAX__;
    map->queue[params->rear] = params->start; 
    params->rear++; 
}

void    shortest_way(t_map *map)
{
    t_queue params;
    int d;
    int k;

    params = (t_queue){0, 0, 0, 0};
    intit_variables(map, &params);
    while (params.rear != params.front)
    {
        d = map->queue[params.front];
        params.front++;
        k = 0;
        while (k < map->mat_len)
        {
            if (map->visited[k] == -1 && map->mat[d][k])
            {
                map->queue[params.rear] = k;
                params.rear++;
                map->visited[k] = d;
                get_path(map, &params, k);
            }
            k++;
        }
    }
     free_all(map, 'e');
}