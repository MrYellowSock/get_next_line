#include "get_next_line.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (src == NULL && dst == NULL && n > 0)
	{
		return (NULL);
	}
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s != 0)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	new_len;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_len = len1 + len2 + 1;
	new_str = malloc(new_len);
	if (new_str == NULL)
	{
		return (NULL);
	}
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	tocheck;
	size_t	i;

	tocheck = ft_strlen(s);
	i = 0;
	while (i <= tocheck)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

// split only the first occurence of sep
char	**ft_split_half(char const *s, char sep)
{
	char	**output;
	char	*break_point;
	int		left_size;
	int		right_size;

	break_point = ft_strchr(s, sep);
	if (!break_point)
		return (NULL);
	output = malloc(sizeof(char *) * 2);
	if (!output)
		return (NULL);
	left_size = break_point - s + 1;
	right_size = ft_strlen(s) - left_size;
	output[0] = malloc(left_size + 1);
	output[1] = malloc(right_size + 1);
	if (!output[0] && !output[1])
		return (NULL);
	output[0][left_size] = 0;
	ft_memcpy(output[0], s, left_size);
	ft_memcpy(output[1], s + left_size, right_size);
	return (output);
}
