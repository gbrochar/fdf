/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:56:59 by gbrochar          #+#    #+#             */
/*   Updated: 2015/12/05 16:22:09 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	str_size;
	int		n_mem;

	n_mem = n;
	str_size = (n < 0) ? 3 : 2;
	while ((n > 9 || n < -9) && str_size++)
		n /= 10;
	str = (char *)malloc((str_size--) * sizeof(char));
	if (!str)
		return (NULL);
	str[str_size--] = '\0';
	while (n_mem > 9 || n_mem < -9)
	{
		str[str_size--] = (n_mem < 0) ? -(n_mem % 10) + '0' : n_mem % 10 + '0';
		n_mem = n_mem / 10;
	}
	str[0] = (n_mem < 0) ? '-' : (n_mem + '0');
	str[1] = (n_mem < 0) ? (-n_mem + '0') : str[1];
	return (str);
}
