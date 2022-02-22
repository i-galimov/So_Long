#include "../so_long.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char			*dest_pointer;
	const char		*src_pointer;

	dest_pointer = (char *) dst;
	src_pointer = (char *) src;
	if (dst || src)
	{
		if (dest_pointer < src_pointer)
			while (len--)
				*dest_pointer++ = *src_pointer++;
		else
			while (len--)
				*(dest_pointer + len) = *(src_pointer + len);
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len_of_both;
	char	*final_string;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len_of_both = s1_len + s2_len + 1;
	final_string = malloc(sizeof(char) * len_of_both);
	if (final_string == NULL)
		return (NULL);
	ft_memmove(final_string, s1, s1_len);
	ft_memmove(final_string + s1_len, s2, s2_len);
	final_string[len_of_both - 1] = '\0';
	return (final_string);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	if (s[i] || c == 0)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	string_lenght;
	char	*copy_pointer;

	string_lenght = ft_strlen(s1) + 1;
	copy_pointer = (char *) malloc(string_lenght);
	if (copy_pointer == NULL)
		return (NULL);
	ft_memcpy(copy_pointer, s1, string_lenght);
	return (copy_pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	s_len = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && s_len < len)
		{
			str[s_len] = s[i];
			s_len++;
		}
		i++;
	}
	str[s_len] = 0;
	return (str);
}
