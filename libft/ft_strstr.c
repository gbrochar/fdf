/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:24:53 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/28 16:38:40 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, char *s2)
{
	int		i;
	int		i_mem;
	int		i_tofind;

	i_mem = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i_mem] != '\0')
	{
		i_tofind = 0;
		while (s1[i_mem] != s2[i_tofind] && s1[i_mem] != '\0')
			i_mem++;
		if (s1[i_mem] == '\0')
			return (NULL);
		i = i_mem;
		while (s1[i++] == s2[i_tofind] || s2[i_tofind] == '\0')
			if (s2[i_tofind++] == '\0')
				return ((char *)&s1[i_mem]);
		i_mem++;
	}
	return (NULL);
}
