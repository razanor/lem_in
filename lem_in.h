/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:06:43 by nrepak            #+#    #+#             */
/*   Updated: 2018/03/20 13:07:33 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/ft_printf.h"

typedef struct  s_map
{
    short               ants;
    short               roomsFlag;
    short               commandsFlag;
    short               startFlag;
    short               endFlag;
    char                *str;
    struct s_rooms      *rooms;
    struct s_paths      *paths;
    struct s_validMap   *validMap;
}                       t_map;

typedef struct  s_rooms 
{
    char                *roomName;
    short               x;
    short               y;
    struct s_rooms      *next;
}                       t_roooms;

typedef struct  s_paths
{
    char                *from;
    char                *to;
    struct s_paths      *next;
}                       t_paths;

typedef struct  s_validMap
{
    char                *map;                
    struct s_validMap   *next;
}                       t_validMap;

/*
** -------------------------- Validation Functions -------------------------------
*/

void    comments_validation(t_map *map);
void    rooms_validation(t_map *map);
void    links_validation(t_map *map);




/*
** -------------------------- Auxiliary Functions -------------------------------
*/

int     list_size(t_validMap *validMap);

#endif
