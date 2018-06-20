/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:09:02 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:12:02 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str(char *str, char const *s, int start, int end)
{
	int j;

	j = 0;
	while (start <= end)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
}

static int	ft_size(char const *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
			s[i] == '\f' || s[i] == '\r' || s[i] == '\v')
		i++;
	if (i == j)
		return (0);
	j--;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' ||
			s[j] == '\f' || s[j] == '\r' || s[j] == '\v')
		j--;
	return (j - i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		size;

	start = 0;
	end = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (s[end] != '\0')
		end++;
	size = ft_size(s);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	ft_str(str, s, start, end);
	return (str);
}
