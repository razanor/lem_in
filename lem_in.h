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
# define TRUE 1
# define FALSE 0
# include "./libft/ft_printf.h"

typedef struct			s_map
{
	short				ants;
	short				rooms_flag;
	short				com_start_flag;
	short				com_end_flag;
	short				start_flag;
	short				end_flag;
	char				*str;
	struct s_rooms		*rooms;
	struct s_links		*links;
	struct s_valid_map	*valid_map;
}						t_map;

typedef struct			s_rooms
{
	char				*room_name;
	short				is_start;
	short				is_end;
	short				x;
	short				y;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_links
{
	char				*from;
	char				*to;
	struct s_links		*next;
}						t_links;

typedef struct			s_valid_map
{
	char				*map;
	struct s_valid_map	*next;
}						t_valid_map;

/*
** -------------------------- Validation Functions ----------------------------
*/

void					line_analyzer(t_map *map);
void					enough_data_check(t_links **links);
void					unique_rooms(t_rooms **rooms);
_Bool					is_rooms(char *str, t_rooms *rooms);

/*
** -------------------------- Data collection Functions -----------------------
*/

void					map_saver(t_map *map);
void					collect_rooms(char *str, t_rooms **rooms,
						int start, int end);
void					collect_links(char *str, t_links **links);

/*
** -------------------------- Auxiliary Functions ------------------------------
*/

int						list_size(t_valid_map *valid_map);
int						table_size(char **str);
void					error();

#endif
