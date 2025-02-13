/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/13 23:05:29 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
	return (exit_code);
}

int	return_error(int error, t_pipex *pipex)
{
	char *str;

	if (error == ERR_INPT)
	{
		perror("Pipex: infile command1 command2 outfile");
		return (exit_pipex(pipex, EXIT_FAILURE));
	}
	else if (error == ERR_OPNI || error == ERR_OPNO)
	{
		str = ft_strdup("Pipex: ");
		if (pipex->no_such_file != NULL)
			str = ft_strjoin(str, pipex->no_such_file);
		perror(str);
		free(str);
		if (error == ERR_OPNI)
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	else if (error == ERR_CHMI || error == ERR_CHMO)
	{
		str = ft_strdup("Pipex: ");
		if (pipex->no_such_file != NULL)
			str = ft_strjoin(str, pipex->no_such_file);
		perror(str);
		free(str);
		if (error == ERR_CHMI)
			return (error);
		return (exit_pipex(pipex, EXIT_FAILURE));
	}
	else if (error == ERR_NCMD)
	{
		str = ft_strdup("Pipex: ");
		perror(str);
		free(str);
		return (ERR_EXCV);
	}
	else if (error == ERR_NULL)
	{
		str = ft_strdup("Pipex: ");
		perror(str);
		free(str);
		return (exit_pipex(pipex, ERR_EXCV));
	}
	return (exit_pipex(pipex, error));
}
