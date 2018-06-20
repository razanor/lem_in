/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:56:17 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:37:33 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))
# define I(X) ((int)(X))
# define R(X) ((int)(((double)(X)) + 0.5))

# define LINK_COLOR 0x8B7A53

typedef struct		s_ln
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	double			dx;
	double			dy;
	int				font;
	double			gradient;
	double			xend;
	double			yend;
	double			intery;
	double			interx;
}					t_ln;

#endif
