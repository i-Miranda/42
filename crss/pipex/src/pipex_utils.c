#include "pipex.h"

void	return_error(int error)
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
	else if (error == ERR_WTPD)
		perror("Waitpid failed");
	else if (error == ERR_ENVP)
		perror("Environment not set");
	else if (error == ERR_MLLC)
		perror("Malloc failed, returning NULL");
	exit(EXIT_FAILURE);
}

int		build_path(char *path, char *cmd, char **envp)
{
	int	i;
	char **path_array;
	char *temp;
	
	i = 0;
	if (!envp || !envp[i])
		return (ERR_ENVP);
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (ERR_ENVP);
	path_array = ft_split(envp[i], ':');	
	i = 0;
	while (path_array[i])
	{
		temp = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) != ERR_GNRL)
		{
			free_split(path_array);
			return (ERR_NONE);
		}
		free(path);
		i++;
	}
	free_split(path_array);
	return (ERR_GNRL);
}

void	free_split(char **split)
{
	int	i;
	
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
