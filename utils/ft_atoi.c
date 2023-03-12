/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:08:29 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:26:10 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_atoi(char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str ++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		if ((result > 2147483647 && sign > 0) || \
		(result > 2147483648 && sign < 0))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		str ++;
	}
	return ((int)(result * sign));
}
