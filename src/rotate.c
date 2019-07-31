/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:49:51 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/31 13:26:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Changing the coordinate for map rotation
*/

static void	rotate_map(t_fdf *fdf)
{
	int		x;
	int		y;
	double	copyx;
	double	copyy;

	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			copyx = fdf->map[y][x].x;
			copyy = fdf->map[y][x].y;
			fdf->map[y][x].x = fdf->map[y][x].x - (copyy - H / 2)
				- fdf->map[y][x].z;
			fdf->map[y][x].y = fdf->map[y][x].y + (copyx - W / 2)
				- (fdf->map[y][x].z * fdf->zoom / 7.5);
			x++;
		}
		y++;
	}
}

/*
** Place coordinate for second projection
*/

static void	new_projection(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	if (!(fdf->maps = (t_map**)malloc(sizeof(t_map*) * (int)fdf->ymax)))
		ft_error("Malloc error\n");
	while (y < fdf->ymax)
	{
		x = 0;
		if (!(fdf->maps[y] = (t_map*)malloc(sizeof(t_map) * (int)fdf->xmax)))
			ft_error("Malloc error\n");
		while (x < fdf->xmax)
		{
			fdf->maps[y][x].x = fdf->map[y][x].x;
			fdf->maps[y][x].y = fdf->map[y][x].y;
			fdf->maps[y][x].z = fdf->map[y][x].z;
			fdf->maps[y][x].color = fdf->map[y][x].color;
			x++;
		}
		y++;
	}
}

/*
** Place coordinate to the center of window
*/

void		place_to_center(t_fdf *fdf)
{
	int x;
	int y;

	if (fmaxf(fdf->xmax, fdf->ymax) == fdf->xmax)
		fdf->zoom = (W / fdf->xmax) / 2;
	else
		fdf->zoom = (H / fdf->ymax) / 2;
	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			fdf->map[y][x].x = (fdf->map[y][x].x - (fdf->xmax - 1) / 2)
				* fdf->zoom + W / 2;
			fdf->map[y][x].y = (fdf->map[y][x].y - (fdf->ymax - 1) / 2)
				* fdf->zoom + H / 2;
			x++;
		}
		y++;
	}
	new_projection(fdf);
	rotate_map(fdf);
}
