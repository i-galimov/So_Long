/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:48:25 by phella            #+#    #+#             */
/*   Updated: 2022/02/23 15:56:14 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (len);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
