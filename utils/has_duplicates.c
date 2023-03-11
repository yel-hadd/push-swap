/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:21:33 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:04:36 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	has_duplicates(char **args)
{
	int	i;

	while (*args)
	{
		i = 1;
		while (*(args + i))
		{
			if (ft_atoi(*args) == ft_atoi(*(args + i)))
				return (1);
			i += 1;
		}
		args += 1;
	}
	return (0);
}
