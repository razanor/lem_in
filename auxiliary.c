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

int     list_size(t_valid_map *valid_map)
{
    int i;

    i = 0;
    while (valid_map)
    {
        valid_map = valid_map->next;
        i++;
    }
    return (i);
}

void    table_clean(char **table)
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

int     table_size(char **str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
 
int     **create_matrix(int len)
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
        while (j < len)
        {
            mat[i] = (int *)malloc(sizeof(int) * len);
            mat[i][j] = 0;
            j++;
        }
        i++;
    }
    return (mat);
}

