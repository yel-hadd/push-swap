/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/27 15:18:45 by yel-hadd         ###   ########.fr       */
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
	size_t	position;
} t_stack;

int	ft_isdigit(int c);
int	has_duplicates(char **args, int count);
int	has_errors(char **args);
int	is_sorted(char **args, int count);
int	ft_atoi(char *str);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *s);
t_stack	*ft_lstnew(int content, int position);

#endif