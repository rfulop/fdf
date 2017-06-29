/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 04:07:51 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/30 18:58:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


void	interesting(t_mlx *mlx, int wid, int hei);

int		my_key_func(int keycode, void *param, t_mlx *mlx)
{
	printf("Key event %d\n", keycode);
	if (keycode == 69)
	{
		printf("nana\n");
		interesting(mlx, mlx->tmp_x++, mlx->tmp_y++);
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->image.ptr, 0, 0);
	}
	printf("kaka\n");
	return (0);
}

void	put_pixel_image(char *data, int x, int y)
{
	int	a;
	int	pixel;

	a = 0;
	pixel = (4 * 800 * y) + (4 * x);
//	printf("x = %d y = %d pix = %d\n", x, y, pixel);
	while (a < 3)
	{
		data[pixel + a] = 255;
		++a;
	}
	data[pixel + a] = 0;
}

void 	interesting(t_mlx *mlx, int wid, int hei)
{
	int x;
	int y;

	x = mlx->x;
	while (x < wid)
	{
		y = mlx->y;
		while (y < hei)
		{
			printf("x = %d y = %d\n", x, y);
			put_pixel_image(mlx->image.data, x, y);
			++y;
		}
		++x;
	}
	mlx->x = x;
	mlx->y = y;
}

int 	ft_check_line(char *line, t_mlx *mlx)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (line[a])
	{
		if (line[a] == ' ')
			count++;
		if (!ft_isdigit(line[a]) && (line[a] == '-' && !ft_isdigit(line[a + 1])))
			exit (0);
	a++;
	}
	if (!mlx->columns)
		mlx->columns = count;
	if (count != mlx->columns)
		exit (0);
	return (1);
}

void ft_put_points(t_mlx *mlx, int x, int y)
{
	char *str;

	printf("%d %d ", x, y);
	mlx->point[y][x].y = y;
	mlx->point[y][x].x = x;
	printf("%d\n", ft_atoi(mlx->file));
	mlx->point[y][x].z = ft_atoi(mlx->file);
	mlx->point[y][x].color = 0xffffff;
	str = mlx->file;
	while (*str == '-' || ft_isdigit(*str))
		str++;
	while (*str == ' ')
		str++;
	mlx->file = str;
}

void 	ft_make_tab(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(mlx->point = (t_point**)malloc(sizeof(t_point*) * mlx->lines +1 )))
		exit(0);
	while (y < mlx->lines)
	{
		if (!(mlx->point[y] = (t_point*)malloc(sizeof(t_point) * mlx->columns +1)))
			exit(0);
		while (x < mlx->columns)
		{
			ft_put_points(mlx, x, y);
			++x;
		}
		x = 0;
		++y;
	}
}

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	t_mlx mlx;

	mlx.lines = 0;
	mlx.columns = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	mlx.file = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		ft_check_line(line, &mlx);
		mlx.file = ft_strjoin(mlx.file, line);
	//	mlx.file = ft_strjoin(mlx.file, "\n");
		mlx.lines++;
		free(line);
	}
	printf("lines = %d columns = %d\n", mlx.lines, mlx.columns);
	ft_make_tab(&mlx);
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "new window");
	mlx.image.ptr = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
//	image_data = (int*)mlx_get_data_addr(image, &bpp, &size_line, &endian);
	mlx.image.data = mlx_get_data_addr(mlx.image.ptr, &mlx.image.bpp,
										&mlx.image.size_line, &mlx.image.endian);
	mlx.x = 0;
	mlx.y = 0;
	mlx.tmp_y = 200;
	mlx.tmp_x = 200;
	interesting(&mlx, mlx.tmp_x, mlx.tmp_y);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.image.ptr, 0, 0);
/*	mlx_key_hook(mlx.window, my_key_func, &mlx);*/
	mlx_loop(mlx.ptr);
	return (0);
}
