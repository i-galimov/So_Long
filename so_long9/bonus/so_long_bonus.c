/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:37:03 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 16:15:45 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_kf(int keycode, t_var *he)
{
	if (keycode == 2)
		right(he);
	if (keycode == 1)
		down(he);
	if (keycode == 13)
		up(he);
	if (keycode == 0)
		left(he);
	if (keycode == 53)
	{
		mlx_destroy_window(he->mlx, he->win);
		free(he->s);
		exit(0);
		return (0);
	}
	printcount(he);
	ft_print_m(he);
	return (0);
}

int	count_w(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int	red(int keycode, t_var *he)
{
	//mlx_destroy_window(he->mlx, he->win);
	exit(0);
	free(he->s);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	he;
	t_res	xe;

	he.s = get_map(av[1]);
	xe.x = ft_strlen(he.s[0]);
	xe.y = count_w(he.s);
	he.len = -1;
	he.h = xe.y * 40;
	he.w = xe.x * 40;
	he.mlx = mlx_init();
	he.win = mlx_new_window(he.mlx, xe.x * 40, xe.y * 40, "Window");
	printmap(&he, he.s);
	he.x = he.px;
	he.y = he.py;
	mlx_hook(he.win, 17, 0, red, &he);
	mlx_hook(he.win, 2, 0, my_kf, &he);
	mlx_loop(he.mlx);
}
