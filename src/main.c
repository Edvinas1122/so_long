/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:54:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/25 19:49:26 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_vars *vars)
{

	if (key == 53)
	{
		ft_printf("Quit game\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	ft_printf("KEY VALUE :%i\n", key);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*img;
	char	*heap_map;
	t_vars	vars;
	char	*relative_path = "./images/player_01.xpm";
	int		img_width = 40;
	int		img_height = 40;

	if (argc != 2)
	{
		write (1, "Type map name \n", 15);
		exit(0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	heap_map = map_open(argv);
	ft_printf("%s\n", heap_map);
	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<1, key_hook, &vars);
	mlx_loop(vars.mlx);
}
