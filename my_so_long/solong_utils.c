#include "so_long.h"

int	count_lines(t_all *data)
{
	int		lines;

	lines = 0;
	while (data->map[lines])	
		lines++;
	data->lines = lines;
    return (lines);
}

int	count_len(t_all *data)
{
	int	len;

	len = ft_strlen(data->map[0]);
	data->len = len;
    return (len);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
