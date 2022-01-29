/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_heap_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:55:03 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/29 18:15:52 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int where)
{
	if (!(game->map[game->gmech.player_pos + where] == '1'
			|| (game->map[game->gmech.player_pos + where] == 'E'
				&& !game->gmech.door)))
	{
		game->map[game->gmech.player_pos + where] = 'P';
		game->map[game->gmech.player_pos] = '0';
		game->gmech.player_pos = game->gmech.player_pos + where;
		game->gmech.step_num++;
	}
}

int	actions(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		write(1, "Quit game\n", 10);
		free(game->map);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit(0);
	}
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, -game->gmech.lenght);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->gmech.lenght);
	return (0);
}
