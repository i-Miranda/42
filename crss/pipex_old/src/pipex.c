/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 20:17:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_cmd(t_pipex *pipex, int cmd, char **envp)
{
	pipex->path = build_cmd_path(pipex->path_split, pipex->cmds[cmd][0]);
	if (!pipex->path)
	{
		pipex->no_such_cmd = ft_strdup(pipex->cmds[cmd][0]);
		if (pipex->cmds[cmd][0][0] == '\0')
			return_error(ERR_NCMD, pipex, TRUE);
	}
	if (execve(pipex->path, pipex->cmds[cmd], envp) == ERR_GNRL)
	{
		return_error(ERR_NCMD, pipex, FALSE);
		return (ERR_GNRL);
	}
	return (ERR_NONE);
}

static void	child_process(t_pipex *pipex, int cmd, char **envp)
{
	if (cmd == 0)
		dup2(pipex->in_fd, STDIN_FILENO);
	else
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
	if (pipex->of_fd < ERR_NONE)
		return_error(EXIT_FAILURE, pipex, TRUE);
	if (cmd == 2)
		dup2(pipex->of_fd, STDOUT_FILENO);
	else
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	exec_cmd(pipex, cmd, envp);
}

static void	parent_process(t_pipex *pipex, int i)
{
	if (i < ARG_LCMD)
		pipex->in_fd = pipex->pipe_fd[0];
	close (pipex->pipe_fd[0]);
	close (pipex->pipe_fd[1]);
}

void	init_pipex(t_pipex **pipex, int argc, char **argv, char **envp)
{
	*pipex = ft_calloc(1, sizeof(t_pipex));
	if (*pipex == NULL)
		return_error(ERR_MLLC, *pipex, TRUE);
	(*pipex)->path_split = ft_split(get_path(envp), ':');
	(*pipex)->cmds = split_cmds(argc, argv);
	if (!(*pipex)->cmds)
		return_error(ERR_MLLC, *pipex, TRUE);
	(*pipex)->in_fd = open(argv[ARG_IF], O_RDONLY);
	if ((*pipex)->in_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_IF];
		return_error(ERR_OPNI, *pipex, FALSE);
	}
	(*pipex)->of_fd = open(argv[ARG_OF], O_RDWR | O_CREAT | O_TRUNC, CHMOD_URR);
	if ((*pipex)->of_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_OF];
		return_error(ERR_CHMO, *pipex, FALSE);
	}
}

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;
	int		execute_ok;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, envp);
	i = 0;
	execute_ok = 0;
	if (pipe(pipex->pipe_fd) == ERR_GNRL)
		return_error(EXIT_FAILURE, pipex, TRUE);
	while (i < 2)
	{
		pipex->pid = fork();
		if (pipex->pid < CHILD_PID)
			return_error(EXIT_FAILURE, pipex, TRUE);
		if (pipex->pid == CHILD_PID)
			child_process(pipex, i, envp);
		else
			parent_process(pipex, i);
		i++;
	}
	fd_close_wait(pipex);
	free_pipex(pipex);
	return (EXIT_SUCCESS);
}
