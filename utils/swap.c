/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:33:17 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:35:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
This Function swaps the first two nodes of a stack
*/

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
