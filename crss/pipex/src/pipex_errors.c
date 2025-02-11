/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 14:52:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_pipex(t_pipex *pipex)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	return_error(int error, t_pipex *pipex)
{
	if (error == ERR_INPT)
		ft_printf("Pipex: infile command1 command2 outfile\n");
	else if (error == ERR_PIPE)
	{
		perror("Pipe failed");
		return ;
	}
	else if (error == ERR_OPEN)
	{
		perror("Open failed");
		return ;
	}
	else if (error == ERR_FORK)
		perror("Fork failed");
	else if (error == ERR_CHMD)
		perror("File descriptor inaccessible");
	else if (error == ERR_EXCV)
		perror("Execve failed");
	else if (error == ERR_ENVP)
		perror("Environment not set");
	else if (error == ERR_MLLC)
		perror("Malloc failed, returning NULL");
	else if (error == ERR_SPLT)
		perror("Split failed");
	exit_pipex(pipex);
}
