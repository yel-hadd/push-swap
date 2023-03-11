/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gt_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:40:19 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:40:22 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
This function sorts a stack of the size greater than five
It splits stack a into (int divide) chunks then,
it pushes each chunk to stack b
*/

void	sort_gt_five(t_stack **a, t_stack **b, int divide, int size)
{
	int	i;
	int	start;
	int	stop;

	i = 1;
	start = 0;
	while (i <= divide)
	{
		if (i == divide)
		{
			stop = size;
			push_chunk(a, b, start, stop);
			return ;
		}
		else
		{
			stop = (((size / divide) * i) - 1);
			push_chunk(a, b, start, stop);
			start = stop + 1;
		}
		i ++;
	}
}
