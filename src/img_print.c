/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:55:47 by zafar             #+#    #+#             */
/*   Updated: 2022/01/06 13:58:06 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_print(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

void	player_print(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_print(game, image, x, y);
}

int	map_print(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_print(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_print(game, game->img_background, x, y);
			else if (game->map[y][x] == 'C')
				img_print(game, game->img_collectable, x, y);
			else if (game->map[y][x] == 'E')
				img_print(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'P')
				player_print(game, game->img_player, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
