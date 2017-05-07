/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:49:32 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/28 16:39:13 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	i_mem;
	size_t	i_tofind;

	i_mem = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i_mem] != '\0' && i_mem < n)
	{
		i_tofind = 0;
		while (s1[i_mem] != s2[i_tofind] && s1[i_mem] != '\0')
			i_mem++;
		if (s1[i_mem] == '\0')
			return (NULL);
		i = i_mem;
		while ((s1[i] == s2[i_tofind] || s2[i_tofind] == '\0') && i++ <= n)
			if (s2[i_tofind++] == '\0')
				return ((char *)&s1[i_mem]);
		if (i > n)
			return (NULL);
		i_mem++;
	}
	return (NULL);
}
