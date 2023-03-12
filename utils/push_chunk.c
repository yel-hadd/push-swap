/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:15:01 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:33:31 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_chunk(t_stack **a, t_stack **b, int start, int stop)
{
	int	s;
	int	half;

	s = start;
	while (s <= stop)
	{
		if (ft_lstsize(*a) > 0)
		{
			while ((*a)->position < start || (*a)->position > stop)
				rotate(a, 'a');
			half = stop / 2;
			if ((*a)->position <= half)
				push(b, a, 'b');
			else if ((*a)->position > half)
			{
				push(b, a, 'b');
				if ((*b)->position > ft_lstlast(*b)->position)
					rotate(b, 'b');
			}
		}
		s ++;
	}
}
