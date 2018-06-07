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

int     list_size(t_validMap *validMap)
{
    int i;

    i = 0;
    while (validMap)
    {
        validMap = validMap->next;
        i++;
    }
    return (i);
}

int     table_size(char **str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
