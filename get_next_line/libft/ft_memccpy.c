/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:00 by gbrochar          #+#    #+#             */
/*   Updated: 2015/12/08 14:37:54 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	to_find;
	unsigned char	*dst_byte;
	unsigned char	*src_byte;

	to_find = (unsigned char)c;
	i = 0;
	dst_byte = (unsigned char *)dst;
	src_byte = (unsigned char *)src;
	while (i != n && src_byte[i] != to_find)
	{
		dst_byte[i] = src_byte[i];
		i++;
	}
	if (src_byte[i] == to_find)
	{
		dst_byte[i] = to_find;
		return (&dst[i + 1]);
	}
	return (NULL);
}
