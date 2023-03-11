/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:52:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:03:22 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
