/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:11:47 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 03:12:30 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game)
{
	char	*move_cnt;

	move_cnt = ft_itoa(game->move_cnt);
	mlx_string_put(game->mlx->mlx, game->mlx->win, 32 * game->width - 64, 32, \
	0x00FF0000, "MOVEMENT COUNT : ");
	mlx_string_put(game->mlx->mlx, game->mlx->win, 32 * game->width + 96, 32, \
	0x00FF0000, move_cnt);
	free(move_cnt);
	if (game->state == CLEARD)
	{
		mlx_string_put(game->mlx->mlx, game->mlx->win, 64, 32, 0x00FF0000, \
		"CLEAR!");
		exit_game(game);
	}
	else if (game->state == GAME_OVER)
	{
		mlx_string_put(game->mlx->mlx, game->mlx->win, 64, 32, 0x00FF0000, \
		"GAME OVER!");
		exit_game(game);
	}
	return (0);
}
