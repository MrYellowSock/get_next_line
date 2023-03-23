/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:16:05 by skulkamt          #+#    #+#             */
/*   Updated: 2023/03/23 23:21:39 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// READ BUFFER SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dest, char *src);

typedef struct s_vec
{
	char	*buff;
	size_t	offset;
	size_t	size;
}			t_vec;

#endif
