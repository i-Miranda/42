/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 08:53:14 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, int cmd, char **envp)
{
	pipex->path = build_cmd_path(pipex->path_split, pipex->cmds[cmd][0]);
	if (!pipex->path && (*pipex->cmds[cmd])[0] != '\0')
		pipex->no_such_cmd = ft_strdup(pipex->cmds[cmd][0]);
	if (execve(pipex->path, pipex->cmds[cmd], envp) == ERR_GNRL)
		return_error(ERR_NCMD, pipex, TRUE);
}

static void	init_pipex(t_pipex **pipex, int argc, char **argv, char **envp)
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
		if (access(argv[ARG_IF], F_OK) == ERR_NONE)
			return_error(ERR_OPNI, *pipex, FALSE);
		else
			return_error(ERR_OPNI, *pipex, FALSE);
	}
	(*pipex)->of_fd = open(argv[ARG_OF], O_RDWR | O_CREAT | O_TRUNC, CHMOD_URR);
	if ((*pipex)->of_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_OF];
		return_error(ERR_CHMO, *pipex, FALSE);
	}
}

static void	child_process(t_pipex *pipex, char **envp)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == CHILD_PID)
	{
		close (pipex->pipe_fd[1]);
		if (pipex->of_fd > ERR_NONE)
			dup2(pipex->of_fd, STDOUT_FILENO);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		exec_cmd(pipex, ARG_RCMD, envp);
	}
}

static void	parent_process(t_pipex *pipex, char **envp)
{
	pipex->pid = fork();
	close (pipex->pipe_fd[0]);
	if (pipex->in_fd > ERR_NONE)
		dup2(pipex->in_fd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	exec_cmd(pipex, ARG_IF, envp);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, envp);
	if (pipe(pipex->pipe_fd) == ERR_GNRL)
		return_error(EXIT_FAILURE, pipex, TRUE);
	parent_process(pipex, envp);
	child_process(pipex, envp);
	wait_and_close(pipex);
	return_error(errno, pipex, TRUE);
	return (errno);
}
