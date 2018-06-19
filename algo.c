/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:52:25 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/19 13:52:38 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int start_end_node(t_rooms *rooms, char flag)
{
    while (rooms)
    {
        if (rooms->is_start == 1 && flag == 's')
            return (rooms->room_index);
        else if (rooms->is_end == 1 && flag == 'e')
            return (rooms->room_index);
        rooms = rooms->next;
    }
    return (1);
}

static void add_path(int room, t_list **lst)
{
    t_list *tmp;

    if (!(*lst))
    {
        *lst = (t_list*)malloc(sizeof(t_list));
        (*lst)->content_size = room;
        (*lst)->next = NULL;
    }
    else
    {
        tmp = (t_list*)malloc(sizeof(t_list));
        tmp->content_size = room;
        tmp->next = (*lst);
        (*lst) = tmp;
    }
}

static void final_output(t_map *map, t_list **lst)
{
    t_valid_map *tmp;

    tmp = map->valid_map;
    while (tmp)
    {
        ft_printf("%s\n", tmp->map);
        tmp = tmp->next;
    }
    ft_printf("\n");
    path_output(map, lst);
}

static void find_links(int *m, int *end, t_map *map, t_list **lst)
{
    if (*m == *end)
    {
        add_path(map->visited[*m], lst);
        *end = map->visited[*m];
        *m = 0;
    }
}

void  get_path(t_map *map, t_queue *p, int k)
{
    int m;
    int end;
    t_list *lst;

    m = 0;
    lst = NULL;

    if (map->visited[p->end] != -1)
    {
        add_path(k, &lst);
        if (map->mat_len != 2)
            add_path(map->visited[p->end], &lst);
        m = 0;
        end = map->visited[p->end];
        while (m < map->mat_len)
        {
            find_links(&m, &end, map, &lst);
            m++;
        }
        final_output(map, &lst);
        free_all(map, ' ');
        exit(1);
    }
}
