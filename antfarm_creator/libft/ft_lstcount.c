/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:25:17 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 12:02:10 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list **lst, t_list *link)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = *lst;
	while (temp != NULL)
	{
		if (temp == link)
			break ;
		temp = temp->next;
		count++;
	}
	return (count);
}
