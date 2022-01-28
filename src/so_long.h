/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:45:25 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/28 21:58:00 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h> 
# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"
# include "lib/GNL/get_next_line.h"

# define KEY_LEFT 0xff51
# define KEY_UP 0xff52
# define KEY_RIGHT 0xff53
# define KEY_DOWN 0xff54

# ifndef KEY_A
#  define KEY_A 0x0061
# endif

# ifndef KEY_W
#  define KEY_W 0x0077
# endif

# ifndef KEY_D
#  define KEY_D 0x0064
# endif

#ifndef KEY_S
# define KEY_S 0x0073
#endif

#ifndef KEY_ESC
# define KEY_ESC 0xff1b
#endif

#ifndef SPEED
# define SPEED 68
#endif

/* Visual assets */
typedef struct s_assets
{
	void	*wall;
	void	*ground;
	void	*collectable[2];
	void	*player[2];
	void	*exit[2];
}	t_assets;

/*Game mechanics data*/
typedef struct s_gmech
{
	int	lenght;
	int	player_pos;
	int	door;
	int	step_num;
	int	finish;
}	t_gmech;

/* Runtime data */
typedef struct s_game {
	void		*mlx;
	void		*win;
	char		*map;
	int			frame;
	t_assets	assets;
	t_gmech		gmech;
}	t_game;

char	*map_to_heap(t_game *game, char **argv);
void	start(t_game *game, char **argv);
void	error_terminate(int num, t_game *game, char *map);
void	free_mlx(t_game *game);
/* Keys*/
int		actions(int key, t_game *game);
/* Display*/
int		update_display(t_game *game);

#endif