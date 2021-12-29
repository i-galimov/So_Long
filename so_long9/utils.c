/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:35:52 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/15 16:45:00 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s + start);
	if (l < len)
		len = l;
	i = 0;
	j = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j++] = s[i];
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

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

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
