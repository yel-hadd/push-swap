/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/28 18:10:46 by yel-hadd         ###   ########.fr       */
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

void	push_back(t_stack **a, t_stack **b, int max)
{
	int where;

	while (-- max >= 0)
	{
		where = top_or_buttom(*b, max);
		while (where == 0 && (*b)->position != max)
			reverse_rotate(b, 'b');
		while (where == 1 && (*b)->position != max)
			rotate(b, 'b');
		push(a, b, 'a');
	}
}

void	sort_gt_five(t_stack **a, t_stack **b, int divide, int size)
{
	int	i;
	int	start;
	int	stop;

	i = 1;
	start = 0;
	while (i <= divide)
	{
		if (i == divide)
		{
			stop = size;
			push_chunk(a, b, start, stop);
			return ;
		}
		else
		{
			stop = (((size / divide) * i) - 1);
			push_chunk(a, b, start, stop);
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
	{
		sort_gt_five(a, b, 5, size);
		push_back(a, b, size);
	}
	else if (size >= 200)
	{
		sort_gt_five(a, b, 10, size);
		push_back(a, b, size);
	}
}

char	**append(char **dest, char **src)
{
	size_t		s;
	size_t		d;
	size_t		y;
	char	**new;
	char	**tmp;

	d = 0;
	s = 0;
	while (dest != NULL && dest[d])
		d ++;
	while (src[s])
		s ++;
	new = ft_calloc((s + d), sizeof(char *));
	y = 0;
	tmp = dest;
	while (y <= d && d != 0)
		new[y ++] = ft_strdup(*dest++);
	free_2d(tmp);
	while (y <= s && s != 0)
		new[y ++] = ft_strdup(*src++);
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	**tmp;

	stack_a = NULL;
	stack_b = NULL;
	args = NULL;
	if (argc == 1)
		return (0);
	while (argv)
	{
		tmp = ft_split(*argv, ' ');
		args = append(args, tmp);
		free_2d(tmp);
		argv ++;
	}
	if (has_errors(args))
		return (write(1, "Error : Invalid Args\n", 21), 0);
	parse_args(&stack_a, args);
	master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
	//print_stack(&stack_b);
//	printf("\n------\n");
//	//print_stack(&stack_b);
//	if (fr)
//		free_2d(argv);
//	ft_lstclear(&stack_a);
	// system("leaks a.out");
}
