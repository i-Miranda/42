#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *ft_solve_bsq(char *file)
{
	char *solution;
	char **map;
	char *map_codes;
	int col_count;
	int	row_count;
	int i;

	i = 0;
	col_count = 0;
	row_count  = 0;
	while (file[i] != '\n')
	{
		map_codes[i] = file[i];
		i++;
	}
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			row_count++;
		else
			col_count++;
		i++;
	}
	map = malloc(sizeof(char) * row_count);
	i = 0;
	while (i < row_count)
	{
		map[i] = malloc(sizeof(char) * col_count);
		i++;
	}
	free(map);
	return (solution);
}

int	main(int argc, char **argv)
{
	int	n;
	char file[1000];
	char *solution;

	n = 1;

	while (n < argc)
	{
		read(open(argv[1], 0), file, 1000);
		solution = malloc(sizeof(file));
		write(1, file, 1000);
		write(1, "\n", 1);
		solution = ft_solve_bsq(file);
		write(1, solution, 1000);
		write(1, "\n", 1);
		free(solution);
	}
	return (0);
}
