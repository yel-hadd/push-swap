/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:41:12 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/29 17:12:25 by yel-hadd         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dstcpy;

	dstcpy = dst;
	if (!dst && !src)
		return (dstcpy);
	while ((n > 0))
	{
		*(char *)dst ++ = *(char *)src ++;
		n --;
	}
	return (dstcpy);
}

void ft_lstclear(t_stack **lst)
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