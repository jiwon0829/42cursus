/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:45:28 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 04:48:18 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
		print_error("Failed to load map\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_error("Failed to allocation memory\n");
	init_game(game);
	setting_map(av[1], game);
	check_map(game);
	game->mlx->mlx = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->width * 64, \
					game->height * 64, "Collecting Christmas presents");
	fill_map(game);
	mlx_hook(game->mlx->win, 17, 0, exit_game, game);
	mlx_hook(game->mlx->win, KEY_RELEASE, 0, &key_event, game);
	mlx_loop_hook(game->mlx->mlx, start_game, game);
	mlx_loop(game->mlx->mlx);
}
