/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:59:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/22 15:02:32 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_fdf *fdf, t_map map0, t_map map1)
{
	double x;
	double y;

	x = map0.x;
	y = map0.y;
	if (fabs(map0.y - map1.y) > fabs(map0.x - map1.y))
		while ((map0.y > map1.y ? y >= map1.y : y <= map1.y))
		{
			x = /*((y - map0.y)/(map1.y - map0.y)) * (map1.x - map0.x) + */map0.x;
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, map0.color);
			y += map0.y > map1.y ? -1 : 1;
		}
	else
		while ((map0.x > map1.x ? x >= map1.x : x <= map1.x))
		{
			y = /*((x - map0.x)/(map1.x - map0.x)) * (map1.y - map0.y) + */map0.y;
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, map0.color);
			x += map0.x > map1.x ? -1 : 1;
		}
}

/*
** Place image
*/

static void	draw_image(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			if ((x + 1) < fdf->xmax)
				draw_line(fdf, fdf->map[y][x], fdf->map[y][x + 1]);
			if ((y + 1) < fdf->ymax)
				draw_line(fdf, fdf->map[y][x], fdf->map[y + 1][x]);
			x++;
		}
		y++;
	}
}

/*
** Place coordinate to the center of window
*/

static void	place_to_center(t_fdf *fdf)
{
	int x;
	int y;

	if (fmaxf(fdf->xmax, fdf->ymax) == fdf->xmax)
		fdf->zoom = W / fdf->xmax;
	else
		fdf->zoom = H / fdf->ymax;
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
			fdf->map[y][x].z *= fdf->zoom;
			x++;
		}
		y++;
	}
}

/*
** Create new window and place there image
*/

void		create_image(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W, H, "FDF");
	place_to_center(fdf);
	draw_image(fdf);
	mlx_loop(fdf->mlx);
}
