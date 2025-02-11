#include "pipex.h"

void	return_error(int error, t_pipex *pipex)
{
	if (error == ERR_INPT)
		perror("Pipex: infile command1 command2 outfile");
	else if (error == ERR_PIPE)
		perror("Pipe failed");
	else if (error == ERR_OPEN)
		perror("Open failed");
	else if (error == ERR_FORK)
		perror("Fork failed");
	else if (error == ERR_ACS)
		perror("Access failed");
	else if (error == ERR_DUP2)
		perror("Dup2 failed");
	else if (error == ERR_XCV)
		perror("Execve failed");
	else if (error == ERR_ENVP)
		perror("Environment not set");
	else if (error == ERR_MLLC)
		perror("Malloc failed, returning NULL");
	if (pipex != NULL)
		free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	fd_close_wait(t_pipex *pipex, int argc)
{
	int	i;

	close(pipex->in_fd);
	close(pipex->of_fd);
	i = 0;
	while (i < argc - 2)
	{
		wait(NULL);
		i++;
	}
}

char	***split_cmds(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = 1;
	cmds = malloc(sizeof(char **) * argc);
	while (i < (argc))
	{
		cmds[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	cmds[i - 1] = NULL;
	return (cmds);
}

char	*find_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (!env || !*env)
		return (NULL);
	path = NULL;
	while (env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path != NULL)
			return (&path[5]);
		i++;
	}
	return (NULL);
}

char	*build_path(char **path_split, char *command)
{
	char	*temp;
	char	*path;
	int		i;

	if (ft_strchr(command, '/') && (access(command, X_OK) == 0))
		return (ft_strdup(command));
	i = 0;
	if (path_split)
	{
		while (path_split[i])
		{
			temp = ft_strjoin(path_split[i], "/");
			path = ft_strjoin(temp, command);
			free(temp);
			if (access(path, X_OK) == 0)
				return (path);
			free(path);
			i++;
		}
	}
	return (NULL);
}
