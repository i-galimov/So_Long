#include "so_long.h"

void	check_qlines(t_all *data)
{
	int		i;

	i = 0;
	if (data->lines < 3)
		ft_error_qlines();
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != data->len)
			ft_error_qlines();
		i++;
	}
}

char	**ft_save_map(char *argv, t_all *data)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	data->map = (char **) malloc(100);
	if (!data->map)
		exit(0);
	fd = open(argv, O_RDONLY);
	i = 0;
	str = gnl(fd);
	while (str)
	{
		data->map[i] = str;
		str = gnl(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	return (data->map);
}

int	main(int argc, char **argv)
{
	t_all		data;
	int			len;
	int			lines;

	data.map = ft_save_map(argv[1], &data);
	lines = count_lines(&data);
	len	= count_len(&data);

	check_qlines(&data);
	check_argv(argc, argv);
	check_elements(&data);
	check_updownwall(&data);
	check_leftrightwall(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (len - 1) * 90, lines * 90, "So_long");
	ft_create_img(&data);
	ft_draw_map(&data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 0L, &ft_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}
