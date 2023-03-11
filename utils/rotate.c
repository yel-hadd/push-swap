/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:36:04 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:04:58 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate(t_stack **a, char stack)
{
	t_stack	*node;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = NULL;
	ft_lstlast(*a)->next = node;
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
