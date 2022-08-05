/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:09:14 by zafar             #+#    #+#             */
/*   Updated: 2022/01/17 13:52:27 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_square(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_char_counter(t_game *game)
{
	int	x;
	int	y;

	game->amm_collectable = 0;
	game->amm_player = 0;
	game->amm_exit = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x++])
		{
			if (game->map[y][x] == 'C')
				game->amm_collectable++;
			else if (game->map[y][x] == 'P')
				game->amm_player++;
			else if (game->map[y][x] == 'E')
				game->amm_exit++;
		}
		y++;
	}
	if (game->amm_collectable == 0 || game->amm_exit == 0
		|| game->amm_player != 1)
		return (0);
	return (1);
}

int	ft_is_wall(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	if ((!ft_consist_of(map[0])) || (!ft_consist_of(map[i - 1])))
		return (0);
	return (1);
}

int	ft_is_pec(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'C' && map[y][x] != 'E' &&
					map[y][x] != 'P' && map[y][x] != '1' &&
					map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_check(t_game *game)
{
	if (ft_is_square(game) && ft_is_wall(game->map)
		&& ft_char_counter(game) && ft_is_pec(game->map))
		return (1);
	return (0);
}
