/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:34:07 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:08:00 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_str(char *str, char const *s, int i)
{
	int j;

	j = 0;
	while (s[j] != '\0')
	{
		str[i] = s[j];
		i++;
		j++;
	}
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
	ft_str(join, s1, i);
	ft_str(join, s2, len1);
	join[len1 + len2] = '\0';
	return (join);
}
