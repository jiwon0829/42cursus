/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:27:33 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/11 04:57:49 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_visited(t_path *path, t_game *game)
{
	int	y;
	int	x;

	path->visited = (int **)malloc(sizeof(int *) * (game->height + 1));
	y = -1;
	while (++y < game->height)
	{
		path->visited[y] = (int *)malloc(sizeof(int) * (game->width + 1));
		if (!path->visited[y])
			free_visited(path->visited);
		x = -1;
		while (++x < game->width)
			path->visited[y][x] = FALSE;
	}
	path->visited[y] = FALSE;
	path->cnt = game->present_cnt;
}

void	dfs(t_game *game, t_path *path, int y, int x)
{
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};
	int			nx;
	int			ny;
	int			i;

	path->visited[y][x] = TRUE;
	if (game->map[y][x] == 'C')
		--(path->cnt);
	if (game->map[y][x] == 'E')
	{
		path->is_valid = TRUE;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		nx = dx[i] + x;
		ny = dy[i] + y;
		if (nx < 0 || nx > game->width || ny < 0 || ny > game->height)
			continue ;
		if (!path->visited[ny][nx] && game->map[ny][nx] != '1')
			dfs(game, path, ny, nx);
	}
}

void	check_valid_path(t_game *game)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	init_visited(path, game);
	dfs(game, path, game->santa_y, game->santa_x);
	if (!path->is_valid || path->cnt > 0)
		print_error("There is no valid path\n");
	free_visited(path->visited);
	free(path);
	path = 0;
}

void	free_visited(int **visited)
{
	int	i;

	i = -1;
	while (visited[++i])
	{
		free(visited[i]);
		visited[i] = 0;
	}
	free(visited);
	visited = 0;
}
