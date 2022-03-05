/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:34:36 by phella            #+#    #+#             */
/*   Updated: 2022/02/23 15:34:39 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_c(t_all *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_move_key(int *x, int *y, int key)
{
	if (key == 0)
		*x -= 1;
	if (key == 1)
		*y += 1;
	if (key == 2)
		*x += 1;
	if (key == 13)
		*y -= 1;
}

void	ft_find_player(t_all *data, int *x, int *y)
{
	*y = 0;
	while (data->map[*y])
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

int	ft_move(t_all *data, int key)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	ft_find_player(data, &x, &y);
	player_y = y;
	player_x = x;
	ft_move_key(&x, &y, key);
	if (data->map[y][x] == 'E' && ft_check_c(data) == 0)
		exit (0);
	if (data->map[y][x] == 'V')
		exit(0);
	if (data->map[y][x] == '1' || data->map[y][x] == 'E')
		return (0);
	else
	{
		data->map[y][x] = 'P';
		data->map[player_y][player_x] = '0';
	}
	return (1);
}

int	ft_key_hook(int key, t_all *data)
{
	static int	step = 0;

	if (key == 53)
		exit(0);
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		step += ft_move(data, key);
		write(1, "Step:", 5);
		ft_count_step(step, 1);
		write(1, "\n", 1);
		ft_draw_map(data);
	}
	return (0);
}
