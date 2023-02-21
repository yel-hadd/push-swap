/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/21 01:59:29 by yel-hadd         ###   ########.fr       */
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

void	push_chunk(t_stack **a, t_stack **b, int chunk_size, int stop)
{
	int	i;

	i = -1;
	while (++i < chunk_size)
	{
		while ((*a)->position >= stop)
			rotate(a, 'a');
		if ((*a)->position <= ((stop-1) / 2))
			push(b, a, 'b');
		else
		{
			push(b, a, 'b');
			rotate(b, 'b');
		}
	}
}

void	sort_lt_200(t_stack **a, t_stack **b, int size)
{
	int	j;
	int	chunk_size;
	int	left;
	int	stop;

	j = 1;
	chunk_size = (size / 5);
	left = size % 5;
	while (j < 6)
	{
		stop = chunk_size * j;
		push_chunk(a, b, chunk_size, stop);
		j ++;
	}
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
	else if (size > 5 && size < 200)
		sort_lt_200(a, b, size);
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
