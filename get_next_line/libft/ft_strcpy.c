/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:10:54 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/29 22:32:41 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char		*p_dest;
	const char	*p_src;

	p_src = src;
	p_dest = dst;
	while ((*p_dest++ = *p_src++))
		;
	*p_dest = '\0';
	return (dst);
}
