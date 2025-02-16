/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 01:08:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, int i, char **envp)
{
	pipex->path = build_cmd_path(pipex->path_split, pipex->cmds[i][0]);
	if (!pipex->path)
	{
		if (ft_strncmp(pipex->cmds[i][0], "", 1) == 0)
			pipex->no_such_cmd = ft_strdup(pipex->cmds[i][0]);
	}
	if (execve(pipex->path, pipex->cmds[i], envp) == ERR_GNRL)
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

static void	child_process(t_pipex *pipex, int i, char **envp)
{
	dup2(pipex->in_fd, STDIN_FILENO);
	if (i == ARG_LCMD)
	{
		if (pipex->of_fd < ERR_NONE)
			return_error(EXIT_FAILURE, pipex, TRUE);
		dup2(pipex->of_fd, STDOUT_FILENO);
		close(pipex->of_fd);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	exec_cmd(pipex, i, envp);
}

static void	parent_process(t_pipex *pipex, int i)
{
	close (pipex->pipe_fd[1]);
	if (i >= ARG_IF)
		close (pipex->in_fd);
	if (i < ARG_LCMD)
		pipex->in_fd = pipex->pipe_fd[0];
	else
		close (pipex->pipe_fd[0]);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, envp);
	i = 0;
	while (i < ARG_RCMD)
	{
		if (i < ARG_LCMD)
			if (pipe(pipex->pipe_fd) == ERR_GNRL)
				return_error(EXIT_FAILURE, pipex, TRUE);
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
