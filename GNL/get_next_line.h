#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strchr_len(const char *s, char c);
size_t	ft_strlen(const char *str);

#endif
