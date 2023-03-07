/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:52:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/07 04:53:02 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void push_chunk(t_stack **a, t_stack **b, int start, int stop)
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
			else if((*a)->position > half)
			{
				push(b, a, 'b');
				if ((*b)->position > ft_lstlast(*b)->position)
					rotate(b, 'b');
			}
		}
		s ++;
	}
}

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

void	master_filter(t_stack **a, t_stack **b, int size)
{
	(void) b;
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 5 && size < 200)
	{
		sort_gt_five(a, b, 5, size);
		push_back(a, b, size);
	}
	else if (size >= 200)
	{
		sort_gt_five(a, b, 10, size);
		push_back(a, b, size);
	}
}