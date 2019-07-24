/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:59:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/24 15:53:30 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_color(double z0, double z1, t_map *map0)
{
	if (map0->color == -1)
	{
		if (z0 != 0 && z1 != 0 && z0 != z1)
			map0->color = ft_atoi_base("228B22", 16);
		else if (z0 != 0 && z1 != 0 && z0 == z1)
			map0->color = ft_atoi_base("FFFF00", 16);
		else if (z0 || z1)
			map0->color = ft_atoi_base("00CED1", 16);
		else
			map0->color = ft_atoi_base("FFFFFF", 16);
	}
}

static void	draw_line(t_fdf *fdf, t_map map0, t_map map1)
{
	double x;
	double y;

	x = map0.x;
	y = map0.y;
	if (fabs(map1.y - map0.y) > fabs(map1.x - map0.x))
		while ((map0.y > map1.y ? y >= map1.y : y <= map1.y))
		{
			x = ((y - map0.y) / (map1.y - map0.y)) * (map1.x - map0.x) + map0.x;
			set_color(map0.z, map1.z, &map0);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, map0.color);
			y += map0.y > map1.y ? -1 : 1;
		}
	else
		while ((map0.x > map1.x ? x >= map1.x : x <= map1.x))
		{
			y = ((x - map0.x) / (map1.x - map0.x)) * (map1.y - map0.y) + map0.y;
			set_color(map0.z, map1.z, &map0);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, map0.color);
			x += map0.x > map1.x ? -1 : 1;
		}
}

/*
** Place image
*/

void		draw_image(t_fdf *fdf)
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
** Create new window and place there image
*/

void		create_image(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W, H, "FDF");
	place_to_center(fdf);
	draw_image(fdf);
	mlx_key_hook(fdf->win, keys_hook, fdf);
	mlx_loop(fdf->mlx);
}
