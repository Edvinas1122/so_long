/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:52:00 by emomkus           #+#    #+#             */
/*   Updated: 2022/02/02 07:25:39 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	player_pos_find(char *map_str)
{
	char	*tmp;

	tmp = ft_strchr(map_str, 'P');
	if (tmp && ft_strchr(tmp + 1, 'P'))
	{
		free(map_str);
		exit(0);
	}
	return (tmp - map_str);
}

static void	load_assets(t_game *game, int width, int height)
{
	game->assets.wall = mlx_xpm_file_to_image(game->mlx,
			"./src/images/wall.xpm", &width, &height);
	game->assets.ground = mlx_xpm_file_to_image(game->mlx,
			"./src/images/ground.xpm", &width, &height);
	game->assets.collectable[0] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/collectable_1.xpm", &width, &height);
	game->assets.collectable[1] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/collectable_2.xpm", &width, &height);
	game->assets.player[0] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/player_01.xpm", &width, &height);
	game->assets.player[1] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/player_02.xpm", &width, &height);
	game->assets.exit[0] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/exit_1.xpm", &width, &height);
	game->assets.exit[1] = mlx_xpm_file_to_image(game->mlx,
			"./src/images/exit_2.xpm", &width, &height);
}

void	start(t_game *game, char **argv)
{
	game->map = map_to_heap(game, argv);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_terminate(7, NULL, NULL);
	game->win = mlx_new_window(game->mlx, (game->gmech.lenght - 1) * 60,
			60 * (ft_strlen(game->map) / (game->gmech.lenght - 1)), "So Long!");
	load_assets(game, 60, 60);
	game->gmech.door = 0;
	game->gmech.step_num = 0;
	game->gmech.player_pos = player_pos_find(game->map);
	game->frame = 0;
}
