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

static void		put_rooms_name(t_list **lst, t_rooms *rooms)
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

static void		ft_shift(int ant, int *arr, int all_ant, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	if (ant < all_ant)
		arr[i] = ant + 1;
	else
		arr[i] = 0;
}

static void		ft_print_lem(int ant, int ind, t_list *lst, int size)
{
	int i;

	i = ind ? size - ind : size - 1;
	while (--i)
		lst = lst->next;
	ft_printf("L%d-%s", ant, lst->content);
	if (size == 2)
		ft_printf(" ");
}

static void		initialize(t_map *map, t_list **lst, t_output *out)
{
	t_list *t;

	out->i = 1;
	out->j = 0;
	out->space = 0;
	out->len = ft_lst_size(*lst);
	t = *lst;
	*lst = (*lst)->next;
	free(t);
	put_rooms_name(lst, map->rooms);
}

void			path_output(t_map *map, t_list **lst)
{
	t_output	out;
	int			arr[ft_lst_size(*lst)];

	initialize(map, lst, &out);
	ft_bzero(arr, out.len * 4);
	arr[out.len - 1] = 1;
	while (ft_zero(arr, out.len))
	{
		out.j = 0;
		while (out.j < out.len)
		{
			if (arr[out.j] && out.j)
			{
				out.space++ ? ft_printf(" ") : 0;
				ft_print_lem(arr[out.j], out.j, *lst, out.len);
			}
			out.j++;
		}
		out.space = 0;
		ft_shift(out.i, arr, map->ants, out.len);
		if (ft_zero(arr, out.len) && out.len != 2)
			ft_printf("\n");
		out.i++;
	}
	out.len == 2 ? ft_printf("\n") : 0;
}
