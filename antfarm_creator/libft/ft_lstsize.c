/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:10:05 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 11:51:51 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
