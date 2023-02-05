/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:41:12 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/05 02:11:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew(int content, size_t position)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (ptr);
	ptr->position = position;
	ptr->data = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *lst;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack *ft_before_last(t_stack *a)
{
    t_stack *var;

    var = a;
    while (var->next->next != NULL)
		var = var->next;	
	return (var);
}

/*
The top_or_buttom fuction Locates the node with the smallest position, then it determines whether
it's on the top or the button of the stack.

Return value:
1 => top
0 => buttom
*/

int	top_or_buttom(t_stack *stack)
{
    t_stack *var;
	int		index;
	int		size;

	size = ft_lstsize(stack);
    var = stack;
	index = 1;
    while (var->position != 0)
	{
		index += 1;
		var = var->next;
	}
	if (index <= (size/2))
		return (1);
	else
		return (0);
}
