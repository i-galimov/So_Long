#include "so_long.h"

void check_argv(int argc, char **argv)
{
    int len_mapname;

	if (argc == 2)   
	{
		len_mapname = ft_strlen(argv[1]);
		if (argv[1][len_mapname - 4] == '.')
			if (argv[1][len_mapname - 3] == 'b')
				if (argv[1][len_mapname - 2] == 'e')
					if (argv[1][len_mapname - 1] == 'r')
						return ;
	}
	ft_error_arg();
}

void	check_elements(t_all *data)
{
	int		i;
	int		j;

	i = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	j = 0;

	while (data->map[i])
	{	
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c++;
			if (data->map[i][j] == 'E')
				data->e++;
			if (data->map[i][j]== 'P')
				data->p++;
			j++;
		}
		i++;
	}
	if (data->c * data->e * data->p == 0 || data->p != 1)
		ft_error_elements();
		
}		

void	check_updownwall(t_all *data)
{
	int	i;
	int	l;

	l = count_lines(data);
	i = 0;
	while (data->map[0][i] && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1')
			ft_error_wall();
		i++;
	}
	i = 0;
	while (data->map[l - 1][i] && data->map[l - 1][i] != '\n')
	{
		if (data->map[l - 1][i] != '1')
			ft_error_wall();
		i++;
	}
}

void	check_leftrightwall(t_all *data)
{
	int	i;

	i = 1;
	while (i < data->lines - 1)
	{
		if (data->map[i][0] != '1' && data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			ft_error_wall();
		i++;
	}
}
