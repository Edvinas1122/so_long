/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:54:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/28 17:32:16 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file_format(char *name)
{
	if (ft_strlen(name) < 4)
	{
		write(1, "Wrong file format", 17);
		exit(0);
	}
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".ber", 4))
	{
		write(1, "Wrong file format", 17);
		exit(0);
	}
}

void	error_terminate(int num, char *map)
{
	if (num == 1)
		write(1, "Permission error", 17);
	else if (num == 2)
		write(1, "Empty map", 9);
	else if (num == 3)
	{
		write(1, "Invalid map", 11);
		free(map);
	}
	else if (num == 4)
	{
		write(1, "So long !", 9);
		free(map);
	}
	exit(0);
	
}

static int	close_win(t_game *game)
{
	free(game->map);
	write(1, "Quit game", 9);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write (1, "No map name or too many arguments\n", 34);
		exit(0);
	}
	check_file_format(argv[1]);
	start(&game, argv);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_hook(game.win, 2, 1L << 1, actions, &game);
	mlx_loop_hook(game.mlx, update_display, (void *)&game);
	mlx_loop(game.mlx);
}
