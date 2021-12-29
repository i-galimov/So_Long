/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:35:26 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/15 16:39:57 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_1string(char **s)
{
	int	i;

	i = 0;
	while (s[0][i])
	{
		if (s[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_laststring(char **s, int a)
{
	int	i;

	i = 0;
	a--;
	while (s[a][i])
	{
		if (s[a][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_first(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_last(char **s, int x)
{
	int	i;

	x--;
	i = 0;
	while (s[i])
	{
		if (s[i][x] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **s, t_res *xe)
{
	if (check_1string(s) && check_laststring(s, xe->y) && \
		check_first(s) && check_last(s, xe->x))
		return (1);
	else
		return (0);
}
