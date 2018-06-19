/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:50:48 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/07 16:50:50 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_lst_size(t_list *lst)
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

int		ft_zero(int *arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (arr[i])
			return (1);
	return (0);
}

void	table_clean(char **table)
{
	int i;

	i = 0;
	while (table[i])
	{
		ft_strdel(&table[i]);
		i++;
	}
	free(table);
}

int		**create_matrix(int len)
{
	int **mat;
	int i;
	int j;

	i = 0;
	j = 0;
	mat = (int **)malloc(sizeof(int *) * len);
	while (i < len)
	{
		j = 0;
		mat[i] = (int *)malloc(sizeof(int) * len);
		while (j < len)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
	return (mat);
}

int		*init_array(int *visited, int len, char flag)
{
	int i;

	i = 0;
	visited = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (flag == '0')
			visited[i++] = 0;
		else if (flag == '-')
			visited[i++] = -1;
	}
	return (visited);
}
