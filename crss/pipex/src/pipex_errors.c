/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/15 12:46:21 by ivan             ###   ########.fr       */
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

static int	handle_error(int error, t_pipex *pipex)
{
	if (error == ERR_INPT)
	{
		ft_putstr_fd("infile command1 command2 outfile\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (error == ERR_OPNI || error == ERR_CHMI || error == ERR_CHMO)
	{
		if (error == ERR_OPNI || error == ERR_CHMI)
			ft_putstr_fd("cannot open :", STDERR_FILENO);
		else
			ft_putstr_fd("cannot create :", STDERR_FILENO);
		ft_putstr_fd(pipex->no_such_file, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		if (error == ERR_CHMO)
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	else if (error == ERR_NCMD || error == ERR_NULL)
	{
		if (pipex->no_such_cmd != NULL)
			ft_putstr_fd(pipex->no_such_cmd, STDERR_FILENO);
		ft_putstr_fd(": not found\n", STDERR_FILENO);
		error = ERR_NCMD;
	}
	return (error);
}

static int	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
	return (exit_code);
}

int	return_error(int error, t_pipex *pipex, int exit)
{
	if (error == EXIT_SUCCESS || error == EXIT_FAILURE)
		return (exit_pipex(pipex, error));
	build_prefix(pipex);
	if (exit == TRUE)
		return (exit_pipex(pipex, handle_error(error, pipex)));
	return (handle_error(error, pipex));
}
