/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:21:14 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/11 03:30:01 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *filename, int *fd)
{
	if (!check_filename(filename))
		print_error("Invalid file extension\n");
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		print_error("Failed to open map\n");
}

int	check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (filename[--len] != 'r')
		return (FALSE);
	if (filename[--len] != 'e')
		return (FALSE);
	if (filename[--len] != 'b')
		return (FALSE);
	if (filename[--len] != '.')
		return (FALSE);
	return (TRUE);
}

void	setting_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*backup;
	char	*map;

	check_file(filename, &fd);
	line = get_next_line(fd);
	if (!line)
		print_error("Map is empty\n");
	game->width = ft_strlen(line) - 1;
	map = ft_strdup(line);
	while (line)
	{
		game->height += 1;
		backup = map;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin(backup, line);
	}
	free(line);
	game->map = ft_split(map, '\n');
	free(map);
}
