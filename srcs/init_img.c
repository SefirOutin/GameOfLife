/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:07:52 by soutin            #+#    #+#             */
/*   Updated: 2024/05/13 13:54:19 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int	init_img(t_data *data, t_img *img, int width, int height)
{
	img->img = mlx_new_image(data->pmlx, width, height);
	if (!img->img)
		return (-1);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_l,
			&img->endian);
	img->h = height;
	img->w = width;
	return (0);
}
