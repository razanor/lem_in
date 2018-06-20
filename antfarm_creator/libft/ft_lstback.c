/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:18:31 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 11:45:55 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
