/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:46:53 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				position;
}	t_stack;

void	sort_gt_five(t_stack **a, t_stack **b, int divide, int size);
void	push_chunk(t_stack **a, t_stack **b, int start, int stop);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	push(t_stack **dest, t_stack **source, char stack);
void	master_filter(t_stack **a, t_stack **b, int size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	push_back(t_stack **a, t_stack **b, int max);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		top_or_buttom(t_stack *stack, int position);
t_stack	*ft_lstnew(int content, size_t position);
void	add_index(t_stack **lst, t_stack **node);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	add_to_stack(t_stack **lst, char **argv);
void	reverse_rotate(t_stack **a, char stack);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	get_lst_position(t_stack **lst);
void	rotate(t_stack **a, char stack);
char	**parse(int argc, char **argv, int z);
void	swap(t_stack **a, char stack);
size_t	count_words(char *s, char c);
t_stack	*ft_before_last(t_stack *a);
char	**ft_split(char *s, char c);
void	ft_lstclear(t_stack **head);
int		has_duplicates(char **args);
void	ft_bzero(void *s, size_t n);
void	print_stack(t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		has_errors(char **args);
void	sort_three(t_stack **a);
int		is_sorted(char **args);
int		empty_arg(char **argv);
int		has_spaces(char *str);
char	*ft_strdup(char *s1);
void	free_2d(char **arr);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_isspace(char c);
int		ft_isdigit(int c);

#endif
