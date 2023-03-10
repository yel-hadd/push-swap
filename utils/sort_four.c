/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:37:17 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:37:20 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
