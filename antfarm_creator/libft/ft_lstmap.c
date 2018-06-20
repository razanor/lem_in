/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:07:11 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/08 13:00:02 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*head;
	t_list	*temp;

	nlist = NULL;
	head = NULL;
	temp = NULL;
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			nlist = f(lst);
			if (temp != NULL)
				temp->next = nlist;
			else
				head = nlist;
			temp = nlist;
			lst = lst->next;
		}
	}
	return (head);
}
