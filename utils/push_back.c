/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:38:11 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:04:48 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_back(t_stack **a, t_stack **b, int max)
{
	int where;

	while (-- max >= 0)
	{
		where = top_or_buttom(*b, max);
		while (where == 0 && (*b)->position != max)
			reverse_rotate(b, 'b');
		while (where == 1 && (*b)->position != max)
			rotate(b, 'b');
		push(a, b, 'a');
	}
}
