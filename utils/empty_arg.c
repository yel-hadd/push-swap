/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:59:33 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 22:59:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	empty_arg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0)
			return (1);
	}
	return (0);
}
