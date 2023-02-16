/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/16 18:41:40 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	parse_args(t_stack **lst, char **argv)
{
	t_stack	*node;

	while (*argv)
	{
		node = ft_lstnew(ft_atoi(*argv), 0);
		add_index(lst, &node);
		ft_lstadd_back(lst, node);
		argv ++;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	where;

	where = top_or_buttom(*a, 0);
	while (where == 0 && (*a)->position != 0)
		reverse_rotate(a, 'a');
	while (where == 1 && (*a)->position != 0)
		rotate(a, 'a');
	push(b, a, 'b');
	where = top_or_buttom(*a, 1);
	while (where == 0 && (*a)->position != 1)
		reverse_rotate(a, 'a');
	while (where == 1 && (*a)->position != 1)
		rotate(a, 'a');
	push(b, a, 'b');
	sort_three(a);
	push(a, b, 'a');
	push(a, b, 'a');
}

static void	master_filter(t_stack **a, t_stack **b, int size)
{
	(void) b;
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		fr;

	fr = 0;
	stack_a = NULL;
	stack_b = NULL;
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
	// TODO: fix is_sorted bug : false positives when argc = 1
	if (is_sorted(argv, argc -1))
		return (write(1, "Already Sorted !\n", 18), 0);
	parse_args(&stack_a, argv);
	master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
	print_stack(&stack_a);
//	printf("\n------\n");
//	//print_stack(&stack_b);
//	if (fr)
//		free_2d(argv);
//	ft_lstclear(&stack_a);
	// system("leaks a.out");
}
