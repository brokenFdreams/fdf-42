/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:32:46 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/19 15:58:50 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fill_map_y(t_fdf *fdf, char *data, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (data[i])
	{
		if (data[i] != ' ')
		{
			(fdf->map)[y][x].y = y;
			(fdf->map)[y][x].x = x;
			(fdf->map)[y][x].z = ft_atoi(data + i);
			while (data[i] && data[i] != ',' && data[i] != ' ')
				i++;
			if (data[i] && data[i] == ',')
				(fdf->map)[y][x].color = ft_atoi_base(data + ++i + 2, 16);
			else
				(fdf->map)[y][x].color = ft_atoi_base("FFFFFF", 16);
			x++;
			while (data[i] && data[i] != ' ')
				i++;
		}
		if (data[i])
			i++;
	}
}

/*
** Fill a map
*/

static void	fill_map(t_fdf *fdf, t_list *lines, int size)
{
	int x;
	int y;

	y = 0;
	if (!(fdf->map = (t_map**)ft_memalloc(sizeof(t_map*) * size)))
		ft_error("Malloc error\n");
	while (lines)
	{
		x = ft_count_words(lines->content, ' ');
		fdf->xmax = x;
		if (!((fdf->map)[y] = (t_map*)ft_memalloc(sizeof(t_map) * x)))
			ft_error("Malloc error\n");
		fill_map_y(fdf, (char*)lines->content, y);
		y++;
		lines = lines->next;
	}
}

/*
** Read data from file
*/

void	reading(char *file, t_fdf *fdf)
{
	int		gnl;
	int		y;
	char	*line;
	t_list	*lines;

	y = 0;
	if ((fdf->fd = open(file, O_RDONLY)) == -1)
		ft_error("Usage: ./fdf [mapfile.fd]\n");
	while ((gnl = get_next_line(fdf->fd, &line)) > 0 && ++y)
		ft_line_list(&lines, line);
	if (gnl == -1)
		ft_error("Usage: ./fdf [mapfile.fd]\n");
	fdf->ymax = y;
	close(fdf->fd);
	validation(lines);
	fill_map(fdf, lines, y);
	create_image(fdf);
	ft_freelist(&lines);
}
