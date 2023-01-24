/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/01/24 18:15:17 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int data;
	struct s_stack *next;
	int position;
} t_stack;

int	ft_isdigit(int c);
int	has_duplicates(char **args);
int	has_errors(char **args);
int	is_sorted(char **args);
int	ft_atoi(const char *str);

#endif
