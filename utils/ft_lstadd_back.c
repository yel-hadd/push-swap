/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:24:56 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:25:02 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
