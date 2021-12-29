/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:40:13 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/15 16:40:43 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	checklen(char **s)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(s[0]);
	while (s[i])
	{
		while (s[i][j])
		{
			j++;
		}
		if (j == len)
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
