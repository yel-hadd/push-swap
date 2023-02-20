/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:06:24 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/21 00:44:42 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_stack **a)
{
    int     first;
    int     middle;
    int     last;

    first = (*a)->position;
    middle = (*a)->next->position;
    last = ft_lstlast(*a)->position;
	if (last > first && first > middle)
		swap(a, 'a');
	else if (first > middle && middle > last)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (first > last && last > middle)
		rotate(a, 'a');
	else if (middle > last && last > first)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (middle > first && first > last)
		reverse_rotate(a, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	where;

	where = top_or_buttom(*a, 0);
	while (where == 0 && (*a)->position != 0)
		reverse_rotate(a, 'a');
	while (where == 1 && (*a)->position != 0)
		rotate(a, 'a');
	push(b, a, 'b');
	sort_three(a);
	push(a, b, 'a');
}

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
