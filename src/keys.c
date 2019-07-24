/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:19:41 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/24 14:04:02 by fsinged          ###   ########.fr       */
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
	rotate_map(fdf);
}

/*
** Rotate x to left or right
*/

static void	rotate_x(int key, t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			fdf->map[y][x].x += key == 124 ? 10 : -10;
			x++;
		}
		y++;
	}
}

/*
** Rotate y to up or down
*/

static void	rotate_y(int key, t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			fdf->map[y][x].y += key == 125 ? 10 : -10;
			x++;
		}
		y++;
	}
}

/*
** events by keyboard
*/

int			keys_hook(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key == 53)
		exit(1);
	else if (key == 124 || key == 123)
		rotate_x(key, fdf);
	else if (key == 126 || key == 125)
		rotate_y(key, fdf);
	if (key >= 123 && key <= 126)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_image(fdf);
	}
	return (0);
}
