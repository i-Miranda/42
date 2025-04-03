/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors_bash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/17 17:30:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	build_file_suffix(t_pipex *pipex, int file_or_cmd, char *str_error)
{
	if (file_or_cmd == 0)
	{
		if (pipex->no_such_file != NULL)
			ft_putstr_fd(pipex->no_such_file, STDERR_FILENO);
	}
	else
	{
		if (pipex->no_such_cmd != NULL)
			ft_putstr_fd(pipex->no_such_cmd, STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str_error, STDERR_FILENO);
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
		build_file_suffix(pipex, 0, "No such file or directory");
		error = EXIT_FAILURE;
	}
	else if (error == ERR_CHMI || error == ERR_CHMO)
	{
		build_file_suffix(pipex, 0, "Permission denied");
		error = EXIT_FAILURE;
	}
	else if (error == ERR_NCMD)
		build_file_suffix(pipex, 1, "command not found");
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
