/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:26:30 by nrepak            #+#    #+#             */
/*   Updated: 2017/12/28 17:28:22 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_put_in_line(char *tmp, char **line)
{
	char	*p;
	int		a;

	if (!(p = ft_strchr(tmp, '\n')))
	{
		if (ft_strlen(tmp) > 0)
		{
			*line = ft_strdup(tmp);
			free(tmp);
			return (1);
		}
		free(tmp);
		return (0);
	}
	a = p - tmp;
	*line = ft_strsub(tmp, 0, a);
	free(tmp);
	return (1);
}

static	void	ft_check(t_list **list, char **tmp)
{
	char *p;

	if (!(p = ft_strchr((*list)->content, '\n')))
		*tmp = ft_strnew(0);
	else
	{
		*tmp = ft_strdup(p + 1);
		*p = ' ';
	}
}

static	void	ft_check_list(t_list **head, t_list **list, char **tmp, int fd)
{
	if (!(*head))
	{
		*tmp = ft_strnew(BUFF_SIZE);
		*head = ft_lstnew(*tmp, BUFF_SIZE + 1);
		(*head)->content_size = fd;
		free(*tmp);
	}
	*list = *head;
	while ((int)(*list)->content_size != fd && (*list)->next)
		*list = (*list)->next;
	if ((int)(*list)->content_size != fd)
	{
		*tmp = ft_strnew(BUFF_SIZE);
		(*list)->next = ft_lstnew(*tmp, BUFF_SIZE + 1);
		*list = (*list)->next;
		(*list)->content_size = fd;
		free(*tmp);
	}
}

int				get_next_line(const int fd, char **line)
{
	int				res;
	char			*tmp;
	char			*clean;
	t_list			*list;
	static t_list	*head;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	ft_check_list(&head, &list, &tmp, fd);
	ft_check(&list, &tmp);
	while (!ft_strchr(tmp, '\n') &&
	(res = read(list->content_size, list->content, BUFF_SIZE)) > 0)
	{
		((char *)(list->content))[res] = '\0';
		clean = tmp;
		tmp = ft_strjoin(tmp, list->content);
		free(clean);
	}
	if (res == -1)
		return (-1);
	return (ft_put_in_line(tmp, line));
}
