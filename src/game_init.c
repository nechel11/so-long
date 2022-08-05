/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:00:32 by zafar             #+#    #+#             */
/*   Updated: 2022/01/11 12:10:40 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_upload(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image
		(game->mlx, "img/background.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "img/player.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "img/walls.xpm", &game->img_w, &game->img_h);
	game->img_collectable = mlx_xpm_file_to_image
		(game->mlx, "img/collect.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "img/exit.xpm", &game->img_w, &game->img_h);
}

static void	window_sizer(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	str = '\0';
	while (game->map[i] != str)
		i++;
	game->img_h = i * 32;
	game->img_w = ft_strlen(game->map[0]) * 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	window_sizer(game);
	game->win = mlx_new_window(game->mlx, game->img_w, game->img_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	img_upload(game);
	map_print(game);
}
