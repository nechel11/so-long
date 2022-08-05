/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:32:14 by zafar             #+#    #+#             */
/*   Updated: 2022/01/18 11:51:22 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 128

typedef struct s_game
{
	void	*mlx;
	void	*img_background;
	void	*img_player;
	void	*img_wall;
	void	*img_collectable;
	void	*img_exit;
	void	*win;
	int		x_player;
	int		y_player;
	char	**map;
	int		amm_collectable;
	int		amm_exit;
	int		amm_player;
	int		img_w;
	int		img_h;
	int		moves;
	int		endgame;
}	t_game;

void	img_print(t_game *game, void *image, int x, int y);
void	player_print(t_game *game, void *image, int x, int y);
int		map_print(t_game *game);
size_t	ft_strlen(const char *s);
int		ft_is_square(t_game *game);
int		ft_consist_of(char *str);
int		ft_is_wall(char **map);
int		ft_char_counter(t_game *game);
int		ft_is_pec(char **map);
int		map_check(t_game *game);
void	game_init(t_game *game);

char	*get_next_line(int fd);
char	*gnl_read_remainder(int fd, char *temp_line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*gnl_enter(char *temp_line, char *buffer);
char	*gnl_liner(char *temp_line);
char	*gnl_reading(char	*temp_line);
char	**map_reading(char *path);

void	map_clear(char **map);
int		exit_game(t_game *game);
void	game_init(t_game *game);
void	gameplay(t_game *game);
void	print_w(t_game *game);
void	print_s(t_game *game);
void	print_a(t_game *game);
void	print_d(t_game *game);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
