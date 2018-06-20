/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:42:53 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 12:59:21 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = *alst;
	if (alst != NULL && del != NULL)
	{
		while (temp)
		{
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp->next;
		}
		*alst = NULL;
	}
}
