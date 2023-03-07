/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:09:31 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/07 01:20:40 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

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

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *) s1;
	uc2 = (unsigned char *) s2;
	i = 0;
	while ((uc1[i] || uc2[i]) && i < n)
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i ++;
	}
	return (0);
}

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

int	is_sorted(char **args, int count)
{
	size_t	i;
	size_t	y;

	y = 0;
	while (*args)
	{
		i = 1;
		while (i < (count - y) && *(args + i))
		{
			
			if (ft_atoi(*args) > ft_atoi(*(args + i)))
				return (0);
			i += 1;
		}
		args += 1;
		y += 1;
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