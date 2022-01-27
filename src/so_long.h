/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:45:25 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/27 19:14:56 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h> 
# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"
# include "lib/GNL/get_next_line.h"

# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define KEY_ESC 53
# define SPEED 13

/* Visual assets */
typedef struct	s_assets {
	void	*wall;
	void	*ground;
	void	*collectable[2];
	void	*player[2];
	void	*exit[2];
}				t_assets;

/*Game mechanics data*/
typedef struct s_gmech
{
	int	lenght;
	int player_pos;
	int	door;
	int	step_num;
	int	finish;
}				t_gmech;

/* Runtime data */
typedef struct	s_game {
	void		*mlx;
	void		*win;
	char		*map;
	t_assets	assets;
	t_gmech		gmech;
}				t_game;

char	*map_to_heap(t_game *game, char **argv);
void	start(t_game *game, char **argv);
/* Keys*/
int 	actions(int key, t_game *game);
/* Display*/
int		update_display(t_game *game);

#endif