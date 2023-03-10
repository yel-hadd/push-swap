/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:26:04 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:26:22 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
