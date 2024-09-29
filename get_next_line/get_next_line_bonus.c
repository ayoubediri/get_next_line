#include "get_next_line_bonus.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char	*ft_strdup(char **str, int n) 
{
	int     i;
 	char	*s; 

	i = 0;
    s = "";
    if (*str == NULL)
        return ft_strdup(&s, 0);
    s = malloc(ft_strlen(*str) + 1);
	i = -1; 
	while (((*str)[++i]))
		s[i] = ((*str)[i]);
 	s[i] = 0;
    if (n == 1)
    {
        free(*str);
        *str = NULL;
    }
    return (s); 
}
 
char *ft_strjoin(char **s1, char *s2) 
{
    int     i;
    int     j;
    char    *str;

    i = -1;
    j = 0;
    str = malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    while (((*s1)[++i]))
        str[i] = ((*s1)[i]);
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = 0;
    free(*s1);
    return (str);
}

char    *ft_strchar(char *str, int c, ssize_t b_read)
{
    int i;

    i = 0;
    if (str == NULL)
        return (NULL);
    while (str[i])
    {
        if (str[i] == c)
            return (str + i + 1);
        i++;
    }
    if (b_read == 0)
        return (str);
    return (NULL);
}

char    *ft_get_line(int fd,char *buffer ,ssize_t b_read, char *s)
{
    char    *line;

    if (fd < 0 || BUFFER_SIZE < 0 || (b_read <= 0 && !*s))
        return (NULL);
    line = ft_strdup(&s, 1); 
    while (b_read > 0)
    {
        buffer[b_read] = 0;
        line = ft_strjoin(&line, buffer);
        if (ft_strchar(line,'\n',b_read) != NULL)
            break;
        b_read = read(fd, buffer, BUFFER_SIZE);
    }
    return (line);
}

char *get_next_line(int fd)
{
	static char	*s_line[1024];
	char		*line;
    char        *end;
	ssize_t		b_read;
	char		buffer[BUFFER_SIZE + 1];

	b_read = read(fd, buffer, BUFFER_SIZE); 
 	line = ft_get_line(fd, buffer, b_read, s_line[fd]);
    end = ft_strchar(line, '\n', b_read);
    s_line[fd] = ft_strdup(&end, 0);
    if (end != NULL)
        *end = 0;
    else if (end == NULL && b_read == 0)
        return (NULL);
    return (line);
}
