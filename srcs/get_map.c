/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 23:44:15 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:24:17 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**fdf_malloc_map(char ***fdf_map)
{
	int		**map;
	int		i;
	int		i2;
	int		len;

	i = 0;
	i2 = -1;
	len = 0;
	while (fdf_map[i])
		++i;
	while (fdf_map[0][len])
		len++;
	if (!(map = (int **)malloc(i * sizeof(int *))))
		return (NULL);
	while (++i2 != i)
		if (!(map[i2] = (int *)malloc(len * sizeof(int))))
			return (NULL);
	return (map);
}

void	get_map(int **map, char ***fdf_map)
{
	int		i;
	int		j;

	i = 0;
	while (fdf_map[i])
	{
		j = 0;
		while (fdf_map[i][j])
		{
			map[i][j] = ft_atoi(fdf_map[i][j]);
			++j;
		}
		++i;
	}
}

int		**get_struct(char ***fdf_map)
{
	int		**map;

	if (!(map = fdf_malloc_map(fdf_map)))
		return (NULL);
	get_map(map, fdf_map);
	return (map);
}
