/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:51:16 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/21 17:26:48 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

int	move_press(int keyCode, t_game *game)
{
	if (keyCode == 53)
		ext(game, 0, 1);
	if (keyCode == 13)
		game->w = true;
	if (keyCode == 1)
		game->s = true;
	if (keyCode == 0)
		game->a = true;
	if (keyCode == 2)
		game->d = true;
	if (keyCode == 124)
		game->right = true;
	if (keyCode == 123)
		game->left = true;
	return (0);
}

int	move_release(int keyCode, t_game *game)
{
	if (keyCode == 13)
		game->w = false;
	if (keyCode == 1)
		game->s = false;
	if (keyCode == 0)
		game->a = false;
	if (keyCode == 2)
		game->d = false;
	if (keyCode == 124)
		game->right = false;
	if (keyCode == 123)
		game->left = false;
	return (0);
}

void	movement_2(t_game *game)
{
	if (game->a)
	{
		if (game->map.area[(int)(game->pos[1])][(int)(game->pos[0]
				- game->plane[0] * game->speed)] != '1')
			game->pos[0] -= game->plane[0] * game->speed;
		if (game->map.area[(int)(game->pos[1] - game->plane[1]
				* game->speed)][(int)(game->pos[0])] != '1')
			game->pos[1] -= game->plane[1] * game->speed;
	}
	if (game->d)
	{
		if (game->map.area[(int)(game->pos[1])][(int)(game->pos[0]
				+ game->plane[0] * game->speed)] != '1')
			game->pos[0] += game->plane[0] * game->speed;
		if (game->map.area[(int)(game->pos[1] + game->plane[1]
				* game->speed)][(int)(game->pos[0])] != '1')
			game->pos[1] += game->plane[1] * game->speed;
	}
}

void	movement(t_game *game)
{
	if (game->w)
	{
		if (game->map.area[(int)(game->pos[1])][(int)(game->pos[0]
				+ game->dir[0] * game->speed)] != '1')
			game->pos[0] += game->dir[0] * game->speed;
		if (game->map.area[(int)(game->pos[1] + game->dir[1]
				* game->speed)][(int)(game->pos[0])] != '1')
			game->pos[1] += game->dir[1] * game->speed;
	}
	if (game->s)
	{
		if (game->map.area[(int)(game->pos[1])][(int)(game->pos[0]
				- game->dir[0] * game->speed)] != '1')
			game->pos[0] -= game->dir[0] * game->speed;
		if (game->map.area[(int)(game->pos[1] - game->dir[1]
				* game->speed)][(int)(game->pos[0])] != '1')
			game->pos[1] -= game->dir[1] * game->speed;
	}
	movement_2(game);
}

void	rotate(t_game *g, double dir, double plane)
{
	if (g->right)
	{
		dir = g->dir[0];
		g->dir[0] = g->dir[0] * cos(g->rspeed) - g->dir[1] * sin(g->rspeed);
		g->dir[1] = dir * sin(g->rspeed) + g->dir[1] * cos(g->rspeed);
		plane = g->plane[0];
		g->plane[0] = g->plane[0] * cos(g->rspeed) - g->plane[1]
			* sin(g->rspeed);
		g->plane[1] = plane * sin(g->rspeed) + g->plane[1] * cos(g->rspeed);
	}
	if (g->left)
	{
		dir = g->dir[0];
		g->dir[0] = g->dir[0] * cos(g->rspeed) + g->dir[1] * sin(g->rspeed);
		g->dir[1] = -dir * sin(g->rspeed) + g->dir[1] * cos(g->rspeed);
		plane = g->plane[0];
		g->plane[0] = g->plane[0] * cos(g->rspeed) + g->plane[1]
			* sin(g->rspeed);
		g->plane[1] = -plane * sin(g->rspeed) + g->plane[1] * cos(g->rspeed);
	}
}
