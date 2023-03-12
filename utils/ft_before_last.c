/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:26:47 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:28:13 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*ft_before_last(t_stack *a)
{
	t_stack	*var;

	var = a;
	while (var->next->next != NULL)
		var = var->next;
	return (var);
}
