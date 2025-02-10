#include "pipex.h"

void	return_error(int error)
{
	if (error == -1)
		perror("Pipex: infile command1 command2 outfile");
	else if (error == -2)
		perror("pipe failed");
	else if (error == -3)
		perror("open failed");
	else if (error == -4)
		perror("fork failed");
	else if (error == -5)
		perror("access failed");
	else if (error == -6)
		perror("dup2 failed");
	else if (error == -7)
		perror("execve failed");
	else if (error == -8)
		perror("waitpid failed");
	else if (error == -9)
		perror("environment not set");
	exit(EXIT_FAILURE);
}

int		build_path(char *path, char *cmd, char **envp)
{
	int	i;
	char **path_array;
	
	i = 0;
	if (!envp || !envp[i])
		return (-9);
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (-9);
	else
		path_array = ft_split(envp[i], ':');	
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
