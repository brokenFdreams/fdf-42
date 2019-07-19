/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:59:03 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/19 13:07:58 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# inlcude "libft/libft.h"
# include "libft/getnextline.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_map
{
	double		x;
	double		y;
	double		z;
	long int	color;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	int			fd;
	double		xmax;
	double		yamx;
	double		zoom;
}				t_fdf;

void		ft_error(char *message);

#endif
