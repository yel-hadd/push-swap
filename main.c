/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:54:06 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:12:17 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (empty_arg(argv))
		return (write(1, "Error\n", 6), 0);
	args = parse(--argc, ++argv);
	if (has_errors(args) || !args)
		return (free_2d(args), write(1, "Error\n", 6), 0);
	if (has_duplicates(args))
		return (free_2d(args), write(1, "Error\n", 6), 0);
	if (is_sorted(args))
		return (free_2d(args), 0);
	add_to_stack(&stack_a, args);
	master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_lstclear(&stack_a);
	free_2d(args);
}
