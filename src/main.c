/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:54:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/31 12:10:25 by emomkus          ###   ########.fr       */
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

void	error_terminate(int num, t_game *game, char *map)
{
	if (num == 1)
		write(1, "Permission error\n", 18);
	else if (num == 2)
		write(1, "No read\n", 8);
	else if (num == 3)
	{
		write(1, "Invalid map\n", 12);
		free(map);
	}
	else if (num == 4)
	{
		free_mlx(game);
		write(1, "So long !\n", 10);
	}
	else if (num == 5)
	{
		free_mlx(game);
		write(1, "Quit game\n", 10);
	}
	exit(0);
}

static int	close_win(t_game *game)
{
	error_terminate(5, game, NULL);
	return (0);
}

#ifdef OS

int	main(int argc, char **argv)
{
	t_game	game;

	ft_printf("test2");
	if (argc != 2)
	{
		write (1, "No map name or too many arguments\n", 34);
		exit(0);
	}
	check_file_format(argv[1]);
	start(&game, argv);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_hook(game.win, 2, 1L << 2, actions, &game);
	mlx_loop_hook(game.mlx, update_display, (void *)&game);
	mlx_loop(game.mlx);
}
#else

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write (1, "No map name or too many arguments\n", 34);
		exit(0);
	}
	ft_printf("test");
	check_file_format(argv[1]);
	start(&game, argv);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_key_hook(game.win, actions, &game);
	mlx_loop_hook(game.mlx, update_display, (void *)&game);
	mlx_loop(game.mlx);
}
#endif
