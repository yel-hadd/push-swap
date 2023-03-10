/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:23:06 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:23:11 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_sorted(char **arr)
{
	char	**args;
	int		i;

	args = arr;
	while (*args)
	{
		i = 1;
		while (*(args + i))
		{
			if (ft_atoi(*args) > ft_atoi(*(args + i)))
				return (0);
			i += 1;
		}
		args += 1;
	}
	return (1);
}
