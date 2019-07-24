/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:19:41 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/24 13:03:44 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
** Rotate z
*/
/*
static void	rotate_z(int key, t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->ymax)
	{
		x = 0;
		while (x < fdf->xmax)
		{
			if (fdf->map[y][x].z != 0.0)
			{
				if (key == 5)
					fdf->map[y][x].y -= fdf->map[y][x].z;
				else
					fdf->map[y][x].y += fdf->map[y][x].z;
			}
			x++;
		}
		y++;
	}
}
*/
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
	printf("%d\n", key);
	return (0);
}

int			mouse_hook(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
/*	if (key == 5 || key == 4)
	{
		write(1, "0", 1);
		rotate_y(key + 121, fdf);
		write(1, "1", 1);
		mlx_clear_window(fdf->mlx, fdf->win);
		write(1, "2", 1);
		draw_image(fdf);
		write(1, "3", 1);
	}
*/
	printf("%d\n", key);
	return (0);
}
