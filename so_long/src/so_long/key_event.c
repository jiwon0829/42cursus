/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 05:36:23 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 02:01:46 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_santa(t_game *game, int y, int x)
{
	if (game->map[game->santa_y + y][game->santa_x + x] == '1')
		return ;
	else if (game->map[game->santa_y + y][game->santa_x + x] == 'C')
		game->present_cnt -= 1;
	else if (game->map[game->santa_y + y][game->santa_x + x] == 'E')
	{
		if (game->present_cnt == 0)
			game->state = CLEARD;
	}
	else if (game->map[game->santa_y + y][game->santa_x + x] == 'S')
	{
		game->state = GAME_OVER;
		return ;
	}
	adjust_santa_position(game, y, x);
	refill_map(game);
}

void	adjust_santa_position(t_game *game, int y, int x)
{
	if (game->santa_in_sled == TRUE)
	{
		game->map[game->santa_y][game->santa_x] = 'E';
		game->santa_in_sled = FALSE;
	}
	else
		game->map[game->santa_y][game->santa_x] = '0';
	game->santa_x += x;
	game->santa_y += y;
	if (game->map[game->santa_y][game->santa_x] == 'E')
		game->santa_in_sled = TRUE;
	game->map[game->santa_y][game->santa_x] = 'P';
	game->move_cnt += 1;
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (game->state != ONGOING)
		return (0);
	if (keycode == KEY_W)
		move_santa(game, -1, 0);
	else if (keycode == KEY_A)
		move_santa(game, 0, -1);
	else if (keycode == KEY_S)
		move_santa(game, 1, 0);
	else if (keycode == KEY_D)
		move_santa(game, 0, 1);
	return (0);
}
