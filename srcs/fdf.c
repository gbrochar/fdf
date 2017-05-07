/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:49:19 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:29:53 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf(t_mlx e)
{
	int		i;
	int		j;

	i = -1;
	while (++i != e.zmax)
	{
		j = -1;
		while (++j != e.xmax)
		{
			e.x1 = e.x0 + ((j - i) * e.w);
			e.y1 = e.y0 + ((j + i) * e.h) - e.m[i][j] * e.z * e.d;
			if (j != e.xmax - 1)
			{
				e.x2 = e.x0 + (((j + 1) - i) * e.w);
				e.y2 = e.y0 + (((j + 1) + i) * e.h) - e.m[i][j + 1] * e.z * e.d;
				mlx_draw_line(e);
			}
			if (i != e.zmax - 1)
			{
				e.x2 = e.x0 + ((j - (i + 1)) * e.w);
				e.y2 = e.y0 + ((j + (i + 1)) * e.h) - e.m[i + 1][j] * e.z * e.d;
				mlx_draw_line(e);
			}
		}
	}
}
