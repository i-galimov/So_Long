/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:34:56 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 11:35:35 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (*s1)
	{
		s3[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		s2++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest == NULL)
		return (NULL);
	while (++i < s1_len)
		dest[i] = s1[i];
	while (j <= s2_len)
		dest[i++] = s2[j++];
	free(s1);
	return (dest);
}
