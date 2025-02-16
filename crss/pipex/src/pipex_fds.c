/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:11:04 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 20:22:13 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	(*pipex)->of_fd = open(argv[ARG_OF], O_RDWR | O_CREAT | O_TRUNC, CHMOD_URR);
}

int	wait_and_close(t_pipex *pipex, pid_t pid1, pid_t pid2)
{
	int	pid2_status;

	pid2_status = 0;
	close_fds(pipex);
	if (pid2 != ERR_GNRL)
		waitpid(pid2, &pid2_status, 0);
	if (pid1 != ERR_GNRL)
		wait(NULL);
	if (WIFEXITED(pid2_status))
		pid2_status = WEXITSTATUS(pid2_status);
	return (pid2_status);
}

void	close_fds(t_pipex *pipex)
{
	close(pipex->in_fd);
	close(pipex->of_fd);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
