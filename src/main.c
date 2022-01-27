/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:54:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/27 22:30:44 by emomkus          ###   ########.fr       */
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
	mlx_hook(game.win, 2, 1L<<1, actions, &game); /*X GUI close key error*/
	mlx_loop_hook(game.mlx, update_display, (void *)&game);
	mlx_loop(game.mlx);
}
