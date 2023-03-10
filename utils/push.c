/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:14:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:36:26 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push(t_stack **dest, t_stack **source, char stack)
{
	t_stack	*node;

	if (*source == NULL)
		return ;
	node = *source;
	*source = (*source)->next;
	node->next = *dest;
	*dest = node;
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
