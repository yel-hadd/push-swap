/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:26:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/05 02:03:21 by yel-hadd         ###   ########.fr       */
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

void	print_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		printf("%d : %d\n", tmp->data, tmp->position);
		tmp = tmp->next;
	}
}

void free_2d(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		arr[i ++] = NULL;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len += 1;
	}
	return (len);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}