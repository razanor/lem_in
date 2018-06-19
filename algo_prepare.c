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

static  int start_end_node(t_rooms *rooms, char flag)
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

static void put_rooms_name(t_list **lst, t_rooms *rooms)
{
    t_list *tmp;

    while (rooms)
    {
        tmp = *lst;
        while (tmp)
        {
            if (rooms->room_index == (int)tmp->content_size)
                tmp->content = ft_strdup(rooms->room_name);
            tmp = tmp->next;
        }  
        rooms = rooms->next; 
    }
}

// static void set_flags_to_zero(t_list **lst)
// {
//     t_list *tmp;

//     tmp = *lst;
//     while (tmp)
//     {
//         tmp->flag = 0;
//         tmp = tmp->next;
//     }
// }

// static int check_if_one(t_list **lst)
// {
//     t_list *tmp;

//     tmp = *lst;
//     while (tmp)
//     {
//         if (tmp->flag == 1)
//             return (1);
//         tmp = tmp->next;
//     }
//     return (0);
// }

static void ft_print_lem(int ant, int ind, t_list *lst, int size)
{
    int i;

    i = ind ? size - ind : size - 1 ;
    // printf("%d%d%d\n", i,size,ind);
    while (--i)
        lst = lst->next;
    ft_printf("L%d-%s ", ant, lst->content);
}

static int  ft_lst_size(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

static void ft_shift(int ant, int *arr, int all_ant, int len)
{
    int i;

    i = 0;
    while (i < len - 1)
    {
        arr[i] = arr[i + 1];
        // printf("T%d ", ant);     
        i++;
    }
    // printf("%d\n", i);       
    if (ant < all_ant)
        arr[i] =  ant + 1;
    else
        arr[i] = 0;
    // i = 0;
    // while (i < 4)
    // {
    //     printf("G%d ", arr[i++]);
    // }
    // printf("\n");
}

static int ft_zero(int *arr,int len)
{
    int i;

    i = -1;
    while(++i < len)
        if (arr[i])
            return (1);
    return (0);        
}

static void path_output(t_map *map, t_list **lst)
{
    int len = ft_lst_size(*lst);
    int arr[len];
    ft_bzero(arr, len * 4);
    int     i;
    int     j;

    i = 1;
    arr[len - 1] = 1;
    *lst = (*lst)->next;
    put_rooms_name(lst, map->rooms);
    while (ft_zero(arr, len))
    {
        j = 0;
        while (j < len)
        {     
            if (arr[j] && j)
                ft_print_lem(arr[j], j, *lst, len);
            j++;
        }
        ft_shift(i, arr, map->ants, len);
        if (ft_zero(arr, len) && map->mat_len != 2)
            ft_printf("\n");        
        i++;
    }
    if (map->mat_len == 2)
        ft_printf("\n");
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


static void  get_path(t_map *map, t_queue *p, int k)
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
            if (m == end)
            {
                add_path(map->visited[m], &lst); //  кімнату старту не потрібно в найкоротшому шляху
                end = map->visited[m];
                m = 0;
            }
            m++;
        }
        final_output(map, &lst);
        exit (1);
    }
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
            }
            k++;
        }
    }
     error(map);
    // int i = 0;
	// int	j = 0;
    // while (i < map->mat_len)
    // {
    //     j = 0;
    //     while (j < map->mat_len)
    //     {
    //         ft_printf("%d", map->mat[i][j]);
    //         j++;
    //     }
    //     ft_printf("\n");
    //     i++;
    // }
}
