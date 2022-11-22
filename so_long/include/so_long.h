/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:45:19 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 04:48:16 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

# define FALSE 0
# define TRUE 1

# define KEY_PRESS 2
# define KEY_RELEASE 3

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/*
game state
*/
# define ONGOING 100
# define CLEARD 101
# define GAME_OVER 102
// exit button == 17

typedef struct s_path
{
	size_t	cnt;
	int		**visited;
	int		is_valid;
}				t_path;

typedef struct s_img
{
	int		width;
	int		height;
	void	*wall;
	void	*ground;
	void	*sled;
	void	*santa;
	void	*santa2;
	void	*present;
	void	*snowman;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_game
{
	int		width;
	int		height;
	char	**map;
	int		state;
	int		santa_x;
	int		santa_y;
	int		santa_in_sled;
	size_t	move_cnt;
	size_t	present_cnt;
	t_mlx	*mlx;
	t_img	*imgs;
}			t_game;

/*
game, key_event
*/
void	init_game(t_game *game);
void	setting_map(char *filename, t_game *game);
int		check_filename(char *filename);
int		start_game(t_game *game);
void	loop_game(t_game *game);
int		key_event(int keycode, t_game *game);
void	move_santa(t_game *game, int y, int x);
void	adjust_santa_position(t_game *game, int y, int x);

/*
map check
*/
void	check_map(t_game *game);
void	check_rectangular(t_game *game);
void	check_surrounded_walls(t_game *game);
void	check_items(t_game *game);
void	find_items(t_game *game, int *exit, int *collectible, int *start);
void	check_valid_path(t_game *game);
void	free_visited(int **visited);
/*
map setting
*/
void	fill_map(t_game *game);
void	refill_map(t_game *game);
void	setting_imgs(t_game *game);
void	match_img(t_game *game, t_img *imgs, int x, int y);
void	check_empty_map(t_game *game, char *line, char *map);
/*
utils
*/
void	print_error(char *message);
char	*ft_strdup(const char *s1);
int		exit_game(t_game *game);
void	free_memory(t_game *game);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);

#endif