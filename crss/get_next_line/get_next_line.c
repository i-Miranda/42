#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*fd_stream;
	static ssize_t	read_val;
	size_t			count;
	
	count = 0;
	fd_stream = malloc(read(fd, 
	while (!check_new_line(fd_stream))
	{
		read_val = read(fd, fd_stream, count);	
		count++;
		return (next_line);
	}
	return (NULL);	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (argv[1] == '0')
		{
			return (0);
		}
		else if (argv[1] == '1')
		{
			return (0);
		}
		else if (argv[1] == '2')
		{
			return (0);
		}
		else
			return (1);
	}
	return (1);
}
