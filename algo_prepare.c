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
 
void    shortest_way(t_map *map)
{
    t_queue params;
    int d;
    int k;

    params = (t_queue){0, 0, 0, 0};
    map->visited = init_array(map->visited, map->mat_len, '-');
    map->queue = init_array(map->queue, map->mat_len, '0');
    params.start = start_end_node(map->rooms, 's');
    params.end = start_end_node(map->rooms, 'e'); 
    map->visited[params.start] = __INT_MAX__; // make vertex start visited
    map->queue[params.rear] = params.start; // enqueue vertex start
    params.rear++; 
    while (params.rear != params.front) // condinion for empty queue
    {
        // dequeue
        d = map->queue[params.front];
        // if (d == params.end)
        //     break ;
        params.front++;
        // check adjacent nodes from dequeue node
        k = 0;
        while (k < map->mat_len)
        {
            // if there is adjacent vertex enqueue it
            if (map->visited[k] == -1 && map->mat[d][k])
            {
                map->queue[params.rear] = k;
                params.rear++;
                map->visited[k] = d;
                get_path(map, &params, k);
                // if (k == params.end)
                //     break ;
            }
            k++;
        }
    }
     free_all(map, 'e');
}
