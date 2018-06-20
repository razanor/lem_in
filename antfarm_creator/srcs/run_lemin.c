/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:55:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 11:17:51 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		start_end(t_win *v, t_link *l, FILE *log)
{
	int ret;

	ret = 0;
	if ((ret = ft_strequ(l->name1, v->start->name)) &&
		(ret = ft_strequ(l->name2, v->end->name)))
		fprintf(log, "%s-%s", "s", "e");
	else if ((ret = ft_strequ(l->name2, v->start->name)) &&
		(ret = ft_strequ(l->name1, v->end->name)))
		fprintf(log, "%s-%s", "e", "s");
	else if ((ret = ft_strequ(l->name1, v->start->name)))
		fprintf(log, "%s-%s", "s", l->name2);
	else if ((ret = ft_strequ(l->name2, v->start->name)))
		fprintf(log, "%s-%s", l->name1, "s");
	else if ((ret = ft_strequ(l->name1, v->end->name)))
		fprintf(log, "%s-%s", "e", l->name2);
	else if ((ret = ft_strequ(l->name2, v->end->name)))
		fprintf(log, "%s-%s", l->name1, "e");
	return (ret);
}

void	write_rooms(t_win *v, FILE *log)
{
	t_room	*r;
	char	*start;
	char	*end;

	r = v->rooms;
	while (r)
	{
		if (r->type == 's')
		{
			fprintf(log, "%s\n%s %i %i\n", "##start", "s", 1, 0);
			start = r->name;
		}
		else if (r->type == 'e')
		{
			fprintf(log, "%s\n%s %i %i\n", "##end", "e", 0, 1);
			end = r->name;
		}
		else
			fprintf(log, "%s %s %s\n", r->name, r->name, r->name);
		r = r->next;
	}
}

void	write_file(t_win *v)
{
	FILE	*log;
	t_link	*l;

	l = v->links;
	log = fopen("test.txt", "w");
	fprintf(log, "%i\n", v->ants_num);
	write_rooms(v, log);
	l = v->links;
	while (l)
	{
		if (!(start_end(v, l, log)))
			fprintf(log, "%s-%s", l->name1, l->name2);
		l = l->next;
		if (l)
			fprintf(log, "\n");
	}
	fclose(log);
}

void	run_lemin(t_win *v)
{
	write_file(v);
	system("./../lem-in -m < test.txt");
}
