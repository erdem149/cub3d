/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:04:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 17:59:24 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

t_color_data	color_assignment(int transparent, int red, int green, int blue)
{
	t_color_data	color;

	color.transparent = transparent;
	color.red = red;
	color.green = green;
	color.blue = blue;
	color.tmp_x = 0;
	color.tmp_y = 0;
	color.flag = 0;
	return (color);
}

unsigned long	rgb_to_hex(t_color_data color)
{
	return ((color.transparent << 24)
		+ (color.red << 16) + (color.green << 8) + (color.blue));
}

double	angle_to_radyan(double ang)
{
	while (ang <= 0.0)
		ang += 360;
	while (ang > 360.0)
		ang -= 360;
	return (ang * (M_PI / 180.0));
}

void	img_colors(t_cub3d *main, int *img, int height, int width)
{
	int	i;
	int	k;

	k = 0;
	while (k != height)
	{
		i = -1;
		while (++i != width)
		{
			if (main->color.flag == 1)
				img[(int)main->mw * (main->color.tmp_y + k)
					+ (main->color.tmp_x + i)] = rgb_to_hex(main->color);
			else
				img[(int)width * k + i] = rgb_to_hex(main->color);
		}
		k++;
	}
}

void	textured_wall(t_cub3d *main, int img_loc, int location, int i)
{
	int	color;
	int	*xpm;

	xpm = main->map->xpm_tmp;
	if (img_loc - 64 * (int)((double)i \
	* ((double)64 / (double)(main->wh * 2))) >= 0)
	{
		color = xpm[img_loc - 64 * (int)((double)i \
		* ((double)64 / (double)(main->wh * 2)))];
		if ((location - (SCREEN_WIDTH * i)) >= 0 && color >= 0)
			main->game_img_adress[(location - (SCREEN_WIDTH * i))] = color;
	}
	if (img_loc + 64 * (int)((double)i \
	* ((double)64 / (double)(main->wh * 2))) < 64 * 64)
	{
		color = xpm[img_loc + 64 * (int)((double)i \
		* ((double)64 / (double)(main->wh * 2)))];
		if ((SCREEN_HEIGHT * SCREEN_WIDTH) >= \
			(location + (SCREEN_WIDTH * i)) && color >= 0)
			main->game_img_adress[(location + (SCREEN_WIDTH * i))] = color;
	}
}
