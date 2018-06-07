/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:07:47 by nrepak            #+#    #+#             */
/*   Updated: 2018/06/05 17:36:38 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static 	void	error() {
// 	ft_printf("ERROR\n");
// 	exit(1);
// }	

static void		mapSaver(t_map **map, char *str)
{
	t_validMap *tmp;

	if (!((*map)->validMap))
	{
		(*map)->validMap = (t_validMap*)malloc(sizeof(t_validMap));
		(*map)->validMap->map = ft_strdup(str);
		(*map)->validMap->next = NULL;
	}
	else
	{
		tmp = (*map)->validMap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_validMap*)malloc(sizeof(t_validMap));
		tmp->next->map = ft_strdup(str);
		tmp->next->next = NULL;
	}
}

static void		validationFirstPart(t_map *map)
{
	char *str;
	int	 i;

	i = 0;

	while (get_next_line(0, &str))
	{
		if (*str == '#' && strcmp(str, "##start") && strcmp(str, "##end") && *(str + 1) != ' ')
			mapSaver(&map, str);
		if (atoi(str) && atoi(str) > 0 && !ft_strchr(str, ' ') && !ft_strchr(str, '-'))
		{ 
			map->ants = atoi(str);
			mapSaver(&map, str);
		}
		if (strcmp(str, "##start") == 0)
		{
			if (map->ants)
				mapSaver(&map, str);
		}
		if ((ft_count_w(str, ' ')) == 3 && ft_count_char(str, ' ') == 2 && *str != '#' && *str != 'L')
			mapSaver(&map, str);
		if (strcmp(str, "##end") == 0)
			mapSaver(&map, str);
		if (ft_count_char(str, '-') == 1)
			mapSaver(&map, str);
		i++;
	}
	printf("%d\n", i);
	i = 0;
	while (map->validMap)
	{
		map->validMap = map->validMap->next;
		i++;
	}
	printf("%d\n", i);
	
}


int		main(void)
{
	t_map map;
	
	map = (t_map){0, 0, 0, 0, 0, 1, NULL, NULL, NULL};
	validationFirstPart(&map);
	
	return (0);	
	
}

