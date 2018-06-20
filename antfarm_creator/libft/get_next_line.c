/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:23:08 by anesteru          #+#    #+#             */
/*   Updated: 2017/12/29 14:23:14 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_longer_line(char *line, size_t n)
{
	char		*rewritten_line;
	size_t		i;

	rewritten_line = ft_strnew(ft_strlen(line) + n);
	i = -1;
	while (line[++i] != '\0')
		rewritten_line[i] = line[i];
	free(line);
	return (rewritten_line);
}

int		get_line(char *stack, char **line)
{
	size_t		i;

	i = -1;
	while (stack[++i] != '\n')
		if (stack[i] == '\0')
		{
			if (i != 0)
			{
				*line = !(*line) ? ft_strnew(i) : get_longer_line(*line, i);
				*line = ft_strncat(*line, stack, i);
				ft_bzero(stack, BUFF_SIZE);
			}
			return (0);
		}
	*line = !(*line) ? ft_strnew(i) : get_longer_line(*line, i);
	*line = ft_strncat(*line, stack, i);
	ft_memmove(stack, stack + i + 1, ft_strlen(stack + i));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	size_t		bytes_read;
	static char	*stack[4864];

	if (BUFF_SIZE <= 0 || fd < 0 || fd > 4864)
		return (-1);
	if (!line || (read(fd, stack[fd], 0) == -1))
		return (-1);
	if (stack[fd] == NULL && (stack[fd] = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	*line = NULL;
	if (get_line(stack[fd], line) == 1)
		return (1);
	while ((bytes_read = read(fd, stack[fd], BUFF_SIZE)) > 0)
	{
		stack[fd][bytes_read] = '\0';
		if (get_line(stack[fd], line) == 1)
			return (1);
	}
	if (*line != NULL)
		return (1);
	free(stack[fd]);
	stack[fd] = NULL;
	return (0);
}
