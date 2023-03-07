/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:54:06 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/07 05:20:47 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_to_stack(t_stack **lst, char **argv)
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;

	pb = (unsigned char *) b;
	while (len != 0)
	{
		*pb = (unsigned char) c;
		pb ++;
		len --;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset((void *) s, 0, (size_t) n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	**parse(int argc, char **argv, size_t *size)
{
	int		i;
	int		y;
	char	**tmp;
	size_t	count;
	char	**args;

	i = -1;
	count = 0;
	while (++i < argc)
		count += count_words(argv[i], ' ');
	*size = count;
	args = ft_calloc(count + 1, sizeof(char *));
	i = -1;
	y = -1;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		while (*tmp)
			args[++y] = *(tmp ++);
	}
	return (args);
}

int	empty_arg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0)
			return (1);
	}
	return (0);
}

//void	f()
//{
//	system("leaks a.out");
//}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	size_t	arg_count;

	//atexit(f);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (empty_arg(argv))
		return (write(1, "Error : Empty Arg\n", 18), 0);
	args = parse(--argc, ++argv, &arg_count);
	if (has_errors(args) || !args)
		return (free_2d(args), write(1, "Error : Invalid Args\n", 21), 0);
	if (has_duplicates(args))
		return (free_2d(args), write(1, "Error : Duplicate Args\n", 24), 0);
	if (is_sorted(args))
		return (free_2d(args), write(1, "Already Sorted !\n", 18), 0);
	add_to_stack(&stack_a, argv);
	master_filter(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_lstclear(&stack_a);
	free_2d(args);
	system("leaks a.out");
}
