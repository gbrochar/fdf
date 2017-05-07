/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:24:20 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:45:28 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define ABS(a) ((a) < 0 ? -(a) : (a))

# define COLOR 0xFFFFFF
# define ZOOM 1
# define DEPTH 1
# define TILE_WIDTH 32
# define TILE_HEIGHT 16
# define ORIGINX 960
# define ORIGINY 100
# define WINX 1920
# define WINY 1080

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				color;
	int				nothing;
}					t_fdf;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				xmax;
	int				x0;
	int				x1;
	int				x2;
	int				zmax;
	int				y0;
	int				y1;
	int				y2;
	float			h;
	float			w;
	int				color;
	int				**grid;
	float			d;
	float			z;
	int				**m;
}					t_mlx;

int					**get_struct(char ***fdf_map);
int					**fdf_parsing(char *file_name, t_mlx *mlx);
void				mlx_swap(t_mlx *mlx);
void				reset(t_mlx *mlx);
void				mlx_draw_line(t_mlx mlx);
int					*ft_atoi_split(char **to_split, t_mlx *mlx);
void				fdf(t_mlx mlx);
int					key_hook(int keycode, void *mlx_void);

#endif
