/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:29:43 by phella            #+#    #+#             */
/*   Updated: 2022/02/23 15:52:31 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_qlines(void)
{
	write(1, "Error in quantity lines\n", 24);
	exit(1);
}

void	ft_error_arg(void)
{
	write(1, "Error in argument\n", 18);
	exit(1);
}

void	ft_error_elements(void)
{
	write(1, "Error in element\n", 17);
	exit(1);
}

void	ft_error_wall(void)
{
	write(1, "Error in wall\n", 14);
	exit(1);
}
