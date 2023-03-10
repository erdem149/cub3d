/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:36:38 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 12:52:31 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	ray_calculator_c(t_cub3d *main, double distance_v, double distance_h)
{
	if (distance_v < distance_h)
	{
		main->ray.distance = distance_v;
		main->ray.hit_v = true;
		main->ray.hit_h = false;
		main->ray.last_hit = main->ray.lh_y;
	}
	else
	{
		main->ray.distance = distance_h;
		main->ray.hit_v = false;
		main->ray.hit_h = true;
		main->ray.last_hit = main->ray.lh_x;
	}
}

int	is_wall_v2(t_cub3d *main, double x, double y)
{
	int	x_x;
	int	y_y;

	x_x = (int)floor(x);
	y_y = (int)floor(y);
	if (x < 0 || x > main->map->map_max_line
		|| y < 0 || y > main->map->map_lines_num)
		return (0);
	if (x_x < 0 || x_x > main->map->map_max_line
		|| y_y < 0 || y_y > main->map->map_lines_num)
		return (0);
	if (ft_strchr("L", main->map->map[y_y][x_x]))
	{
		main->ray.sp_x = x_x + 0.5;
		main->ray.sp_y = y_y + 0.5;
		main->ray.sp_distance = sqrt(
				powf(main->player->def_p_x - main->ray.sp_x, 2)
				+ powf(main->player->def_p_y - main->ray.sp_y, 2));
		main->ray.sp_ray = true;
	}
	return (ft_strchr("0NSEWAL", main->map->map[y_y][x_x]) == NULL);
}
