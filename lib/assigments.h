/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:39:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/13 13:51:32 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSIGMENTS_H
# define ASSIGMENTS_H
# include <stdbool.h>

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;

	bool	hit_v;
	bool	hit_h;

	int		dir_y;
	int		dir_x;
	char	lh_x;
	char	lh_y;
	char	last_hit;
	double	distance;
	int		door_x;
	int		door_y;
	int		ray_number;
} t_ray;

typedef struct s_cub3d_map
{
	void			*SO_texture_img;
	void			*door_img;
	void			*NO_texture_img;
	void			*hand;
	void			*hand_addr;
	void			*WE_texture_img;
	void			*EA_texture_img;
	char			**map;
	char			**val;
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
	int				*door_addr;
	int				*xpm_tmp;
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
	double			p_last_x;
	double			p_last_y;
	bool			key_w;
	bool			key_s;
	bool			key_d;
	bool			key_a;
	bool			key_e;
	bool			key_t;
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
	int	transparent;
	int	red;
	int	green;
	int	blue;
	int	tmp_x;
	int	tmp_y;
	int	flag;
} t_color_data;

typedef struct s_cub3d
{
	int					tmp_img_x;
	int					tmp_img_y;
	int					tmp_img_z;
	int					*game_img_adress;
	int					*mini_map_img_adress;
	int					WH;
	void				*mlx;
	void				*mlx_window;
	void				*game_img;
	void				*mini_map_img;
	t_cub3d_mini_map	*mini_map;
	t_cub3d_map			*map;
	t_player			*player;
	t_ray				ray;
} t_cub3d;

#endif
