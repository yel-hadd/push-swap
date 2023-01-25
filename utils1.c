/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:08:29 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/25 14:39:21 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count += 1;
	return (count);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	if (ft_strlen((char *) s2) != n)
        return (1);
    i = 0;
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (i < n)
	{
		if (s1cpy[i] != s2cpy[i])
			return (s1cpy[i] - s2cpy[i]);
		i ++;
	}
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

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
		str ++;
	}
	return (result * sign);
}
