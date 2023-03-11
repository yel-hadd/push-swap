/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:57:03 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/11 23:04:28 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (0);
	ft_memcpy(s2, (const void *) s1, ((len + 1) * sizeof(char)));
	return (s2);
}
