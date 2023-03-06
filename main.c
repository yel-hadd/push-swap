/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:54:06 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/07 00:24:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

char	**parse(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	args = parse(--argc, ++argv);
	if (has_errors(args) || !args)
		return (write(1, "Error : Invalid Args\n", 21), 0);
	//if (has_duplicates(argv, argc - 1))
	//	return (write(1, "Error : Duplicate Args\n", 24), 0);
	//// TODO: fix is_sorted bug : false positives when argc = 1
	//if (is_sorted(argv, argc -1))
	//	return (write(1, "Already Sorted !\n", 18), 0);
}
