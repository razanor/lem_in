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
	int				ants;
	int				rooms_flag;
	int				com_start_flag;
	int				com_end_flag;
	int				start_flag;
	int				end_flag;
	int				links_end;
	int				links_start;
	int				mat_len;
	char				*str;
	int					**mat;
	int					*visited;
	int					*queue;
	struct s_rooms		*rooms;
	struct s_links		*links;
	struct s_valid_map	*valid_map;
}						t_map;

typedef struct			s_rooms
{
	char				*room_name;
	int					room_index;
	int				is_start;
	int				is_end;
	int				prev;
	int				x;
	int				y;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_links
{
	char				*from;
	char				*to;
	int					from_index;
	int					to_index;
	struct s_links		*next;
}						t_links;

typedef struct			s_valid_map
{
	char				*map;
	struct s_valid_map	*next;
}						t_valid_map;

typedef struct			s_queue
{
	int					front;
	int					rear;
	int					start;
	int					end;
}						t_queue;

/*
** -------------------------- Validation Functions ----------------------------
*/

void					line_analyzer(t_map *map);
void					enough_data_check(t_links **links, t_map *map);
void					unique_rooms(t_rooms **rooms, t_map *map);
_Bool					is_rooms(char *str, t_rooms *rooms, int *s, int *e);

/*
** -------------------------- Data collection Functions -----------------------
*/

void					map_saver(t_map *map);
void					collect_rooms(t_map *map, int start, int end);
void					collect_links(char *str, t_links **links);

/*
** -------------------------- Auxiliary Functions ------------------------------
*/

int 					ft_zero(int *arr,int len);
int  					ft_lst_size(t_list *lst);
int						table_size(char **str);
void					free_all(t_map *map, char flag);
void    				table_clean(char **table);
int     				**create_matrix(int len);
int     				*init_array(int *visited, int len, char flag);

/*
** -------------------------- Algo Functions ------------------------------
*/

void					rooms_to_index(t_map *map);
void    				adjacency_matrix(t_map *map);
void    				shortest_way(t_map *map);
int 					start_end_node(t_rooms *rooms, char flag);
void  					get_path(t_map *map, t_queue *p, int k);
void 					path_output(t_map *map, t_list **lst);

#endif
