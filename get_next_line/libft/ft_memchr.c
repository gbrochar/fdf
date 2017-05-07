/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:03:54 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/25 14:07:56 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	unsigned char	*str;
	size_t			i;

	i = 0;
	to_find = c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
