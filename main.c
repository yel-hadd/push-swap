/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/01 23:17:59 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	has_empty_arg(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			return (1);
	}
	return (0);
}

int	has_errors(char **string)
{
	char	**arr;
	char	*tmp;

	arr = string;
	while (*arr)
	{
		tmp = *arr;
		while (*tmp)
		{
			if (!ft_isdigit(*tmp) && *tmp != '+' && *tmp != '-')
				return (1);
			tmp ++;
		}
		arr ++;
	}
	return (1);
}


int	parse_args(t_stack **lst, char **argv)
{
	t_stack	*node;
	char	**tmp;
	int		i;

	while (*argv)
	{
		tmp = ft_split(*argv, ' ');
		if (has_errors(tmp))
			return (0);
		printf("%s", *tmp);
		exit(0);
		i = 0;
		while (tmp[i])
		{
			node = ft_lstnew(tmp[i], ft_atoi(tmp[i]), 0);
			add_index(lst, &node);
			ft_lstadd_back(lst, node);
			i ++;
		}
		free_2d(tmp);
		argv ++;
	}
	return (1);
}

int	is_unique(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *lst;
	while (tmp != NULL)
	{
		node = tmp->next;
		while (node != NULL)
		{
			if (tmp->data == node->data)
				return (0);
			node = node->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	valid_zero(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '0' && str[0] != '-' && str[0] != '+')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	is_convertible(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if ((tmp->data == 0 && !valid_zero(tmp->init)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		result;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (has_empty_arg(argc, argv))
		return (write(1, "Error 1\n", 8), 0);
	result = parse_args(&stack_a, ++argv);
	if (result > 0 && is_convertible(&stack_a))
	{
		if (is_unique(&stack_a) && !is_sorted(&stack_a))
		{
			master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
			print_stack(&stack_a);
		}
		else
			return (write(1, "Error 3\n", 8), 0);
	}
	else
		return (write(1, "Error 2\n", 8), 0);
	ft_lstclear(&stack_a);
	// system("leaks pushswap");
}
