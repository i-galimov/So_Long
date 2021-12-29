/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:56:16 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 14:21:25 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	left(t_var *he)
{
	if (he->s[he->y / 40][he->x / 40 - 1] != '1' && \
		(he->s[he->y / 40][he->x / 40 - 1] != 'E' || he->len < 0))
	{
		printimg(he, "xpm/An.xpm");
		he->x = he->x - 40;
		printimg(he, "xpm/isr.xpm");
		if (he->s[he->y / 40][he->x / 40] == 'C')
		{
			he->s[he->y / 40][he->x / 40] = '0';
			he->len--;
		}
		else if (he->s[he->y / 40][he->x / 40] == 'E')
			exit(0);
	}	
}

void	right(t_var *he)
{
	if (he->s[he->y / 40][he->x / 40 + 1] != '1' && \
		(he->s[he->y / 40][he->x / 40 + 1] != 'E' || he->len < 0))
	{
		printimg(he, "xpm/An.xpm");
		he->x = he->x + 40;
		printimg(he, "xpm/imn.xpm");
		if (he->s[he->y / 40][he->x / 40] == 'C')
		{
			he->s[he->y / 40][he->x / 40] = '0';
			he->len--;
		}
		else if (he->s[he->y / 40][he->x / 40] == 'E')
			exit(0);
	}
}

void	down(t_var *he)
{
	if (he->s[he->y / 40 + 1][he->x / 40] != '1' && \
		(he->s[he->y / 40 + 1][he->x / 40] != 'E' || he->len < 0))
	{
		printimg(he, "xpm/An.xpm");
		he->y = he->y + 40;
		printimg(he, "xpm/ltht.xpm");
		if (he->s[he->y / 40][he->x / 40] == 'C')
		{
			he->s[he->y / 40][he->x / 40] = '0';
			he->len--;
		}
		else if (he->s[he->y / 40][he->x / 40] == 'E')
			exit(0);
	}
}

void	up(t_var *he)
{
	if (he->s[he->y / 40 - 1][he->x / 40] != '1' && \
		(he->s[he->y / 40 - 1][he->x / 40] != 'E' || he->len < 0))
	{
		printimg(he, "xpm/An.xpm");
		he->y = he->y - 40;
		printimg(he, "xpm/fou9.xpm");
		if (he->s[he->y / 40][he->x / 40] == 'C')
		{
			he->s[he->y / 40][he->x / 40] = '0';
			he->len--;
		}
		else if (he->s[he->y / 40][he->x / 40] == 'E')
			exit(0);
	}
}
