/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:13:15 by soutin            #+#    #+#             */
/*   Updated: 2024/05/17 16:05:01 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

// void	initial_pos(int *grid)
// {
// 	int	x = WIDTH / CELL_SIZE / 2;
// 	int	y = HEIGHT / CELL_SIZE / 2;
	
// 	grid[x * y] = 1;
	
// }

// void	print_cell(t_data *data, t_point point, bool live)
// {
// 	int color;
	
// }

// void	print_grid(t_data *data, int *grid)
// {
// 	t_point	current;
	
// 	current.y = 0;
// 	while (current.y < HEIGHT)
// 	{
// 		current.x = 0;
// 		while (current.x < WIDTH)
// 		{
			
// 		}
// 	}
// }

int main()
{
	t_data	data;
	
	bzero(&data, sizeof(t_data));
	init_mlx_data(&data);
	
	init_hook_and_loop(&data);
	return 0;
}