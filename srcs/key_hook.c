/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:23:56 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:24:38 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_keycode_1(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 125 || keycode == 1)
		mlx->y0 += 10;
	if (keycode == 123 || keycode == 0)
		mlx->x0 -= 10;
	if (keycode == 124 || keycode == 2)
		mlx->x0 += 10;
	if (keycode == 126 || keycode == 13)
		mlx->y0 -= 10;
	if (keycode == 32)
		mlx->d += 0.1;
	if (keycode == 38 && mlx->d > 0)
		mlx->d -= 0.1;
	if (keycode == 16)
		mlx->d += 0.5;
	if (keycode == 4 && mlx->d > 1)
		mlx->d -= 0.5;
}

void	manage_keycode_2(int keycode, t_mlx *mlx)
{
	if (keycode == 69)
	{
		mlx->z += 0.08;
		mlx->y0 -= mlx->zmax;
		mlx->w *= 1.2;
		mlx->h *= 1.2;
	}
	if (keycode == 78 && mlx->h > 3)
	{
		mlx->z -= 0.08;
		mlx->y0 += mlx->zmax;
		mlx->w /= 1.2;
		mlx->h /= 1.2;
	}
	if (keycode == 15)
		reset(mlx);
}

int		key_hook(int keycode, void *mlx_void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_void;
	manage_keycode_1(keycode, mlx);
	manage_keycode_2(keycode, mlx);
	mlx_clear_window(mlx->ptr, mlx->win);
	fdf(*mlx);
	return (0);
}
