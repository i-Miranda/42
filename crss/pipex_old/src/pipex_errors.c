/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 13:21:40 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	build_prefix(t_pipex *pipex)
{
	ft_putstr_fd("Pipex: ", STDERR_FILENO);
	if (pipex != NULL)
		ft_putnbr_fd(pipex->pid, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
}

static void	build_file_suffix(t_pipex *pipex)
{
	ft_putstr_fd(pipex->no_such_file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

static int	handle_error(int error, t_pipex *pipex)
{
	if (error == ERR_INPT)
	{
		ft_putstr_fd("infile command1 command2 outfile\n", STDERR_FILENO);
		error = EXIT_FAILURE;
	}
	else if (error == ERR_OPNI || error == ERR_CHMO)
	{
		if (error == ERR_OPNI)
			ft_putstr_fd("cannot open ", STDERR_FILENO);
		else
			ft_putstr_fd("cannot create ", STDERR_FILENO);
		build_file_suffix(pipex);
		if (error == ERR_CHMO)
			error = EXIT_FAILURE;
		else
			error = EXIT_SUCCESS;
	}
	else if (error == ERR_NCMD || error == ERR_NULL)
	{
		if (pipex->no_such_cmd != NULL)
			ft_putstr_fd(pipex->no_such_cmd, STDERR_FILENO);
		if (error == ERR_NCMD)
			ft_putendl_fd(": not found", STDERR_FILENO);
		else if (error == ERR_NULL)
			ft_putendl_fd(": permission denied", STDERR_FILENO);
	}
	return (error);
}

void	return_error(int error, t_pipex *pipex, int exitbool)
{
	build_prefix(pipex);
	error = handle_error(error, pipex);
	if (exitbool == TRUE)
	{
		if (pipex)
			free_pipex(pipex);
		exit(error);
	}
}
