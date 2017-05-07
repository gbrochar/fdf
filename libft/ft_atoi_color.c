/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:18:43 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/06 10:25:37 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_color(char *hexa_color)
{
	int		i;
	int		result;

	result = 0;
	i = 5;
	while (i >= 0)
	{
		if (hexa_color[i] >= '0' && hexa_color[i] <= '9')
			result += (hexa_color[i] - '0') * ft_power(16, (6 - i));
		else if (hexa_color[i] >= 'A' && hexa_color[i] <= 'F')
			result += (hexa_color[i] - '0') * ft_power(16, (6 - i));
		else
			return (-1);
		i--;
	}
	return (result);
}
