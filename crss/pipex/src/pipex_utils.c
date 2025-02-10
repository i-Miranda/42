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

int	parse_cmds(t_pipe **pipe_data, char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < (*pipe_data)->argc)
	{
		(*pipe_data)->cmds[j] = ft_split(args[i], ' ');
		j++;
		i++;
	}
	return (ERR_NONE);
}


int	parse_args(t_pipe **pipe_data, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	(*pipe_data)->argc = i;
	(*pipe_data)->if_path = args[0];
	(*pipe_data)->of_path = args[(*pipe_data)->argc];
	return (ERR_NONE);
}
