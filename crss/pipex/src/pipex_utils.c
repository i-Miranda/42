/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 20:51:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	close_fds(pipex);
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

char	*get_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	if (!envp || !*envp)
		return (EMERGENCY_PATH);
	path = NULL;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path != NULL)
			return (&path[5]);
		i++;
	}
	return (NULL);
}

char	*build_cmd_path(char **path_split, char *cmd)
{
	char	*temp;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	if (cmd[0] == '\0' || (ft_strchr(cmd, '/')
			&& access(cmd, X_OK) == ERR_NONE))
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
