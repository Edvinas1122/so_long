/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:01:23 by emomkus           #+#    #+#             */
/*   Updated: 2022/02/02 07:28:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.collectable[0]);
	mlx_destroy_image(game->mlx, game->assets.collectable[1]);
	mlx_destroy_image(game->mlx, game->assets.exit[0]);
	mlx_destroy_image(game->mlx, game->assets.exit[1]);
	mlx_destroy_image(game->mlx, game->assets.ground);
	mlx_destroy_image(game->mlx, game->assets.wall);
	mlx_destroy_image(game->mlx, game->assets.player[0]);
	mlx_destroy_image(game->mlx, game->assets.player[1]);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}

void	error_terminate(int num, t_game *game, char *map)
{
	if (num == 1)
		write(1, "Permission error\n", 18);
	else if (num == 2)
		write(1, "No read\n", 8);
	else if (num == 6)
		write(1, "Wrong file format\n", 17);
	else if (num == 7)
		write(1, "No display driver\n", 18);
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

int	close_win(t_game *game)
{
	error_terminate(5, game, NULL);
	return (0);
}
