/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:41:46 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:26:17 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	param_init(t_win *v)
{
	int i;

	i = -1;
	while (++i < 1000)
		v->actions[i] = -1;
	v->ants_num = 20;
	v->room_nb = 0;
	v->mouse_on = 0;
	v->space_on = 0;
	v->setting_s = 0;
	v->setting_e = 0;
	v->rooms = NULL;
	v->links = NULL;
}

int		main(void)
{
	t_win	v;

	param_init(&v);
	win_init(&v);
	return (0);
}
