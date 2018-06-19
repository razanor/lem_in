/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:00:04 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/19 14:01:18 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static void ft_shift(int ant, int *arr, int all_ant, int len)
{
    int i;

    i = 0;
    while (i < len - 1)
    {
        arr[i] = arr[i + 1];     
        i++;
    }       
    if (ant < all_ant)
        arr[i] =  ant + 1;
    else
        arr[i] = 0;
}

static void ft_print_lem(int ant, int ind, t_list *lst, int size)
{
    int i;

    i = ind ? size - ind : size - 1 ;
    while (--i)
        lst = lst->next;
    ft_printf("L%d-%s", ant, lst->content);
    if (size == 2)
            ft_printf(" ");
}

void path_output(t_map *map, t_list **lst)
{
    int len = ft_lst_size(*lst);
    t_list *t;
    int arr[len];
    ft_bzero(arr, len * 4);
    int     i;
    int     j;
    int     space;

    space = 0;
    i = 1;
    arr[len - 1] = 1;
    t = *lst;
    *lst = (*lst)->next;
      free(t);
    put_rooms_name(lst, map->rooms);
        while (ft_zero(arr, len))
    {
        j = 0;
        while (j < len)
        {     
            if (arr[j] && j)
            {
                if (space++)
                    ft_printf(" ");
                ft_print_lem(arr[j], j, *lst, len);
            }
            j++;
        }
        space = 0;
        ft_shift(i, arr, map->ants, len);
        if (ft_zero(arr, len) && len != 2)
            ft_printf("\n");
        i++;
    }
    if (len == 2)
        ft_printf("\n");
}
