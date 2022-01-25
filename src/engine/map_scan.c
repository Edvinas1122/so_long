/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:07:48 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/25 19:47:49 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_valid_char(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\0')
		return (1);
	else
		return(0);
}

static int	check_valid_map_line(char *tmp, int len, int border)
{
	int i;

	i = 0;
	if (len != (int)ft_strlen(tmp))
	{
		if (tmp[ft_strlen(tmp)] != 0)
			return (0);
	}
	if (border)
	{
		while (tmp[i])
		{
			if (tmp[i] != '1')
				return (0);
			i++;
		}
	}
	else
	{
		if (tmp[i++] != '1')
			return (0);
		while (tmp[i])
		{
			if (!check_valid_char(tmp[i]))
				return (0);
			if (tmp[i] == '\n' && tmp[i - 1] != '1')
				return(0);
			i++;
		}
	}
	return (1);
}

char	*map_open(char **argv)
{
	int		fd;
	char	*map_str;
	char	*tmp;
	int		lenght;

	fd = open(argv[1], O_RDONLY);
	map_str = get_next_line(fd);
	lenght = ft_strlen(map_str);
	check_valid_map_line(map_str, lenght, 1);
	while ((tmp = get_next_line(fd)))
	{
		if (!check_valid_map_line(tmp, lenght, 0))
		{
			free(map_str);
			free(tmp);
			exit(0);
		}
		map_str = ft_strjoin_free(map_str, tmp);
	}
	return (map_str);
}
