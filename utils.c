/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:10:52 by hsuner            #+#    #+#             */
/*   Updated: 2024/03/21 17:28:52 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <malloc/_malloc.h>
#include "cub3d.h"
#include "libft/libft.h"

void	rgb_and_path_check(t_game *game)
{
	int	i;

	i = -1;
	if (game->map.size != 6)
		return (printf("Error\n"), ext(game, 1, 1));
	while (++i < 4)
		if (game->map.dirs[i] && ft_strlen(game->map.dirs[i]) <= 1)
			return (printf("Error\n"), ext(game, 1, 1));
	i = -1;
	while (++i < 3)
		if (!(game->map.f_rgb[i] >= 0 && game->map.f_rgb[i] <= 255)
			|| !(game->map.c_rgb[i] >= 0 && game->map.c_rgb[i] <= 255))
			return (printf("Error\n"), ext(game, 1, 1));
	game->map.colors[0] = (game->map.f_rgb[0] << 16) + (game->map.f_rgb[1] << 8)
		+ game->map.f_rgb[2];
	game->map.colors[1] = (game->map.c_rgb[0] << 16) + (game->map.c_rgb[1] << 8)
		+ game->map.c_rgb[2];
}

void	is_cub(char *file_name, t_game *game)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 1] == 'b' && file_name[len - 2] == 'u'
		&& file_name[len - 3] == 'c' && file_name[len - 4] == '.')
	{
		game->map.fd = open(file_name, O_RDONLY);
		if (game->map.fd == -1)
			return (printf("Error\n"), ext(game, 1, 1));
	}
	else
		return (printf("Error\n"), ext(game, 1, 1));
}

int	cub_atoi(t_game *game, const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (48 <= *str && *str <= 57)
		res = (res * 10) + (*str++ - 48);
	if (res * sign < -2147483648 || res * sign > 2147483647)
		return (printf("Error\n"), ext(game, 1, 1), 0);
	return (res * sign);
}
