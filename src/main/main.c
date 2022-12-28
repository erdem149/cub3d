/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:58:03 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 16:52:04 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	ft_close(void)// şimdilik kapatmak için
{
	exit (0);
	return (0);
}

void loop_window_and_game(t_cub3d *main)
{
	main_game_img_paint(main);
	game_mini_map_paint(main);
	//mlx_hook(main->mlx_window, 2, 2L << 1, move, main);
	mlx_hook(main->mlx_window, 2, 1L<<0, &ft_key_press, main);
	mlx_hook(main->mlx_window, 3, 1L<<1, &ft_key_release, main);
	mlx_hook(main->mlx_window, 17, (0L), ft_close, main);
	mlx_loop_hook(main->mlx, move_loop, main);//for loop test
	mlx_loop(main->mlx);
}


int main(int argc, char **argv)
{
	t_cub3d *main;

	main = (t_cub3d *)malloc(sizeof(t_cub3d));
	if(!main)
		exit_free(main, MALLOC_ERROR);
	main->map = (t_cub3d_map *)malloc(sizeof(t_cub3d_map));
	if(!main->map)
		exit_free(main, MALLOC_ERROR);
	map_full_check(argc, argv, main); // leak var get_prime_map fonksiyonu
	game_window(main);
	loop_window_and_game(main);
	return (EXIT_SUCCESS);
}
