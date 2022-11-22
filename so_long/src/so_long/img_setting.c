/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:50:54 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 03:00:37 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_imgs(t_game *game)
{
	t_img	*imgs;

	imgs = (t_img *)malloc(sizeof(t_img));
	if (!imgs)
		print_error("Failed to allocation memory\n");
	imgs->wall = mlx_xpm_file_to_image(game->mlx->mlx, "./img/wall.xpm", \
				&imgs->width, &imgs->height);
	imgs->ground = mlx_xpm_file_to_image(game->mlx->mlx, "./img/ground.xpm", \
				&imgs->width, &imgs->height);
	imgs->sled = mlx_xpm_file_to_image(game->mlx->mlx, "./img/sled.xpm", \
				&imgs->width, &imgs->height);
	imgs->santa = mlx_xpm_file_to_image(game->mlx->mlx, "./img/santa.xpm", \
				&imgs->width, &imgs->height);
	imgs->present = mlx_xpm_file_to_image(game->mlx->mlx, "./img/present.xpm", \
				&imgs->width, &imgs->height);
	imgs->snowman = mlx_xpm_file_to_image(game->mlx->mlx, "./img/snowman.xpm", \
				&imgs->width, &imgs->height);
	imgs->santa2 = mlx_xpm_file_to_image(game->mlx->mlx, \
					"./img/santa2.xpm", &imgs->width, &imgs->height);
	game->imgs = imgs;
}

void	match_img(t_game *game, t_img *imgs, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, imgs->wall, \
		x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, imgs->ground, \
		x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, imgs->sled, \
		x * 64, y * 64);
	else if (game->map[y][x] == 'P')
	{
		if (game->move_cnt % 2)
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
			imgs->santa, x * 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
			imgs->santa2, x * 64, y * 64);
	}
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, imgs->present, \
		x * 64, y * 64);
	else if (game->map[y][x] == 'S')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, imgs->snowman, \
		x * 64, y * 64);
}

void	fill_map(t_game *game)
{
	int	x;
	int	y;

	setting_imgs(game);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			match_img(game, game->imgs, x, y);
	}
}

void	refill_map(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			match_img(game, game->imgs, x, y);
	}
}
