/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:36:50 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:35:15 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
This function sorts a stack of the size 3
It handles all the possible combinations based on the comparaison
of the position of each node
*/

void	sort_three(t_stack **a)
{
	int	first;
	int	middle;
	int	last;

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
