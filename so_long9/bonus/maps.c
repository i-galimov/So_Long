/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:49:35 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 14:40:36 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**get_map(char *s)
{
	int		fd;
	char	*lines;
	char	*line;
	int		i;

	i = 0;
	fd = open(s, O_RDONLY);
	line = "";
	lines = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines = ft_strjoin1(lines, line);
	}
	close(fd);
	return (ft_split(lines, '\n'));
}

void	printimg(t_var *he, char *s)
{
	he->img = mlx_xpm_file_to_image(he->mlx, s, &he->b, &he->d);
	mlx_put_image_to_window(he->mlx, he->win, he->img, he->x, he->y);
	mlx_destroy_image(he->mlx, he->img);
}

void	printe(t_var *he, char c)
{
	if (c == '1')
		printimg(he, "xpm/wall.xpm");
	if (c == '0')
		printimg(he, "xpm/An.xpm");
	if (c == 'P')
	{
		printimg(he, "xpm/isr.xpm");
		he->px = he->x;
		he->py = he->y;
	}
	if (c == 'C')
	{
		printimg(he, "xpm/Coll.xpm");
		he->len++;
	}
	if (c == 'E')
		printimg(he, "xpm/Exit.xpm");
	if (c == 'N')
		printimg(he, "xpm/trap.xpm");
}

void	printmap(t_var *he, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		he->x = 0;
		while (s[i][j])
		{
			printe(he, s[i][j]);
			he->x += 40;
			j++;
		}
		he->y += 40;
		i++;
	}
	he->x = 0;
	he->y = 0;
}

 /*int check_map(char **s,t_res xe)
{
	int i;

	i = 0;
	while (s[0][i])
	{
		if (s[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (s[xe.y][i])
	{
		if (s[xe.y][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (s[i][0])
	{
		if (s[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
		while (s[i][-1])
	{
		if (s[i][-1] != '1')
			return (0);
		i++;
	}
	return (1);
}*/
