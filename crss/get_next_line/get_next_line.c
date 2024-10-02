#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	**list;
	char			*buf;
	char			*next_line;
	
	if (build_t_list(list) == NULL)
		return (NULL);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE - 1);
	if (!check_newline(buf))
		get_next_line(fd);
	else
		return (next_line);
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
