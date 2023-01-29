/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/29 13:07:28 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

static void	add_index(t_stack **lst, t_stack **node)
{
	t_stack	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->data > (*node)->data)
			tmp->position += 1;
		else
			(*node)->position += 1;
		tmp = tmp->next;
	}
}

static void	parse_args(t_stack **lst, char **argv)
{
	int	i;
	t_stack	*node;

	i = 0;
	while (*argv)
	{
		node = ft_lstnew(ft_atoi(*argv), 0);
		add_index(lst, &node);
		ft_lstadd_back(lst, node);
		argv ++;
	}
	while (*lst != NULL)
	{
		printf("%d : %d\n", (*lst)->data, (*lst)->position);
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

