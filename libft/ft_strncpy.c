/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:18:18 by gbrochar          #+#    #+#             */
/*   Updated: 2015/11/25 16:21:09 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i != n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
