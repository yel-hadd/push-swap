/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/02/03 21:58:37 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int	data;
	struct s_stack	*next;
	int	position;
} t_stack;

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_stack	*ft_lstnew(int content, size_t position);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	add_index(t_stack **lst, t_stack **node);
void	reverse_rotate(t_stack **a, char stack);
int		has_duplicates(char **args, int count);
int		is_sorted(char **args, int count);
void	get_lst_position(t_stack **lst);
void	swap(t_stack **a, char stack);
t_stack *ft_before_last(t_stack *a);
char	**ft_split(char *s, char c);
void	ft_lstclear(t_stack **head);
void	print_stack(t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		has_errors(char **args);
int		has_spaces(char *str);
void 	free_2d(char **arr);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_isdigit(int c);

#endif
