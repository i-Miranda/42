/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:36:59 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 16:50:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	if (!envp || !envp[i])
		return (NULL);
	path = NULL;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path != NULL)
			return(&path[5]);
		i++;
	}
	return (NULL);
}

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
	else if (error == ERR_WTPD)
		perror("Waitpid failed");
	else if (error == ERR_ENVP)
		perror("Environment not set");
	else if (error == ERR_MLLC)
		perror("Malloc failed, returning NULL");
	free_all(pipex);
	exit(EXIT_FAILURE);
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

int		build_path(char *path, char *cmd, char *envp[])
{
	int	i;
	char **path_array;
	char *temp;
	
	temp = find_path(envp);
	if (temp == NULL)
		return (ERR_ENVP);
	path_array = ft_split(temp, ':');	
	free(temp);
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

int	parse_cmds(t_pipe **pipe_data, char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < (*pipe_data)->argc &&
			(*pipe_data)->cmds && (*pipe_data)->cmds[j])
	{
		(*pipe_data)->cmds[j] = ft_split(args[i], ' ');
		j++;
		i++;
	}
	return (ERR_NONE);
}


int	parse_args(t_pipe **pipe_data, char **args, int argc)
{
	(*pipe_data)->argc = argc;
	(*pipe_data)->args = malloc((*pipe_data)->argc * sizeof(char *));
	(*pipe_data)->if_path = args[0];
	(*pipe_data)->of_path = args[(*pipe_data)->argc];
	return (ERR_NONE);
}
