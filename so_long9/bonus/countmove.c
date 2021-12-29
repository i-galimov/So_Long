/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:41:14 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 11:46:45 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	printcount(t_var *he)
{
	static int	i;

	printf("count : %d \n", i);
	i++;
}

static size_t	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_len(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}

void	ft_print_m(t_var *he)
{
	char		*str;
	static int	i;

	he->img = mlx_xpm_file_to_image(he, "xpm/Wall.xpm", &he->b, &he->d);
	mlx_put_image_to_window(he->mlx, he->win, he->img, 0, 0);
	mlx_destroy_image(he->mlx, he->img);
	he->img = mlx_xpm_file_to_image(he->mlx, "xpm/Wall.xpm", &he->b, &he->d);
	mlx_put_image_to_window(he->mlx, he->win, he->img, 40, 0);
	mlx_destroy_image(he->mlx, he->img);
	he->img = mlx_xpm_file_to_image(he->mlx, "xpm/Wall.xpm", &he->b, &he->d);
	mlx_put_image_to_window(he->mlx, he->win, he->img, 80, 0);
	mlx_destroy_image(he->mlx, he->img);
	str = ft_strjoin1("moves :", ft_itoa(i));
	mlx_string_put(he->mlx, he->win, 5, 5, 0x00FF0000, str);
	i++;
}
