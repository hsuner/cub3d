/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:06:37 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/22 14:39:59 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc/_malloc.h>
#include "cub3d.h"
#include "libft/libft.h"

static	int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (!!str && str[i])
		i++;
	return (i);
}

static void	path_finder(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= game->map.start || y >= \
	ft_strlen_2d(game->map.area) || game->map.temp_area[y][x] == ' ' || \
	game->map.temp_area[y][x] == '\0')
		return (printf("Error\n"), ext(game, 1, 1));
	else if (game->map.temp_area[y][x] == '1')
		return ;
	game->map.temp_area[y][x] = '1';
	path_finder(game, y, x - 1);
	path_finder(game, y - 1, x);
	path_finder(game, y, x + 1);
	path_finder(game, y + 1, x);
}

static void	player_control(t_game game)
{
	int	count_0;
	int	count_1;
	int	i;

	i = 0;
	count_0 = 0;
	count_1 = 0;
	while (i < 4)
	{
		if (game.map.nswe_size[i] == 0)
			count_0++;
		else if (game.map.nswe_size[i] == 1)
			count_1++;
		i++;
	}
	if (count_0 == 3 && count_1 == 1)
		return ;
	else
		return (printf("Error\n"), ext(&game, 1, 1));
}

static int	copy_map(t_game *game, int y, int x)
{
	while (game->map.area[++y])
	{
		x = -1;
		while (game->map.area[y][++x])
		{
			if (game->map.area[y][x] == 'N' || game->map.area[y][x] == 'S'
				|| game->map.area[y][x] == 'W' || game->map.area[y][x] == 'E')
			{
				if (game->map.area[y][x] == 'N')
					game->map.nswe_size[0]++;
				else if (game->map.area[y][x] == 'S')
					game->map.nswe_size[1]++;
				else if (game->map.area[y][x] == 'W')
					game->map.nswe_size[2]++;
				else if (game->map.area[y][x] == 'E')
					game->map.nswe_size[3]++;
				game->map.position[0] = y;
				game->map.position[1] = x;
				game->map.player = game->map.area[y][x];
			}
		}
	}
	if (game->map.position[0] == 0 || game->map.position[1] == 0)
		return (printf("Error\n"), ext(game, 1, 1), 1);
	return (0);
}

void	map_check(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map_line[++i])
	{
		if (game->map.map_line[i] != '1' && game->map.map_line[i] != '0'
			&& game->map.map_line[i] != 'N' && game->map.map_line[i] != 'S'
			&& game->map.map_line[i] != 'W' && game->map.map_line[i] != 'E'
			&& game->map.map_line[i] != '\0' && game->map.map_line[i] != '\n'
			&& !(game->map.map_line[i] >= 9 && game->map.map_line[i] <= 13)
			&& game->map.map_line[i] != 32)
			return (printf("Error\n"), ext(game, 1, 1));
	}
	free(game->map.line);
	game->map.line = ft_strdup(game->map.map_line);
	if (!game->map.line)
		return (printf("Error\n"), ext(game, 1, 1));
	game->map.area = ft_split(game->map.line, '\n');
	game->map.temp_area = ft_split(game->map.line, '\n');
	if (!game->map.area || !game->map.temp_area)
		return (printf("Error\n"), ext(game, 1, 1));
	copy_map(game, -1, -1);
	player_control(*game);
	path_finder(game, game->map.position[0], game->map.position[1]);
	rgb_and_path_check(game);
}
