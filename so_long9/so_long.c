/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:37:03 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/15 16:43:51 by eassamer         ###   ########.fr       */
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
		freeblocks(he);
		exit(0);
		return (0);
	}
	printcount(he);
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

void	freeblocks(t_var *he)
{
	int	i;

	i = 0;
	while (he->s[i])
	{
		free(he->s[i]);
		i++;
	}
	free(he->s);
}

int	redcross(int keycode, t_var *he)
{
	(void)keycode;
	freeblocks(he);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	he;
	t_res	xe;

	(void)ac;
	he.s = get_map(av[1]);
	xe.x = ft_strlen(he.s[0]);
	xe.y = count_w(he.s);
	if (!check_map(he.s, &xe) || !checklen(he.s))
	{
		printf("ERROR MAP");
		return (freeblocks(&he), 0);
	}
	he.len = -1;
	he.h = xe.y * 40;
	he.w = xe.x * 40;
	he.mlx = mlx_init();
	he.win = mlx_new_window(he.mlx, xe.x * 40, xe.y * 40, "Window");
	printmap(&he, he.s);
	he.x = he.px;
	he.y = he.py;
	mlx_hook(he.win, 17, 0, redcross, &he);
	mlx_hook(he.win, 2, 0, my_kf, &he);
	mlx_loop(he.mlx);
}
