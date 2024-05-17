/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:09 by soutin            #+#    #+#             */
/*   Updated: 2024/05/17 15:54:56 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int	init_mlx_data(t_data *data)
{
	data->pmlx = mlx_init();
	if (!data->pmlx)
		return (1);
	data->pwin = mlx_new_window(data->pmlx, 800,
			800, "Game of Life");
	if (!data->pwin)
		return (free(data->pwin), 1);
	return (0);
}

int	exit_and_free(t_data *data)
{
	if (data->pwin)
		mlx_destroy_window(data->pmlx, data->pwin);
	if (data->pmlx)
	{
		mlx_destroy_display(data->pmlx);
		free(data->pmlx);
	}
	exit(EXIT_SUCCESS);
}

int	get_inputs(int keysym, t_data *data)
{
	if (keysym == 65307)
		exit_and_free(data);
	return (0);
}

void	init_hook_and_loop(t_data *data)
{
	mlx_hook(data->pwin, KeyPress, KeyPressMask, get_inputs, data);
	mlx_hook(data->pwin, DestroyNotify, StructureNotifyMask,
		&exit_and_free, data);
	mlx_loop(data->pmlx);
}
