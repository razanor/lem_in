/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:52:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:31:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_h_lines(t_ln *l, t_win *m)
{
	l->yend = l->y1 + l->gradient * (R(l->x1) - l->x1);
	l->intery = l->yend + l->gradient;
	l->yend = l->y2 + l->gradient * (R(l->x2) - l->x2);
	l->x = R(l->x1);
	while (++l->x <= R(l->x2) - 1)
	{
		put_img_pixel(m, l->x, I(l->intery), LINK_COLOR);
		put_img_pixel(m, l->x, I(l->intery) + 1, LINK_COLOR);
		l->intery += l->gradient;
	}
}

void	draw_v_lines(t_ln *l, t_win *m)
{
	l->xend = l->x1 + l->gradient * (R(l->y1) - l->y1);
	l->interx = l->xend + l->gradient;
	l->xend = l->x2 + l->gradient * (R(l->y2) - l->y2);
	l->y = R(l->y1);
	while (++l->y <= R(l->y2) - 1)
	{
		put_img_pixel(m, I(l->interx), l->y, LINK_COLOR);
		put_img_pixel(m, I(l->interx) + 1, l->y, LINK_COLOR);
		l->interx += l->gradient;
	}
}

void	draw_line2(t_ln *ln, t_win *v)
{
	if (ln->y2 < ln->y1)
	{
		ft_swap(&ln->x1, &ln->x2);
		ft_swap(&ln->y1, &ln->y2);
	}
	ln->x2 += ln->font;
	ln->x1 += ln->font;
	ln->gradient = ln->dx / ln->dy;
	draw_v_lines(ln, v);
}

void	draw_line(t_ln *ln, t_win *v)
{
	ln->dx = (double)ln->x2 - (double)ln->x1;
	ln->dy = (double)ln->y2 - (double)ln->y1;
	if (ABS(ln->dx) > ABS(ln->dy))
	{
		if (ln->x2 < ln->x1)
		{
			ft_swap(&ln->x1, &ln->x2);
			ft_swap(&ln->y1, &ln->y2);
		}
		ln->y2 += ln->font;
		ln->y1 += ln->font;
		ln->gradient = ln->dy / ln->dx;
		draw_h_lines(ln, v);
	}
	else
		draw_line2(ln, v);
}
