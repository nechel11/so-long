/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:09:02 by zafar             #+#    #+#             */
/*   Updated: 2022/01/21 12:39:14 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	movements_events(int button, t_game *game)
{
	if (button == 65362 || button == 1731)
	{
		game->y_player = game->y_player - 1;
		print_w(game);
	}
	else if (button == 65364 || button == 1753)
	{
		game->y_player = game->y_player + 1;
		print_s(game);
	}
	else if (button == 65361 || button == 1734)
	{
		game->x_player = game->x_player - 1;
		print_a(game);
	}
	else if (button == 65363 || button == 1751)
	{
		game->x_player = game->x_player + 1;
		print_d(game);
	}
}

static int	exit_press(int button, t_game *game)
{
	if (button == 65307)
	{
		exit_game(game);
	}
	else if (!game->endgame)
	{
		movements_events(button, game);
		printf("Move number is %i\n", game->moves);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, exit_press, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
