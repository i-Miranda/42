/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 23:02:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
}

int	return_error(int error, t_pipex *pipex)
{
	char *str;

	if (error == ERR_INPT)
	{
		ft_printf("Pipex: infile command1 command2 outfile\n");
		return (exit_pipex(pipex, EXIT_FAILURE));
	}
	else if (error == ERR_OPEN)
	{
		ft_printf("Pipex: no such file or directory: %s\n",
			pipex->no_such_file);
		return (error);
	}
	else if (error == ERR_CHMI || error == ERR_CHMO)
	{
		str = ft_strdup("Pipex: permission denied: ");
		if (pipex->no_such_file != NULL)
			ft_strjoin(str, pipex->no_such_file);
		str = ft_strjoin(str, strerror(ERR_CHMD));
		perror(str);
		free(str);
		if (error == ERR_CHMI)
			return (error);
		return (exit_pipex(pipex, ERR_CHMD));
	}
	else if (error == ERR_NCMD)
	{
		str = ft_strjoin("Pipex: command not found: ", strerror(errno));
		perror(str);
		free(str);
		return (ERR_EXCV);
	}
	else if (error == ERR_NULL)
	{
		str = ft_strdup("Pipex: permission denied: ");
		if (pipex->no_such_file != NULL)
			ft_strjoin(str, pipex->no_such_file);
		str = ft_strjoin(str, strerror(ERR_CHMD));
		perror(str);
		free(str);
		return (exit_pipex(pipex, ERR_EXCV));
	}
	return (exit_pipex(pipex, error));
}
