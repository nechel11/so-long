/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:33:55 by zafar             #+#    #+#             */
/*   Updated: 2022/01/19 17:09:03 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	cheqer(int argc)
{
	if (argc == 2)
		return (1);
	else
	{
		printf("Error : bad arguments\n");
		exit(1);
	}
}

static int	ber_cheq(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1] == 'e'
		&& str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	return (0);
}

static void	error_ft(int i)
{
	(void)i;
	printf("Bad arguments\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (cheqer(argc))
	{
		game.map = map_reading(argv[1]);
		if (!game.map)
			error_ft(1);
		map_check(&game);
		if (map_check(&game) != 0 && ber_cheq(argv[1]) != 0)
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				map_clear(game.map);
			printf("Error : bad map\n");
			exit(1);
		}
	}
	map_clear(game.map);
	return (0);
}
