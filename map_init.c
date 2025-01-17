/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:55 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/22 14:39:59 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_null.h>
#include "cub3d.h"

static void	map_init2(t_map *map)
{
	map->fd = 0;
	map->max = 0;
	map->start = 0;
	map->f_rgb[0] = -1;
	map->f_rgb[1] = -1;
	map->f_rgb[2] = -1;
	map->c_rgb[0] = -1;
	map->c_rgb[1] = -1;
	map->c_rgb[2] = -1;
	map->colors[0] = 0;
	map->colors[1] = 0;
	map->position[0] = 0;
	map->position[1] = 0;
	map->nswe_size[0] = 0;
	map->nswe_size[1] = 0;
	map->nswe_size[2] = 0;
	map->nswe_size[3] = 0;
	map->size = 0;
}

static void	map_init(t_map *map)
{
	map->dirs[0] = NULL;
	map->dirs[1] = NULL;
	map->dirs[2] = NULL;
	map->dirs[3] = NULL;
	map->color = NULL;
	map->info = NULL;
	map->area = NULL;
	map->temp_area = NULL;
	map->line = NULL;
	map->map_line = NULL;
	map->info_line = NULL;
	map->player = 0;
	map_init2(map);
}

void	init_image(t_game *game)
{
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->image = NULL;
}

void	init_manager(t_game *game)
{
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	init_image(game);
	map_init(&game->map);
}
