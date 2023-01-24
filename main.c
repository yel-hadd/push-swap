/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/24 18:19:10 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

int main(int argc, char **argv)
{
	// t_stack stack_a;
	// t_stack stack_b;
	// size_t  i;
	if(argc == 1)
		return(0);
	if (has_duplicates(argv) || has_errors(argv))
	{
		printf("error detected !");
		return (0);
	}
	if (is_sorted(argv))
	{
		printf("stack already sorted");
		return (0);
	}
	// ft_atoi --- error --- dupl --- sorted
	// while(av[])
	// ft_lstnew
	// ft_lstaddback
}
