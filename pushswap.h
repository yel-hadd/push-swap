/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/29 17:10:54 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	data;
	struct s_stack	*next;
	int	position;
} t_stack;

int	ft_isdigit(int c);
int	has_duplicates(char **args, int count);
int	has_errors(char **args);
int	is_sorted(char **args, int count);
int	ft_atoi(char *str);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *s);
t_stack	*ft_lstnew(int content, size_t position);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	get_lst_position(t_stack **lst);
char	**ft_split(char *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_lstclear(t_stack **head);
#endif
