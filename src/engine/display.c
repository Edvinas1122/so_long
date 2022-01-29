/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:55:05 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/29 18:15:03 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	display_cases_s(t_game *game, char item, int x, int y)
{
	if (item == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.collectable[(game->frame > 0)], x, y);
		return (1);
	}
	return (0);
}

static int	display_cases(t_game *game, char item, int x, int y)
{
	if (item == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.player[(game->frame > 0)], x, y);
	else if (item == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.ground, x, y);
	else if (item == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.wall, x, y);
	else if (item == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.exit[game->gmech.door], x, y);
		return (1);
	}
	return (0);
}

static void	itterate_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	door;

	if (game->frame++ > SPEED)
		game->frame = -SPEED;
	i = 0;
	door = 0;
	game->gmech.finish = 0;
	while (game->map[i])
	{
		x = 60 * (i % (game->gmech.lenght));
		y = 60 * (i / (game->gmech.lenght));
		if (display_cases_s(game, game->map[i], x, y))
			door = 1;
		if (display_cases(game, game->map[i], x, y))
			game->gmech.finish = 1;
		i++;
	}
	if (!door)
		game->gmech.door = 1;
	if (!game->gmech.finish)
		error_terminate(4, game, NULL);
}

int	update_display(t_game *game)
{
	itterate_map(game);
	mlx_string_put(game->mlx, game->win, 60, 60, 0x00000000,
		ft_itoa(game->gmech.step_num));
	return (1);
}
