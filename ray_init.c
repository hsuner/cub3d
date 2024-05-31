/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:51:23 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/22 14:39:59 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "minilibx/mlx.h"

static bool	east_west(t_game *game)
{
	if (game->map.player == 'W')
	{
		game->dir[0] = -1;
		game->dir[1] = 0;
		game->plane[0] = 0;
		game->plane[1] = -0.66;
		return (true);
	}
	else if (game->map.player == 'E')
	{
		game->dir[0] = 1;
		game->dir[1] = 0;
		game->plane[0] = 0;
		game->plane[1] = 0.66;
		return (true);
	}
	return (false);
}

static bool	south_north(t_game *game)
{
	if (game->map.player == 'S')
	{
		game->dir[0] = 0;
		game->dir[1] = 1;
		game->plane[0] = -0.66;
		game->plane[1] = 0;
		return (true);
	}
	else if (game->map.player == 'N')
	{
		game->dir[0] = 0;
		game->dir[1] = -1;
		game->plane[0] = 0.66;
		game->plane[1] = 0;
		return (true);
	}
	return (false);
}

bool	check_player(t_game *game)
{
	if (east_west(game))
		return (true);
	if (south_north(game))
		return (true);
	return (false);
}

void	ray_and_mlx_init(t_game *game)
{
	if (!check_player(game))
		return (printf("Error\n"), ext(game, 1, 1));
	game->pos[0] = game->map.position[1] + 0.5;
	game->pos[1] = game->map.position[0] + 0.5;
	game->speed = 0.065;
	game->rspeed = 0.035;
	game->w = false;
	game->a = false;
	game->s = false;
	game->d = false;
	game->left = false;
	game->right = false;
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (printf("Error\n"), ext(game, 1, 0));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->mlx.win)
		return (printf("Error\n"), ext(game, 1, 0));
}
