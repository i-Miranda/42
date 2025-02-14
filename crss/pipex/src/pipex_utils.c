/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/14 19:16:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			{
				free(pipex->cmds[i][j]);
				j++;
			}
			free(pipex->cmds[i]);
			i++;
		}
	}
	free(pipex->cmds);
	i = 0;
	while (pipex->path_split && pipex->path_split[i])
		free(pipex->path_split[i++]);
	free(pipex->path_split);
	free(pipex);
}

void	fd_close_wait(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->in_fd);
	close(pipex->of_fd);
	while (i < ARG_RCMD)
	{
		wait(NULL);
		i++;
	}
}

char	***split_cmds(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = ARG_LCMD;
	cmds = ft_calloc(argc, sizeof(char **));
	if (cmds != NULL)
	{
		while (i < argc)
		{
			cmds[i - 1] = ft_split(argv[i], ' ');
			i++;
		}
	}
	return (cmds);
}

char	*get_path(char **env)
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

char	*build_path(char **path_split, char *cmd)
{
	char	*temp;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == ERR_NONE)
		return (ft_strdup(cmd));
	i = 0;
	if (path_split)
	{
		while (path_split[i])
		{
			temp = ft_strjoin(path_split[i], "/");
			path = ft_strjoin(temp, cmd);
			free(temp);
			if (access(path, X_OK) == ERR_NONE)
				return (path);
			free(path);
			i++;
		}
	}
	return (NULL);
}
