/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 22:19:58 by gbrochar          #+#    #+#             */
/*   Updated: 2016/03/12 08:48:12 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 16

int		get_next_line(int const fd, char **line);
int		gnl_get_overflow(char **data_overflow, char **line);
int		gnl_check_read(char *buf, char **data_overflow, char **line);

#endif
