/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:51:07 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/21 17:28:20 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc/_malloc.h>
#include "cub3d.h"
#include "minilibx/mlx.h"

int	exit_mlx(t_game *game)
{
	return (ext(game, 0, 1), 0);
}

static void	ft_mlx2(t_game *g, int c)
{
	g->north->addr = (int *)mlx_get_data_addr(g->north->image, &c, &c, &c);
	g->south->addr = (int *)mlx_get_data_addr(g->south->image, &c, &c, &c);
	g->west->addr = (int *)mlx_get_data_addr(g->west->image, &c, &c, &c);
	g->east->addr = (int *)mlx_get_data_addr(g->east->image, &c, &c, &c);
	if (!g->north->addr || !g->south->addr || !g->west->addr || !g->east->addr)
		return (printf("Error\n"), ext(g, 1, 0));
}

void	ft_mlx(t_game *g, int a, int b)
{
	g->image = malloc(sizeof(t_image));
	g->north = malloc(sizeof(t_image));
	g->south = malloc(sizeof(t_image));
	g->west = malloc(sizeof(t_image));
	g->east = malloc(sizeof(t_image));
	if (!g->image || !g->north || !g->south || !g->west || !g->east)
		return (printf("Error\n"), ext(g, 1, 1));
	g->image->image = mlx_new_image(g->mlx.ptr, WIDTH, HEIGHT);
	if (!g->image->image)
		return (printf("Error\n"), ext(g, 1, 0));
	g->image->addr = (int *)mlx_get_data_addr(g->image->image, &a, &a, &a);
	if (!g->image->addr)
		return (printf("Error\n"), ext(g, 1, 0));
	g->north->image = mlx_xpm_file_to_image(g->mlx.ptr, g->map.dirs[0], &b, &b);
	g->south->image = mlx_xpm_file_to_image(g->mlx.ptr, g->map.dirs[1], &b, &b);
	g->west->image = mlx_xpm_file_to_image(g->mlx.ptr, g->map.dirs[2], &b, &b);
	g->east->image = mlx_xpm_file_to_image(g->mlx.ptr, g->map.dirs[3], &b, &b);
	if (!g->north->image || !g->south->image
		|| !g->west->image || !g->east->image)
		return (printf("Error\n"), ext(g, 1, 0));
	ft_mlx2(g, b);
}
