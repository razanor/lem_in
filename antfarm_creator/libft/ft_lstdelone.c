/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:37:31 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 12:59:37 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	char	*str;
	size_t	i;

	list = *alst;
	i = list->content_size;
	str = list->content;
	if (alst != NULL && del != NULL)
	{
		del(str, i);
		free(*alst);
		*alst = NULL;
	}
}
