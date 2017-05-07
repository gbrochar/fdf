/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:36:04 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/25 13:03:31 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;
	size_t				index;

	dst_byte = dst;
	src_byte = src;
	if (dst_byte > src_byte)
	{
		index = len;
		while (index-- > 0)
			dst_byte[index] = src_byte[index];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			dst_byte[index] = src_byte[index];
			index++;
		}
	}
	return (dst);
}
