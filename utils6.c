/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:06:24 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/04 23:52:02 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack **a)
{
    int     first;
    int     middle;
    int     last;

    first = (*a)->position;
    middle = (*a)->next->position;
    last = ft_lstlast(*a)->position;
	if (last > first > middle)
		swap(a, 'a');
	else if (first > middle > last)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (first > last > middle)
		rotate(a, 'a');
	else if (middle > last > first)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (middle > first > last)
		reverse_rotate(a, 'a');
}
