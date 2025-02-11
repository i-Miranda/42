#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	if (pipex->cmds)
	{
		while (pipex->cmds[i])
		{
			j = 0;
			while (pipex->cmds[i][j])
				free(pipex->cmds[i][j++]);
			free(pipex->cmds[i++]);
		}
	}
	free(pipex->cmds);
	i = 0;
	while (pipex->path_split && pipex->path_split[i])
		free(pipex->path_split[i++]);
	free(pipex->path_split);
	free(pipex);
}


int	main(int argc, char **argv, char **env)
{
	if (argc != ARGC)
		return_error(ERR_INPT, NULL);
	pipex(argc - 1, &argv[1], env);
	return (0);
}
