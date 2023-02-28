/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:02:00 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/25 21:09:41 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_chunk(t_stack **a, t_stack **b, int start, int stop)
{
	int	s;
	int	half;

	s = start;
	while (s <= stop && ft_lstsize(*a) > 0)
	{
		while ((*a)->position < start || (*a)->position > stop)
			rotate(a, 'a');
		half = stop / 2; 
		if ((*a)->position <= half)
			push(b, a, 'b');
		else if((*a)->position > half)
		{
			push(b, a, 'b');
			if ((*b)->position > ft_lstlast(*b)->position)
				rotate(b, 'b');
		}
		s ++;
	}
}