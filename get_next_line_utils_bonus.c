/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:15:47 by skulkamt          #+#    #+#             */
/*   Updated: 2023/03/23 23:22:14 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	size_t	cnt;

	cnt = 0;
	while (*s != 0)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

// this one ignore 0
char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*newone;
	size_t	i;

	n = ft_strlen(s1);
	newone = malloc((n + 1) * sizeof(char));
	if (newone == NULL)
	{
		return (newone);
	}
	i = 0;
	while (i < n)
	{
		newone[i] = s1[i];
		i++;
	}
	newone[n] = 0;
	return (newone);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_pointing;

	dest_pointing = dest;
	while (*src != 0)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
	return (dest_pointing);
}
