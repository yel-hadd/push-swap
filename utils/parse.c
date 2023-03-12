/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:58:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:30:59 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	**parse(int argc, char **argv, int z)
{
	int		i;
	int		y;
	char	**tmp;
	size_t	count;
	char	**args;

	i = -1;
	count = 0;
	while (++i < argc)
		count += count_words(argv[i], ' ');
	args = ft_calloc(count + 1, sizeof(char *));
	i = -1;
	y = -1;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		z = 0;
		while (tmp[z])
			args[++y] = ft_strdup(tmp[z++]);
		free_2d(tmp);
	}
	return (args);
}
