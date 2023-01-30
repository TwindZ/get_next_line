#include "get_next_line.h"

int main()
{
	int 	fd;
	char	buf[BUFFER_SIZE];
	int ret;

	fd = open("test.txt", O_RDONLY);
	if((fd = open("test.txt", O_RDONLY))== -1)
	{
		printf("open() fail");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
	// ret = read(fd, buf, BUFFER_SIZE);
	// printf("%d", ret);
	// ret = read(fd, buf, BUFFER_SIZE);
	// printf("%d", ret);
	// ret = read(fd, buf, BUFFER_SIZE);
	// printf("%d", ret);	
	// ret = read(fd, buf, BUFFER_SIZE);
	// printf("%d", ret);


	if (close(fd) == -1)
	{
		printf("close() fail");
		return (1);
	}
}