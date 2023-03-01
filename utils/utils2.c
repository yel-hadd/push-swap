/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:09:31 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/01 23:11:23 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_isdigit(int c)
{
	if (c <= '9' || c >= '0')
		return (1);
	return (0);
}



int	is_sorted(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*run;

	tmp = *lst;
	while (tmp != NULL)
	{
		run = tmp->next;
		while (run != NULL)
		{
			if (tmp->position > run->position)
				return (0);
			run = run->next;
		}
		tmp = tmp->next;
	}
	return (1);
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