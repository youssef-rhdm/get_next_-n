#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	int fd = open("file.txt",O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s", str);
	return 0;
}
