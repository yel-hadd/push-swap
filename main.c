/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/05 02:21:01 by yel-hadd         ###   ########.fr       */
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

/*
Take the first element at the top of source and put it at the top of the destination (dest).
Do nothing if source is empty.

If stack == a : print "pa" on stdout (push a)
If stack == b : print "pb" on stdout (push b)
*/
void	push(t_stack **dest, t_stack **source, char stack)
{
	t_stack	*node;

	node = (*source)->next;
	ft_lstadd_front(dest, *source);
	*source = node;
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*var;
	int		where;

	(void) b;
	var = *a;
	where = top_or_buttom(*a);
	printf("%d\n", where);
	// if (where)
	// 	rotate(a, 'a');
	// else
	while (where == 0 && var->position != 0)
	{
		reverse_rotate(a, 'a');
		var = *a;
	}
	// TODO: FIx Bug in rotate
	while (where == 1 && var->position != 0)
	{
		rotate(a, 'a');
		var = *a;
	}
	// TODO: FIx Bug in push
	push(b, a, 'b');
	sort_three(a);
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
	// else if (size == 5)
	// 	sort_five(a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		fr;

	fr = 0;
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
	printf("\n------\n");
	print_stack(&stack_b);
	if (fr)
		free_2d(argv);
	ft_lstclear(&stack_a);
	// system("leaks a.out");
}
