#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buf[1];
	size_t			count;
	ssize_t			read_val;
	
	buf[0] = 0;
	count = sizeof(char);
	read_val = -1;
	while (!check_new_line(buf[0]))
	{
		read_val = read(fd, buf, count);
		if (read_val == -1)
			return (NULL);
		buf[1] = 0;
	}
	return (buf);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (argv[1] == "0")
		{
			get_next_line(0);
			return (0);
		}
		else if (argv[1] == "1")
		{
			get_next_line(1);
			return (0);
		}
		else if (argv[1] == "2")
		{
			get_next_line(2);
			return (0);
		}
		else
			return (1);
	}
	return (1);
}
