#include "../so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) b;
	while (len--)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest_pointer;
	char	*src_pointer;

	dest_pointer = (char *) dst;
	src_pointer = (char *) src;
	while (n)
	{
		*(dest_pointer++) = *(src_pointer++);
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

static char	*making_a_line(int fd, char *last_line, char *buffer)
{
	int		read_return;
	char	*temp;

	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (!read_return)
			break ;
		else if (read_return == -1)
			return (0);
		buffer[read_return] = '\0';
		if (!last_line)
			last_line = ft_strdup("");
		temp = last_line;
		last_line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (last_line);
}

char	*gnl(int fd)
{
	size_t		count;
	char		*buffer;
	char		*line_ptr;
	static char	*backup;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	count = 0;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line_ptr = making_a_line(fd, backup, buffer);
	free(buffer);
	if (!line_ptr)
		return (NULL);
	while (line_ptr[count] != '\0' && line_ptr[count] != '\n')
		count++;
	backup = ft_substr(line_ptr, count + 1, ft_strlen(line_ptr) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line_ptr[count + 1] = '\0';
	return (line_ptr);
}
