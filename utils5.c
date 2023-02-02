/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:57:34 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/02 16:01:19 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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