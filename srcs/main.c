/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:22:54 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:19:43 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_mlx *mlx)
{
	mlx->color = COLOR;
	mlx->z = ZOOM;
	mlx->d = DEPTH;
	mlx->w = TILE_WIDTH;
	mlx->h = TILE_HEIGHT;
	mlx->x0 = ORIGINX;
	mlx->y0 = ORIGINY;
}

int		init_mlx(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (1);
	if (!(mlx->win = mlx_new_window(mlx->ptr, WINX, WINY, "42")))
	{
		free(mlx->ptr);
		return (1);
	}
	mlx_hook(mlx->win, 2, 1L << 1, &key_hook, mlx);
	return (0);
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc == 2)
	{
		reset(&mlx);
		if (!(mlx.m = fdf_parsing(argv[1], &mlx)))
			ft_error();
		if (init_mlx(&mlx))
			ft_error();
		fdf(mlx);
		mlx_loop(mlx.ptr);
	}
	else
		ft_putendl("usage: ./fdf source_file");
	return (0);
}
