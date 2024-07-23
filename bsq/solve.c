#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

struct map_struct
{
	char *solution;
	char **map;
	char *map_codes;
};

void	ft_store_map(char *file, char **map, int i)
{
	int col_count;
	int	row_count;

	col_count = 0;
	row_count  = 0;
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
}

int		ft_store_key(char *file, char *map_codes)	
{
	int i;
	i = 0;
	while (file[i] != '\n')
	{
		map_codes[i] = file[i];
		i++;
	}
	return (i);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
		i++;
	while (i >= 0)
	{
		free(&map[i]);
		i--;
	}
}

char	*ft_solve_bsq(char *file)
{
	struct map_struct puzzle;
	int i;

	i = ft_store_key(file, puzzle.map_codes);	
	ft_store_map(file, puzzle.map, i);
	free_map(puzzle.map);
	return (puzzle.solution);
}
