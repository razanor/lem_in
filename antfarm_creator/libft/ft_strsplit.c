/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:43:07 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:11:09 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_words(char const *s, char c)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	if (s[0] != c && s[i] != '\0')
		nb++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_size(char const *s, int i, char c)
{
	int size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static char	*ft_str(char const *s, int i, char c)
{
	int		j;
	int		size;
	char	*str;

	j = 0;
	size = ft_size(s, i, c);
	str = (char*)malloc(sizeof(char) * (size + 1));
	while (s[i] != c && s[i] != '\0')
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	array = (char**)malloc(sizeof(char*) * (words + 1));
	if (array == NULL)
		return (NULL);
	while (n < words)
	{
		while (s[i] == c)
			i++;
		array[n] = ft_str(s, i, c);
		i = i + ft_strlen(array[n]);
		n++;
	}
	array[n] = NULL;
	return (array);
}
