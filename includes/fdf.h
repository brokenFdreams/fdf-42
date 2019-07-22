/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:59:03 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/22 12:51:26 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define W 1000
# define H 1000

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
	t_map		**map;
	int			fd;
	double		xmax;
	double		ymax;
	double		zoom;
}				t_fdf;

void		ft_error(char *message);
void		reading(char *file, t_fdf *fdf);
long int	ft_atoi_base(char *str, int base);
void		ft_line_list(t_list **begin, void *line);
void		ft_freelist(t_list **begin);
void		validation(t_list *lines);
size_t		ft_count_words(char const *s, char c);
void		create_image(t_fdf *fdf);

#endif
