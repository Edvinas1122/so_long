/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:54:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/02/01 03:09:15 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file_format(char *name)
{
	if (ft_strlen(name) < 4)
		error_terminate(6, NULL, NULL);
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".ber", 4))
		error_terminate(6, NULL, NULL);
}

#ifdef OS

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
	check_file_format(argv[1]);
	start(&game, argv);
	mlx_hook(game.win, 17, 0L, close_win, &game);
	mlx_key_hook(game.win, actions, &game);
	mlx_loop_hook(game.mlx, update_display, (void *)&game);
	mlx_loop(game.mlx);
}
#endif
