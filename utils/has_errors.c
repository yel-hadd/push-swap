/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:22:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:33:46 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	has_errors(char **args)
{
	size_t	i;
	char	*str;

	while (*args)
	{
		i = 0;
		str = *args;
		while (str[i])
		{
			if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
				return (1);
			else if ((str[i] == '+' || str[i] == '-') && (i != 0))
				return (1);
			else if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) \
			&& (str[i] != '-') && (str[i] != '+'))
				return (1);
			i ++;
		}
		args ++;
	}
	return (0);
}
