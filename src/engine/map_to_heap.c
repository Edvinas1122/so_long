/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:07:48 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/28 00:07:35 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_valid_char(char c, int f)
{
	static char a[3];
	
	if (f == 1)
		if (!(a[0] == 1 && a[1] > 0 && a[2] == 1))
			return (0);
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'P')
	{
		a[0]++;
		return (1);
	}
	else if (c == 'C')
	{
		a[1]++;
		return (1);
	}
	else if (c == 'E')
	{
		a[2]++;
		return (1);
	}
	else
		return(0);
}

static int	check_valid_map(char *map, int len, int row, int i, int tmp)
{
	while (map[i] != '\n')
	{
		if (map[i] == '\0' || map[i++] != '1')
			return(0);
	}
	while (row > 1)
	{
		tmp = len - 2;
		if (map[++i] != '1')
			return (0);
		while (tmp--)
		{
			if (!check_valid_char(map[++i], 0))
				return (0);
		}
		if (map[i++] != '1')
			return (0);
		row--;
	}
	while (--len != 0)
	{
		if (map[++i] != '1')
			return(0);
	}
	return (1);
}

char	*map_to_heap(t_game *game, char **argv)
{
	int		fd;
	char	*map_str;
	char	*tmp;
	int		rows;

	rows = 0;
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(0);
	if (!(map_str = get_next_line(fd)))
	{
		write(1, "Empty map", 9);
		exit(0);
	}
	game->gmech.lenght = ft_strlen(map_str);
	while ((tmp = get_next_line(fd)))
	{
		rows++;
		map_str = ft_strjoin_free(map_str, tmp);
	}
	if (!check_valid_map(map_str, game->gmech.lenght, rows, 0, 0) &&
			!heck_valid_char("0", 1))
	{
		write(1, "Invalid map", 11);
		free(map_str);
		exit(0);
	}
	return (map_str);
}
