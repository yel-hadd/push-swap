/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/27 15:20:25 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack stack_b;
	size_t	pos;

	pos = 1;
	if(argc == 1)
		return(0);
	argv ++;
	if (has_errors(argv) || has_duplicates(argv, argc - 1) || is_sorted(argv, argc -1))
		return (0);
	printf("EVERYTHING OKAY !");
	stack_a = ft_lstnew(argv ++, pos);
	while (*argv)
	{
		argv ++;
		pos += 1;
	}
	
	// stack_a = 
	// ft_atoi --- error --- dupl --- sorted
	// while(av[])
	// ft_lstnew
	// ft_lstaddback
}
