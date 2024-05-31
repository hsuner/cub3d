/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:11:02 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/22 14:30:47 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx.h"

static void	raycast(t_game *g)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		calculate_ray_direction_and_distances(g, x);
		calculate_step(g);
		calculate_collision_distance(g);
		calculate_wall_properties(g);
		render_column(g, x, -1);
	}
	mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->image->image, 0, 0);
}

int	gamefunc(t_game *game)
{
	movement(game);
	rotate(game, 0, 0);
	raycast(game);
	return (0);
}
