#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "solve.c"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
		solution = malloc(ft_strlen(file));
		write(1, file, 1000);
		write(1, "\n", 1);
		solution = ft_solve_bsq(file);
		write(1, solution, 1000);
		write(1, "\n", 1);
		free(solution);
	}
	return (0);
}
