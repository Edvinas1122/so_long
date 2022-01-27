/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_heap_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:55:03 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/27 18:49:55 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int where)
{
	if (!(game->map[game->gmech.player_pos + where] == '1' ||
		(game->map[game->gmech.player_pos + where] == 'E' && !game->gmech.door)))
	{
		game->map[game->gmech.player_pos + where] = 'P';
		game->map[game->gmech.player_pos] = '0';
		game->gmech.player_pos = game->gmech.player_pos + where;
	}
}


int actions(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		ft_printf("Quit game\n");
		/*FREE FUNCTION*/
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (key == KEY_W)
		move_player(game, -game->gmech.lenght);
	else if (key == KEY_A)
		move_player(game, -1);
	else if (key == KEY_D)
		move_player(game, 1);
	else if (key == KEY_S)
		move_player(game, game->gmech.lenght);
	game->gmech.step_num++;
	return (0);
}