/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:05:13 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/05 23:49:25 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_tool(int tool[6], t_mlx mlx)
{
	tool[0] = ABS(mlx.x2 - mlx.x1);
	tool[1] = mlx.x1 < mlx.x2 ? 1 : -1;
	tool[2] = -ABS(mlx.y2 - mlx.y1);
	tool[3] = mlx.y1 < mlx.y2 ? 1 : -1;
	tool[4] = tool[0] + tool[2];
}

void	mlx_draw_line(t_mlx mlx)
{
	int		tool[6];

	init_tool(tool, mlx);
	while (1)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, mlx.x1, mlx.y1, mlx.color);
		if (mlx.x1 == mlx.x2 && mlx.y1 == mlx.y2)
			break ;
		tool[5] = 2 * tool[4];
		if (tool[5] >= tool[2])
		{
			tool[4] += tool[2];
			mlx.x1 += tool[1];
		}
		if (tool[5] <= tool[0])
		{
			tool[4] += tool[0];
			mlx.y1 += tool[3];
		}
	}
}
