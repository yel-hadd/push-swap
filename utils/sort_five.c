/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:06:24 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:34:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
This function sorts a stack of the size 5
It pushes the nodes with positions 0 and 1 to stack b,
then it sorts the remaining 3 node using sort_three()
then it pushes back the nodes with positions 0 and 1 to stack a
*/

void	sort_five(t_stack **a, t_stack **b)
{
	int	where;

	where = top_or_buttom(*a, 0);
	while (where == 0 && (*a)->position != 0)
		reverse_rotate(a, 'a');
	while (where == 1 && (*a)->position != 0)
		rotate(a, 'a');
	push(b, a, 'b');
	where = top_or_buttom(*a, 1);
	while (where == 0 && (*a)->position != 1)
		reverse_rotate(a, 'a');
	while (where == 1 && (*a)->position != 1)
		rotate(a, 'a');
	push(b, a, 'b');
	sort_three(a);
	push(a, b, 'a');
	push(a, b, 'a');
}
