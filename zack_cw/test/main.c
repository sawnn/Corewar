#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
void	my_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int	main()
{
	int	fd = open("ici", O_CREAT | O_RDWR);
	int	i = 65530;
	int	*j = 0;
	char	*bytes = malloc(sizeof(100));

	j = malloc(10);
	//bytes[0] = (i >> 24) & 0xFF;
	//bytes[1] = (i >> 16) & 0xFF;
	//bytes[2] = (i >> 8) & 0xFF;
	//bytes[3] = i & 0xFF;
	bytes[0] = (i >> 8) & 0xFF;
	bytes[1] = i & 0xFF;
	my_putchar(fd, bytes[0]);
	my_putchar(fd, bytes[1]);
	//my_putchar(fd, bytes[2]);
	//my_putchar(fd, bytes[3]);
	
}
