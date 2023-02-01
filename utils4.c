/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:26:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/31 16:37:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	print_stack(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%d : %d\n", tmp->data, tmp->position);
		tmp = tmp->next;
	}
}

int has_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str ++;
	}
	return (0);
}

