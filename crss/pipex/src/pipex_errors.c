/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/14 11:15:09 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	join_perror_str(char *str, char *append_str)
{
	if (append_str != NULL)
		str = ft_strjoin(str, append_str);
	perror(str);
	free(str);
}

static int	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
	return (exit_code);
}

static int	handle_error(int error, char *str, t_pipex *pipex)
{
	if (error == ERR_INPT)
	{
		join_perror_str(str, "infile command1 command2 outfile");
		error = EXIT_FAILURE;
	}
	else if (error == ERR_OPNI || error == ERR_OPNO)
	{
		join_perror_str(str, pipex->no_such_file);
		if (error == ERR_OPNI)
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	else if (error == ERR_CHMI || error == ERR_CHMO)
	{
		join_perror_str(str, pipex->no_such_file);
		if (error != ERR_CHMI)
			error = EXIT_FAILURE;
	}
	else if (error == ERR_NCMD || error == ERR_NULL)
	{
		join_perror_str(str, NULL);
		error = ERR_NCMD;
	}
	return (error);
}

int	return_error(int error, t_pipex *pipex)
{
	char	*str;

	str = ft_strdup("Pipex: ");
	error = handle_error(error, str, pipex);
	return (exit_pipex(pipex, error));
}
