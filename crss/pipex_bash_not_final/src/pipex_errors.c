/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 20:39:13 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	else if (error == ERR_OPNI || error == ERR_OPNO)
	{
		if (error == ERR_OPNI)
			ft_putstr_fd("cannot open ", STDERR_FILENO);
		else
			ft_putstr_fd("cannot create ", STDERR_FILENO);
		build_file_suffix(pipex);
		if (error == ERR_OPNO)
			error = EXIT_SUCCESS;
		else
			error = EXIT_FAILURE;
	}
	else if (error == ERR_NCMD)
	{
		if (pipex->no_such_cmd != NULL)
			ft_putstr_fd(pipex->no_such_cmd, STDERR_FILENO);
		ft_putendl_fd(": not found", STDERR_FILENO);
	}
//	else
//		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	return (error);
}

void	return_error(int error, t_pipex *pipex, int exitbool)
{
	ft_putstr_fd("Pipex: ", STDERR_FILENO);
	error = handle_error(error, pipex);
	if (exitbool == TRUE)
	{
		if (pipex != NULL)
			free_pipex(pipex);
		exit(error);
	}
}
