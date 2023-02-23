/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/23 03:08:20 by yel-hadd         ###   ########.fr       */
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

void	push_chunk(t_stack **a, t_stack **b, int start, int stop, int size)
{
	int	i;
	int m;

	i = start;
	while (i <= stop)
	{
		if (size != stop)
		{
			while (((*a)->position < start) || ((*a)->position > stop))
				rotate(a, 'a');
		}
		if ((*a)->position <= (stop / 2))
			push(b, a, 'b');
		else
		{
			push(b, a, 'b');
			rotate(b, 'b');
		}
		i ++;
	}
}

void	sort_lt_200(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	start;
	int	stop;

	i = 1;
	start = 0;
	while (i <= 5)
	{
		if (i == 5)
		{
			stop = size;
			push_chunk(a, b, start, stop, size);
			return ;
		}
		else
		{
			stop = (((size / 5) * i) - 1);
			push_chunk(a, b, start, stop, size);
			start = stop + 1;
		}
		i ++;
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
