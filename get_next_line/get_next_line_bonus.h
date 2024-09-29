#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//handle the buffer_size 
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
// include libraries :
#include <unistd.h>
#include <stdlib.h>

// prototype of functions:
char	*get_next_line(int fd);

#endif
