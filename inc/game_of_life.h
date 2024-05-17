/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:16 by soutin            #+#    #+#             */
/*   Updated: 2024/05/17 16:02:39 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE
# define GAME_OF_LIFE

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <stdbool.h>

# define WIDTH 800
# define HEIGHT 800
# define CELL_SIZE 8

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_data
{
	void	*pmlx;
	void	*pwin;
}			t_data;

int			init_img(t_data *data, t_img *img, int width, int height);
void		destroy_image(void *img, t_data *data);
void		put_pixel_to_image(t_img *img, int x, int y, int color);
int			init_mlx_data(t_data *data);
void		init_hook_and_loop(t_data *data);

#endif