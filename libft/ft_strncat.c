/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:29:04 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/29 12:33:35 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i_dst;
	size_t	i_src;

	i_dst = ft_strlen(s1);
	i_src = 0;
	while (i_src < n && s2[i_src] != '\0')
	{
		s1[i_dst] = s2[i_src];
		i_dst++;
		i_src++;
	}
	s1[i_dst] = '\0';
	return (s1);
}
