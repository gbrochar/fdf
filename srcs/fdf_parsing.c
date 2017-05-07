/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 03:54:03 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/09 11:23:53 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_file(int fd, char *file_name)
{
	char	**file_content;
	char	*buffer;
	int		line_number;
	int		ret;

	line_number = 0;
	while ((ret = get_next_line(fd, &buffer)) > 0)
		line_number++;
	if (ret == -1)
		return (NULL);
	file_content = (char **)malloc((line_number + 1) * sizeof(char *));
	file_content[line_number] = NULL;
	close(fd);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	line_number = 0;
	while ((ret = get_next_line(fd, &buffer)) > 0)
		file_content[line_number++] = ft_strdup(buffer);
	close(fd);
	return (file_content);
}

int		check_str(char *str)
{
	int		i;
	int		hex_count;

	i = 0;
	hex_count = 0;
	if (str[i] == '-')
		++i;
	while (ft_isdigit(str[i]) == 1 && str[i])
		++i;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

int		**parse(char ***fdf_map)
{
	int		i;
	int		j;

	i = 0;
	while (fdf_map[i])
	{
		j = 0;
		while (fdf_map[i][j])
		{
			if (check_str(fdf_map[i][j]) == 1)
				return (NULL);
			j++;
		}
		++i;
	}
	return (get_struct(fdf_map));
}

int		check_line_lenght(char ***fdf_map, t_mlx *mlx)
{
	int		i;
	int		len;
	int		len_buf;

	i = 0;
	len = 0;
	while (fdf_map[i][len])
		++len;
	while (fdf_map[++i])
	{
		len_buf = 0;
		while (fdf_map[i][len_buf])
			++len_buf;
		if (len_buf != len)
			return (1);
	}
	mlx->xmax = len;
	return (0);
}

int		**fdf_parsing(char *file_name, t_mlx *mlx)
{
	char	**file_content;
	char	***fdf_map;
	int		fd;
	int		i;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	file_content = get_file(fd, file_name);
	i = 0;
	while (file_content[i])
		i++;
	fdf_map = (char ***)malloc((i + 1) * sizeof(char **));
	mlx->zmax = i;
	fdf_map[i] = NULL;
	i = 0;
	while (file_content[i])
	{
		fdf_map[i] = ft_strsplit(file_content[i], ' ');
		++i;
	}
	if (check_line_lenght(fdf_map, mlx))
		return (NULL);
	return (parse(fdf_map));
}
