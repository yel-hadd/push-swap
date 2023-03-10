/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:20 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:24 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dstcpy;

	dstcpy = dst;
	if (!dst && !src)
		return (dstcpy);
	while ((n > 0))
	{
		*(char *)dst ++ = *(char *)src ++;
		n --;
	}
	return (dstcpy);
}