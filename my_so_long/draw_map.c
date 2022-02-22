#include "so_long.h"

void	*ft_choose_image(t_all *data, char ch)
{
	if (ch == '0')
		return (data->floor);
	if (ch == '1')
		return (data->wall);
	if (ch == 'C')
		return (data->brain);
	if (ch == 'E')
		return (data->exit);
	if (ch == 'V')
		return (data->enemy);
	if (ch == 'P')
		return (data->zombie);
	if (ch == '\n' || ch == '\0')
	 	return (data->wall);
	else
	{
		ft_error_elements();
		return (data->wall);
	}
}

void	ft_create_img(t_all *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->zombie = mlx_xpm_file_to_image(data->mlx, "./images/zombie.xpm", &i, &j);
	data->floor = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm", &i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &i, &j);
	data->brain = mlx_xpm_file_to_image(data->mlx, "images/brain.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &i, &j);
	data->enemy = mlx_xpm_file_to_image(data->mlx, "images/enemy.xpm", &i, &j);
}

void	 ft_draw_map(t_all *data)
{
	int		i;
	int		x;
	int		y;
	char	*str;
	void	*pic;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		str = data->map[i];
		if (str == NULL)
			break ;
		x = 0;
		while (str[x])
		{
			pic = ft_choose_image(data, str[x]);
			mlx_put_image_to_window(data->mlx, data->win, pic, x * 90, y * 90);
			x++;
		}
		y++;
		i++;
	}
}
