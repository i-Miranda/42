/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 22:59:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, int i, char **env)
{
	if (pipex->in_fd == ERR_GNRL)
		return ;
	pipex->path = build_path(pipex->path_split, pipex->cmds[i][0]);
	if (!pipex->path)
	{
		pipex->no_such_cmd = pipex->cmds[i][0];
		if (pipex->no_such_cmd == NULL)
			return_error(ERR_NULL, pipex);
		else
			return_error(ERR_NCMD, pipex);
	}
	execve(pipex->path, pipex->cmds[i], env);
	return_error(ERR_EXCV, pipex);
}

static void	init_pipex(t_pipex **pipex, int argc, char **argv, char **env)
{
	*pipex = ft_calloc(1, sizeof(t_pipex));
	if (*pipex == NULL)
		return_error(EXIT_FAILURE, *pipex);
	(*pipex)->path_split = ft_split(get_path(env), ':');
	(*pipex)->cmds = split_cmds(argc, argv);
	if (!(*pipex)->cmds)
		return_error(12, *pipex);
	(*pipex)->in_fd = open(argv[ARG_IF], O_RDONLY);
	if ((*pipex)->in_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_IF];
		if (access(argv[ARG_IF], F_OK) == ERR_NONE)
			return_error(ERR_CHMI, *pipex);
		else
			return_error(ERR_OPEN, *pipex);
	}
	(*pipex)->of_fd = open(argv[ARG_OF],
			O_RDWR | O_CREAT | O_TRUNC, CHMOD_RWRR);
	if ((*pipex)->of_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_OF];
		return_error(ERR_CHMO, *pipex);
	}
}

static void	child_process(t_pipex *pipex, int i, char **env)
{
	dup2(pipex->in_fd, STDIN_FILENO);
	if (i == ARG_LCMD)
	{
		if (pipex->of_fd < ERR_NONE)
			return_error(ERR_CHMD, pipex);
		dup2(pipex->of_fd, STDOUT_FILENO);
		close(pipex->of_fd);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	exec_cmd(pipex, i, env);
}

static void	parent_process(t_pipex *pipex, int i)
{
	close (pipex->pipe_fd[1]);
	if (i > ARG_LCMD)
		close (pipex->in_fd);
	if (i < ARG_LCMD)
		pipex->in_fd = pipex->pipe_fd[0];
	else
		close (pipex->pipe_fd[0]);
	if (pipex->in_fd < ERR_NONE)
		pipex->in_fd = open("/dev/null", O_RDONLY);
}

int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		i;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, env); 
	i = 0;
	while (i < ARG_RCMD)
	{
		if (i < ARG_LCMD)
			if (pipe(pipex->pipe_fd) == ERR_GNRL)
				return (return_error(EXIT_FAILURE, pipex));
		pipex->pid = fork();
		if (pipex->pid < ERR_NONE)
			return (return_error(EXIT_FAILURE, pipex));
		else if (pipex->pid == ERR_NONE)
			child_process(pipex, i, env);
		else
			parent_process(pipex, i);
		i++;
	}
	fd_close_wait(pipex);
	return (return_error(EXIT_SUCCESS, pipex));
}
