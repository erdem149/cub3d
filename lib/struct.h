/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:39:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/16 13:39:50 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H
# include <stdbool.h>

typedef struct s_cub3d_map
{
	void			*NO_texture_img;
	void			*SO_texture_img;
	void			*torch;
	void			*WE_texture_img;
	void			*EA_texture_img;

	char			**map;
	char			*map_name;
	char			*NO_texture_path;
	char			*SO_texture_path;
	char			*WE_texture_path;
	char			*EA_texture_path;
	int				map_line_c;
	unsigned long	F_rgb_code;
	unsigned long	C_rgb_code;
	int				map_lines_num;
	int				map_max_line;
	int				*NO_texture_addr;
	int				*WE_texture_addr;
	int				*EA_texture_addr;
	int				*SO_texture_addr;
} t_cub3d_map;

typedef struct s_cub3d_mini_map
{
	int				map_img_size_y;
	int				map_img_size_x;
	int				*ray_addr;
	void			*ray_img;
	int				screen_focus;

}	t_cub3d_mini_map;

typedef struct s_player
{
	bool			key_w;
	bool			key_s;
	bool			key_d;
	bool			key_a;
	bool			key_shift;
	bool			dir_right;
	bool			dir_left;
	bool			dir_up;
	bool			dir_down;
	int				*player_addr;
	double			move_speed;
	double			player_x;
	double			player_y;
	double			def_p_x;
	double			def_p_y;
	double			angle;
	void			*player_img;
}	t_player;

typedef struct  s_color_data
{
	int transparent;
	int red;
	int green;
	int blue;
	int tmp_x;
	int tmp_y;
	int flag;
} t_color_data;

typedef struct s_cub3d
{
	int					tmp_img_x;
	int					tmp_img_y;
	int					tmp_img_z;
	int					*game_img_adress;
	int					*mini_map_img_adress;
	void				*mlx;
	void				*mlx_window;
	void				*game_img;
	void				*mini_map_img;
	t_cub3d_mini_map	*mini_map;
	t_cub3d_map			*map;
	t_player			*player;
}	t_cub3d;

#endif