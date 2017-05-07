/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:54:12 by gbrochar          #+#    #+#             */
/*   Updated: 2015/12/07 11:00:33 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	i2;
	size_t	ws;

	i = ft_strlen(s) - 1;
	i2 = 0;
	ws = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i--)
		ws++;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && ws < ft_strlen(s))
	{
		i++;
		ws++;
	}
	str = (char *)malloc((ft_strlen(s) + 1 - ws) * sizeof(char));
	if (!str)
		return (NULL);
	while (i2 < (ft_strlen(s) - ws))
		str[i2++] = s[i++];
	str[i2] = '\0';
	return (str);
}
