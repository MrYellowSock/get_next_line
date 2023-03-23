#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// READ BUFFER SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_LINE_SIZE
#  define MAX_LINE_SIZE 2097152
# endif

void	*ft_memcpy(void *dst, const void *src, size_t n);
char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
