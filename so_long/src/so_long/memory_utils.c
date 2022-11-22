/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:05 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/11 04:53:08 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < sizeof(t_game))
		((unsigned char *)game)[i++] = 0;
	game->state = ONGOING;
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game->mlx)
		print_error("Failed to allocation memory\n");
	i = 0;
	while (i < sizeof(t_mlx))
		((unsigned char *)game->mlx)[i++] = 0;
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
	{
		free(game->map[i]);
		game->map[i] = 0;
	}	
	free(game->map);
	game->map = 0;
}

void	free_imgs(t_mlx *mlx, t_img *imgs)
{
	mlx_destroy_image(mlx->mlx, imgs->wall);
	mlx_destroy_image(mlx->mlx, imgs->ground);
	mlx_destroy_image(mlx->mlx, imgs->sled);
	mlx_destroy_image(mlx->mlx, imgs->santa);
	mlx_destroy_image(mlx->mlx, imgs->present);
	mlx_destroy_image(mlx->mlx, imgs->snowman);
	mlx_destroy_image(mlx->mlx, imgs->santa2);
	free(imgs);
	imgs = 0;
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	mlx = 0;
}

int	exit_game(t_game *game)
{
	free_imgs(game->mlx, game->imgs);
	free_mlx(game->mlx);
	free_map(game);
	free(game);
	exit(0);
}
