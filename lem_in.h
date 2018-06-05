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
    unsigned short      ants;
    struct s_rooms      *rooms;
    struct s_paths      *paths;
}                       t_map;

typedef struct s_rooms 
{
    char                *roomName;
    unsigned short      x;
    unsigned short      y;
    struct s_rooms      *next;
}                       t_roooms;

typedef struct s_paths
{
    unsigned short      from;
    unsigned short      to;
    struct s_paths      *next;
}                       t_paths;

#endif
