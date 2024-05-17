/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:13:15 by soutin            #+#    #+#             */
/*   Updated: 2024/05/17 17:29:21 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

// void	initial_pos(int *grid)
// {
// 	int	x = WIDTH / CELL_SIZE / 2;
// 	int	y = HEIGHT / CELL_SIZE / 2;
	
// 	grid[x * y] = 1;
	
// }

void	print_cell(t_data *data, t_point point, bool live)
{
	int color;
	
	if (live)
		color = 0xF8F8FF;
	else
		color = 0x000000;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			mlx_pixel_put(data->pmlx, data->pwin, point.x * CELL_SIZE + j, point.y * CELL_SIZE + i, color);
		}
	}
}

void	print_grid(t_data *data)
{
	t_point	current;
	
	current.y = 0;
	while (current.y < HEIGHT / CELL_SIZE)
	{
		current.x = 0;
		while (current.x < WIDTH / CELL_SIZE)
		{
			print_cell(data, current, data->grid[current.y][current.x++]);
				
		}
		current.y++;
	}
}

void place_pattern_at_center_from_file(t_data *data, const char *filename)
{
	int 	centerX = WIDTH / CELL_SIZE / 2;
    int 	centerY = HEIGHT / CELL_SIZE / 2;
	size_t	len;
	t_point	pos;
    char 	*line = NULL;
	char	tmp[100][100];
	
	FILE *file = fopen(filename, "r");
    if (!file)
	{
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int row = 0;
    while (getline(&line, &len, file)!= -1)
	{
        for (int col = 0; col < len; ++col)
            tmp[row][col] = line[col] == '1'? 1 : 0; // Assuming '1' represents alive
        row++;
    }
    free(line); // Free the memory allocated by getline
    fclose(file);
    for (int i = 0; i < row; i++)
	{
        for (int j = 0; j < len; j++)
		{
            if (tmp[i][j] == 1)
			{
                pos.x = centerX + j;
                pos.y = centerY + i;
                // Ensure the pattern does not exceed the grid boundaries
                if (pos.x >= 0 && pos.x < WIDTH / CELL_SIZE && pos.y >= 0 && pos.y < HEIGHT / CELL_SIZE)
                    data->grid[pos.y][pos.x] = 1; // Place the pattern cell
            }
        }
    }
}

int main()
{
	t_data	data;
	
	bzero(&data, sizeof(t_data));
	init_mlx_data(&data);
	data.grid = (bool **)calloc((HEIGHT / CELL_SIZE), sizeof(bool *));
	if (!data.grid)
		return (1);
	for (int i = 0; i < (WIDTH / CELL_SIZE); i++)
	{
		data.grid[i] = calloc((WIDTH / CELL_SIZE), sizeof(bool));
		if (!data.grid[i])
			return (1);
	}
	place_pattern_at_center_from_file(&data, "map");
	print_grid(&data);
	init_hook_and_loop(&data);
	return 0;
}