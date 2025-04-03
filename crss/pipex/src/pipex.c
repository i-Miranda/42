/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/17 17:42:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, int cmd, char **envp)
{
	char	*path;

	path = build_cmd_path(pipex->path_split, pipex->cmds[cmd][0]);
	pipex->no_such_cmd = pipex->cmds[cmd][0];
	if (!path)
		path = ft_strdup("");
	execve(path, pipex->cmds[cmd], envp);
	if (path)
		free(path);
	return_error(ERR_NCMD, pipex, TRUE);
}

static int	child_process(t_pipex *pipex, char **argv, char **envp)
{
	pid_t	pid;

	if (pipex->of_fd < ERR_NONE)
	{
		pipex->no_such_file = argv[ARG_OF];
		if (access(argv[ARG_OF], F_OK) == ERR_NONE)
			return_error(ERR_CHMO, pipex, FALSE);
		else
			return_error(ERR_OPNO, pipex, FALSE);
		return (ERR_GNRL);
	}
	pid = fork();
	if (pid == CHILD_PID)
	{
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		dup2(pipex->of_fd, STDOUT_FILENO);
		close_fds(pipex);
		exec_cmd(pipex, 1, envp);
	}
	else if (pid < CHILD_PID)
		return_error(EXIT_FAILURE, pipex, FALSE);
	return (pid);
}

static int	parent_process(t_pipex *pipex, char **argv, char **envp)
{
	pid_t	pid;

	if (pipex->in_fd < ERR_NONE)
	{
		pipex->no_such_file = argv[ARG_IF];
		if (access(argv[ARG_IF], F_OK) == ERR_NONE)
			return_error(ERR_CHMI, pipex, FALSE);
		else
			return_error(ERR_OPNI, pipex, FALSE);
		return (ERR_GNRL);
	}
	pid = fork();
	if (pid == CHILD_PID)
	{
		dup2(pipex->in_fd, STDIN_FILENO);
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close_fds(pipex);
		exec_cmd(pipex, 0, envp);
	}
	else if (pid < CHILD_PID)
		return_error(EXIT_FAILURE, pipex, FALSE);
	return (pid);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	pid_t	pid1;
	pid_t	pid2;
	int		pid2_status;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, envp);
	if (pipe(pipex->pipe_fd) == ERR_GNRL)
		return_error(EXIT_FAILURE, pipex, TRUE);
	pid1 = parent_process(pipex, argv, envp);
	pid2 = child_process(pipex, argv, envp);
	pid2_status = wait_and_close(pipex, pid1, pid2);
	free_pipex(pipex);
	return (errno);
}
