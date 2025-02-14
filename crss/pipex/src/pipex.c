/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:12 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/14 20:56:21 by ivmirand         ###   ########.fr       */
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
		pipex->no_such_cmd = ft_strdup(pipex->cmds[i][0]);
		if (pipex->no_such_cmd == NULL)
			return_error(ERR_NULL, pipex, TRUE);
		else
			return_error(ERR_NCMD, pipex, TRUE);
	}
	execve(pipex->path, pipex->cmds[i], env);
	return_error(ERR_NCMD, pipex, TRUE);
}

static int	init_pipex(t_pipex **pipex, int argc, char **argv, char **env)
{
	int	error;

	error = 0;
	*pipex = ft_calloc(1, sizeof(t_pipex));
	if (*pipex == NULL)
		error = return_error(ERR_MLLC, *pipex, TRUE);
	(*pipex)->path_split = ft_split(get_path(env), ':');
	(*pipex)->cmds = split_cmds(argc, argv);
	if (!(*pipex)->cmds)
	{
		(*pipex)->no_such_cmd = argv[ARG_LCMD];
		error = return_error(ERR_NULL, *pipex, FALSE);
	}
	(*pipex)->in_fd = open(argv[ARG_IF], O_RDONLY);
	if ((*pipex)->in_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_IF];
		if (access(argv[ARG_IF], F_OK) == ERR_NONE)
			error = return_error(ERR_CHMI, *pipex, TRUE);
		else
			error = return_error(ERR_OPNI, *pipex, FALSE);
	}
	(*pipex)->of_fd = open(argv[ARG_OF], O_RDWR | O_CREAT | O_TRUNC, CHMOD_URR);
	if ((*pipex)->of_fd < ERR_NONE)
	{
		(*pipex)->no_such_file = argv[ARG_OF];
		if (access(argv[ARG_OF], F_OK) == ERR_NONE)
			error = return_error(ERR_CHMO, *pipex, TRUE);
	//	else
	//		error = return_error(ERR_OPNO, *pipex, FALSE);
	}
	return (error);
}

static void	child_process(t_pipex *pipex, int i, char **env)
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
	exec_cmd(pipex, i, env);
}

static void	parent_process(t_pipex *pipex, int i)
{
	close (pipex->pipe_fd[1]);
	if (i > ARG_LCMD)
		close (pipex->in_fd);
	if (i < ARG_LCMD)
	{
		if (pipex->in_fd < ERR_NONE)
			pipex->in_fd = open("/dev/null", O_RDONLY);
		pipex->in_fd = pipex->pipe_fd[0];
	}
	else
		close (pipex->pipe_fd[0]);
}

int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		i;
	int		error;

	pipex = NULL;
	error = init_pipex(&pipex, argc, argv, env);
	i = 0;
	while (i < ARG_RCMD)
	{
		if (i < ARG_LCMD)
			if (pipe(pipex->pipe_fd) == ERR_GNRL)
				return (return_error(EXIT_FAILURE, pipex, TRUE));
		pipex->pid = fork();
		if (pipex->pid < ERR_NONE)
			return (return_error(EXIT_FAILURE, pipex, TRUE));
		else if (pipex->pid == ERR_NONE)
			child_process(pipex, i, env);
		else
			parent_process(pipex, i);
		i++;
	}
	fd_close_wait(pipex);
	return (return_error(error, pipex, TRUE));
}
