/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:09:31 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/24 18:10:01 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	has_duplicates(char **args)
{
	size_t  i;

	while (*args)
	{
		i = 0;
		while (*args + i)
		{
			if (*args == (*args + i))
				return (1);
			i += 1;
		}
		args ++;
	}
	return (0);
}

int	has_errors(char **args)
{
	size_t	i;

	while (*args)
	{
		i = 0;
		while (*args[i])
		{
			if (!ft_isdigit(*args[i]) && (*args[i] != '-') && (*args[i] != '+'))
				return (1);
			i += 1;
		}
		args ++;
	}
	return (0);
}

int	is_sorted(char **args)
{
	while (*args)
	{
		if (*args + 1)
		{
			if (ft_atoi(*args) > ft_atoi(*args + 1))
				return (0);
		}
		args += 1;
	}
	return (1);
}
