/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_or_buttom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:41:12 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:05:17 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
The top_or_buttom fuction Locates the node with the smallest position,
then it determines whether it's on the top or the button of the stack.

Return value:
1 => top
0 => buttom
*/

int	top_or_buttom(t_stack *stack, int position)
{
    t_stack *var;
	int		index;
	int		size;

	size = ft_lstsize(stack);
    var = stack;
	index = 1;
    while (var->position != position)
	{
		index += 1;
		var = var->next;
	}
	if (index <= (size/2))
		return (1);
	else
		return (0);
}
