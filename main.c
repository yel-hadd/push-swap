/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

static void	parse_args(t_stack **lst, char **argv)
{
	while (*argv)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(*argv), 0));
		argv ++;
	}
	get_lst_position(lst);
	while (*lst != NULL)
	{
		printf("%d", (*lst)->data);
		printf("--%zu\n", (*lst)->position);
		*lst = (*lst)->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack stack_b;

	if(argc == 1)
		return(0);
	argv ++;
	// SORTED IS NOT ERROR, SEPERATE IT
	if (has_errors(argv) || has_duplicates(argv, argc - 1) || is_sorted(argv, argc -1))
		return (0);
	parse_args(&stack_a, argv);
}

