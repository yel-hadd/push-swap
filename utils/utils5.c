/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:14:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/21 16:25:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap(t_stack **a, char stack)
{
	t_stack	*var;

	var = (*a)->next;
	(*a)->next = var->next;
	var->next = *a;
	*a = var;
	write(1, "s", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack **a, char stack)
{
	t_stack	*bf_last;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	bf_last = ft_before_last(*a);
	bf_last->next->next = *a;
	*a = bf_last->next;
	bf_last->next = NULL;
	write(1, "rr", 2);
	write(1, &stack, 1);
	write(1, "\n", 1);
}

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

void	push(t_stack **dest, t_stack **source, char stack)
{
	t_stack	*node;

	if (*source == NULL)
		return ;
	node = *source;
	*source = (*source)->next;
	node->next = *dest;
	*dest = node;
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
