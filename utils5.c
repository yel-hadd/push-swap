/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:14:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/05 02:19:07 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
// TODO: FIx Bug in rotate
void	rotate(t_stack **a, char stack)
{
	t_stack	*bf_last;
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	bf_last = ft_before_last(*a);
	first = *a;
	last = ft_lstlast(*a);
	last->next = first;
	first->next = NULL;
	*a = bf_last;
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
