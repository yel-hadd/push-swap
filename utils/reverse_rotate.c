/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:35:38 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:35:42 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	reverse_rotate(t_stack **a, char stack)
{
	t_stack	*bf_last;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	bf_last = ft_before_last(*a);
	bf_last->next->next = *a;
	*a = bf_last->next;
	bf_last->next = NULL;
	write(1, "rr", 2);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
