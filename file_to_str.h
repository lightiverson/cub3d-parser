#ifndef FILE_TO_STR_H
# define FILE_TO_STR_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	file_to_str(int fd, char **file_str);

#endif /* file_to_str.h */