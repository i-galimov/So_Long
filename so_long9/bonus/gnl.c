/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:47:27 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/13 11:47:32 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_read(char *text, int fd)
{
	char	*buff;
	int		n;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	n = 1;
	while (!(ft_strchr(text, '\n')) && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*ft_just_a_line(char *text)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_change_text(char *text)
{
	char	*newtext;
	size_t	len;
	size_t	i;

	len = 0;
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\0')
	{
		free(text);
		return (NULL);
	}
	i = 0;
	newtext = (char *)malloc(sizeof(char) * (ft_strlen(text) - len + 1));
	if (newtext == NULL)
		return (NULL);
	while (text[len++] != '\0')
		newtext[i++] = text[len];
	newtext[i] = '\0';
	free(text);
	return (newtext);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_read(text, fd);
	if (text == NULL)
		return (NULL);
	line = ft_just_a_line(text);
	text = ft_change_text(text);
	return (line);
}
