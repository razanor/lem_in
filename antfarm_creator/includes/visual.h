/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:56:17 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:37:16 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "line.h"

# define X 0
# define Y 1

# define WIDTH 	1500
# define HEIGHT 1000

# define ROOM_SIZE 35

# define ROOM 	0x917F55
# define START  0x26D555
# define END 	0xE44B5F

# define ADD_ROOM 1
# define ADD_LINK 2
# define SET_START 3
# define SET_END 4

# include <stdio.h>

typedef struct		s_room
{
	char			*name;
	int				coords[2];
	char			type;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*name1;
	char			*name2;
	int				from_link_coords[2];
	int				to_link_coords[2];
	struct s_link	*next;
}					t_link;

typedef struct		s_ptr
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				bpp;
	int				size_line;
	int				endian;
}					t_ptr;

typedef struct		s_win
{
	int				room_nb;
	int				ants_num;
	int				from_link_coords[2];
	int				to_link_coords[2];
	int				to_check;
	char			*name1;
	char			*name2;
	t_ptr			p;
	t_room			*rooms;
	t_link			*links;
	t_room			*start;
	t_room			*end;
	int				mouse_on;
	int				space_on;
	int				setting_s;
	int				setting_e;
	int				actions[1000];
}					t_win;

void				win_init(t_win *v);
void				param_init(t_win *v);
void				add_room(t_win *v, int x, int y);
void				set_room(t_win *v, int r_x, int r_y, char type);
int					overlapping(t_win *v, int r_x, int r_y);
void				add_link(t_win *v, int x, int y);
int					is_room(t_win *v, int r_x, int r_y);
int					key_hook(int keycode, t_win *v);
int					key_off(int keycode, t_win *v);
int					mouse_off(int button, int x, int y, t_win *v);
int					mouse_hook(int button, int x, int y, t_win *v);
int					mouse_move(int x, int y, t_win *v);
int					program_exit(t_win *v);
void				put_img_pixel(t_win *v, int x, int y, int color);
void				redraw(t_win *v);
void				clear_image(t_win *v);
void				draw_room(t_win *v);
void				put_room_names(t_win *v);
void				draw_line(t_ln *ln, t_win *v);
void				draw_linking(t_win *v);
void				draw_links(t_win *v);
void				add_action(t_win *v, int type);
void				undo_action(t_win *v);
void				run_lemin(t_win *v);

#endif
