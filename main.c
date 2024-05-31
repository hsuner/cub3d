/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:50:58 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/22 14:45:37 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "minilibx/mlx.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_manager(&game);
	if (ac == 2)
	{
		is_cub(av[1], &game);
		map_read_and_parsing(&game);
		map_check(&game);
		ray_and_mlx_init(&game);
		ft_mlx(&game, 0, 0);
		mlx_hook(game.mlx.win, 2, 0, move_press, &game);
		mlx_hook(game.mlx.win, 3, 0, move_release, &game);
		mlx_hook(game.mlx.win, 17, 0, exit_mlx, &game);
		mlx_loop_hook(game.mlx.ptr, &gamefunc, &game);
		mlx_loop(game.mlx.ptr);
		ext(&game, 0, 1);
	}
	else
		return (printf("Error\n"), 1);
	return (0);
}
