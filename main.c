/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/03 23:38:33 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	parse_args(t_stack **lst, char **argv)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (*argv)
	{
		node = ft_lstnew(ft_atoi(*argv), 0);
		add_index(lst, &node);
		ft_lstadd_back(lst, node);
		argv ++;
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*var;

	var = *a;
	if (var->next->position < var->position < ft_lstlast(var)->position)
		swap(a, 'a');
	else if (ft_lstlast(var)->position < var->next->position < var->position)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (var->next->position < ft_lstlast(var)->position < var->position)
		rotate(a, 'a');
	else if (var->position < ft_lstlast(var)->position < var->next->position)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (ft_lstlast(var)->position < var->position < var->next->position)
		reverse_rotate(a, 'a');
}

void	filter_lt_6(t_stack **a, t_stack **b, int size)
{
	(void)	b;

	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);

}


static void	master_filter(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
		filter_lt_6(a, b, size);
	// else if ((size > 5) && (size < 200))
	// 	filter_lt_200(a, b, size);
	// else if (size >= 200)
	// 	filter_gt_200(a, b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		fr;

	fr = 0;
	if (argc == 1)
		return (0);
	if (argc == 2 && has_spaces(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		fr = 1;
	}
	else
		argv ++;
	if (has_errors(argv))
		return (write(1, "Error : Invalid Args\n", 21), 0);
	if (has_duplicates(argv, argc - 1))
		return (write(1, "Error : Duplicate Args\n", 24), 0);
	if (is_sorted(argv, argc -1))
		return (write(1, "Already Sorted !\n", 18), 0);
	parse_args(&stack_a, argv);
	master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
	print_stack(&stack_a);
	if (fr)
		free_2d(argv);
	ft_lstclear(&stack_a);
	// system("leaks a.out");
}
