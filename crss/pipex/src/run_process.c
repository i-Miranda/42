/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:39:01 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 16:05:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_cmd(char *cmd, char *envp[])
{
	char 	**split_cmd;
	char	*path;
	int		error;

	path = NULL;
	split_cmd = ft_split(cmd, ' ');
	if (split_cmd == NULL || split_cmd[0] == NULL)
	{
		ft_printf("Pipex: command not found: %s\n", cmd);
		return (ERR_GNRL);
	}
	error = build_path(path, cmd, envp);
	if (error < ERR_NONE)
		return (error);
	execve(path, split_cmd, envp);
	free_split(split_cmd);
	return (error);
}

static int	run_child_process(t_pipe **pipe_data, char *envp[])
{
	if (dup2((*pipe_data)->fd_if, 0) == ERR_GNRL)
		return (ERR_DUP2);
	close((*pipe_data)->fd_if);
	if (dup2((*pipe_data)->fildes[0], 1) == ERR_GNRL)
		return (ERR_DUP2);
	close((*pipe_data)->fildes[0]);
	if (exec_cmd((*pipe_data)->left_cmd, envp) < ERR_NONE)
		return (ERR_XCV);
	exit(EXIT_SUCCESS);
	return (ERR_NONE);
}

int	run_processes(t_pipe **pipe_data, char *envp[])
{
	child_pid = fork();	
	parent_pid = fork();	
	if (child_pid == ERR_GNRL || parent_pid == ERR_GNRL)
		return (ERR_FORK);
	if (child_pid == ERR_NONE)
		if (run_child_process(pipe_data, envp) == ERR_NONE)
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	if (waitpid((*pipe_data)->child_pid, NULL, 0) == ERR_GNRL ||
			waitpid((*pipe_data)->parent_pid, NULL, 0) == ERR_GNRL)
		return (ERR_WTPD);
	return (ERR_NONE);
}
