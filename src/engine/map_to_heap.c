/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:07:48 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/30 03:35:08 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_valid_char(char c, int f)
{
	static int	a[3];

	if (f == 1)
	{
		if (a[0] == 1 && a[1] > 0 && a[2] == 1)
			return (1);
		else
			ft_printf("Player: %i\nCollectables: %i\nExits: %i\n",
				a[0], a[1], a[2]);
	}
	else if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == 'P')
			a[0]++;
		if (c == 'C')
			a[1]++;
		if (c == 'E')
			a[2]++;
		return (1);
	}
	return (0);
}

static int	check_valid_top_n_bottom(char *map, int len, int is_top, int row)
{
	int	i;

	i = row * len;
	while (len-- - 1 != 0)
	{
		if (map[i++] != '1')
			return (0);
	}
	if (is_top && map[i] == '\n')
		return (1);
	if (!is_top && map[i] == 0)
		return (1);
	return (0);
}

static int	check_valid_mid(char *map, int len, int row)
{
	int	i;

	i = (row - 1) * len;
	if (map[i] != '1')
		return (0);
	while (len-- - 3)
	{
		if (!check_valid_char(map[++i], 0))
			return (0);
	}
	if (map[++i] != '1')
		return (0);
	if (map[++i] != '\n')
		return (0);
	return (1);
}

void	check_valid(char *map_str, int len, int rows)
{
	int	kill;

	kill = 0;
	if (!check_valid_top_n_bottom(map_str, len, 1, 0))
		kill = 1;
	if (!check_valid_top_n_bottom(map_str, len, 0, rows) || kill)
		kill = 1;
	while (rows - 1 && !kill)
	{
		if (!check_valid_mid(map_str, len, rows))
			kill = 1;
		rows--;
	}
	if (!check_valid_char('\0', 1) && !kill)
		kill = 1;
	if (kill)
		error_terminate(3, NULL, map_str);
}

char	*map_to_heap(t_game *game, char **argv)
{
	int		fd;
	char	*map_str;
	char	*tmp;
	int		rows;

	rows = 0;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		error_terminate(1, NULL, NULL);
	map_str = get_next_line(fd);
	if (!map_str)
		error_terminate(2, NULL, NULL);
	game->gmech.lenght = ft_strlen(map_str);
	tmp = get_next_line(fd);
	while (tmp)
	{
		rows++;
		map_str = ft_strjoin_free(map_str, tmp);
		tmp = get_next_line(fd);
	}
	check_valid(map_str, game->gmech.lenght, rows);
	close(fd);
	return (map_str);
}
