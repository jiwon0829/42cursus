/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:11:26 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/11/11 04:51:14 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	check_rectangular(game);
	check_surrounded_walls(game);
	check_items(game);
	check_valid_path(game);
}

void	check_rectangular(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->height)
	{
		if (game->width != (int)ft_strlen(game->map[y]))
			print_error("Map must be rectangular\n");
		x = -1;
		while (++x < game->width)
			if (!ft_strchr("01EPCS", game->map[y][x]))
				print_error("Invalid characters entered\n");
	}
}

void	check_surrounded_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			print_error("Map must be closed/surrounded by walls\n");
		if (game->map[game->height - 1][i++] != '1')
			print_error("Map must be closed/surrounded by walls\n");
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			print_error("Map must be closed/surrounded by walls\n");
		if (game->map[i++][game->width - 1] != '1')
			print_error("Map must be closed/surrounded by walls\n");
	}
}

void	check_items(t_game *game)
{
	int	exit;
	int	collectible;
	int	start;

	exit = 0;
	collectible = 0;
	start = 0;
	find_items(game, &exit, &collectible, &start);
	if (exit != 1)
		print_error("Map must have one exit\n");
	if (start != 1)
		print_error("Map must have one starting position\n");
	if (collectible < 1)
		print_error("Map must have at one collectible\n");
}

void	find_items(t_game *game, int *exit, int *collectible, \
		int *start)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'E')
				++(*exit);
			else if (game->map[i][j] == 'P')
			{
				++(*start);
				game->santa_x = j;
				game->santa_y = i;
			}
			else if (game->map[i][j] == 'C')
			{
				++(*collectible);
				game->present_cnt += 1;
			}
		}
	}
}
