/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:13:46 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/30 14:46:05 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_byte;
	unsigned char	*s2_byte;
	size_t			i;

	s1_byte = (unsigned char *)s1;
	s2_byte = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (s1_byte[i] == s2_byte[i])
	{
		if (i + 1 == n)
			return (0);
		i++;
	}
	return (s1_byte[i] - s2_byte[i]);
}
