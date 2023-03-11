/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:28:33 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:03:34 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	add_index(t_stack **lst, t_stack **node)
{
	t_stack	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->data > (*node)->data)
			tmp->position += 1;
		else
			(*node)->position += 1;
		tmp = tmp->next;
	}
}