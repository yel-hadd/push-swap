/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:09:31 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/29 16:47:44 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	has_duplicates(char **args, int count)
{
	size_t  i;
    size_t  y;

	y = 0;
    while (*args)
	{
		i = 1;
		while (i < (count - y) && *(args + i))
		{
			if (ft_atoi(*args) == ft_atoi(*(args+i)))
            	return (1);
			i += 1;
		}
		args += 1;
        y += 1;
	}
	return (0);
}

int	has_errors(char **args)
{
	size_t  i;
	char	*str;

    while (*args)
	{
		i = 0;
		str = *args;
		while (str[i])
		{
			if (((str[i] == '-') || (str[i] == '+')) && !ft_isdigit(str[i+1]))
				return (1);
			if ((!ft_isdigit(str[i])) && (str[i] != '-') && (str[i] != '+'))
				return (1);
			i ++;
		}
		args ++;
	}
	return (0);
}

int	is_sorted(char **args, int count)
{
	size_t  i;
    size_t  y;

	y = 0;
    while (*args)
	{
		i = 1;
		while (i < (count - y) && *(args + i))
		{
			if (ft_atoi(*args) > ft_atoi(*(args+i)))
            	return (0);
			i += 1;
		}
		args += 1;
        y += 1;
	}
	return (1);
}
