/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:18:09 by uercan            #+#    #+#             */
/*   Updated: 2023/01/12 23:31:44 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdbool.h>
# include <math.h>

#ifndef CUB3D_H
# define CUB3D_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
/*------------ERROR-CODE----------------*/
# define PROGRAM_ARG_ERROR		101	//22	EINVAL	Invalid argument
# define FILE_NOT_FOUND_ERROR	102	//2		ENOENT	No such file or directory
# define WRONG_FILE_EXTENSION	103	//59	EBFONT	Bad font file format
# define INVALID_MAP			104
# define INVALID_CHARACTER		105
# define INVALID_COUNTS			106
# define MALLOC_ERROR			107
# define MLX_ERROR_INIT			108
# define MLX_ERROR_WINDOW		109
# define MLX_ERROR_IMG			110
# define SUCCESSFUL				0

/*------------MAP-SIZE--------------*/
# define SCREEN_WIDTH			1920 / 1
# define SCREEN_HEIGHT			1080 / 1
# define MINI_MAP_WIDTH_RATION	3
# define MINI_MAP_HEIGHT_RATION	3
# define MINI_MAP_WIDTH			SCREEN_WIDTH / MINI_MAP_WIDTH_RATION
# define MINI_MAP_HEIGHT		SCREEN_HEIGHT / MINI_MAP_HEIGHT_RATION

/*----------KEY-CODES------------*/
# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_LEFT				123
# define KEY_DOWN				125
# define KEY_RIGHT				124
# define KEY_UP					126
# define KEY_SHIFT				257

/*----------------MOVE-------------*/
# define MOVE_PIXEL 1
# define MOVE_PIXEL_FAST 10
# define ROT_ANGLE 5
# define ROT_ANGLE_USER 60

# define MINI_WALL 0xf0ff0f
# define MINI_FLOOR 0xba8576

typedef struct s_cub3d_map
{
	void			*NO_texture_img;
	int				*NO_texture_addr;
	
	void			*SO_texture_img;
	int				*SO_texture_addr;

	void			*WE_texture_img;
	int				*WE_texture_addr;

	void			*EA_texture_img;
	int				*EA_texture_addr;
	
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
} t_cub3d_map;

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
	double			angle;
	void			*player_img;
}	t_player;

typedef struct s_cub3d_mini_map
{
	int				map_img_size_y;
	int				map_img_size_x;
	int				*ray_addr;
	void			*ray_img;
	int				screen_focus;

}	t_cub3d_mini_map;

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

// //*********{V.I.P}*********//
// /***/void check_leaks();/***/
// //*********{V.I.P}*********//

void			put_to_3d(t_cub3d *main, double dis, int ray, int loc, double angle);
void			put_backscreen(t_cub3d *main);

void			exit_free(t_cub3d *main, int err_no);
void			map_check(t_cub3d *main);
void			map_full_check(int index, char **str, t_cub3d *main);
void			map_down_control(t_cub3d *main);
void			check_invallid_chracters(char s, t_cub3d *main, int status);
void			name_check(char *str, t_cub3d *main);
void			free_double_Str(char **s);
void			get_RGB(t_cub3d *main, int i, int k);
void			get_prime_map(t_cub3d *main, int i);
void			main_game_img_paint(t_cub3d *main);
void			game_mini_map_paint(t_cub3d *main);
void			game_window(t_cub3d *main);
void			game_put_player(t_cub3d *main);
void			set_direction(t_cub3d *main, char s, int c, int b);
void			draw_ray(t_cub3d *main, int i,int k);

char			**ft_double_strcpy(char **s, int i);
char			**ft_split_isspace(const char *s);
char			*ft_strjoin_2(char *save, char *buffer);
char			*get_texture_path(t_cub3d *main, int i, int k);

unsigned long	rgb_to_hex(int transparent, int r, int g, int b);
double			angle_to_radyan(double ang);

int				is_wall(t_cub3d *main, double x, double y);
int				move_loop(t_cub3d *main);
int				ft_key_press(int key_code, t_cub3d *main);
int				ft_key_release(int key_code, t_cub3d *main);
int				get_SO_path(t_cub3d *main, int i, int k);
int				get_EA_path(t_cub3d *main, int i, int k);
int				get_WE_path(t_cub3d *main, int i, int k);
int				get_C_RGB(t_cub3d *main, int i, int k);
int				get_F_RGB(t_cub3d *main, int i, int k);
int				get_map_parts(t_cub3d *main);
int				check_isspace(char s);

#endif
