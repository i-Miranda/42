/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 18:36:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
}

void	return_error(int error, t_pipex *pipex)
{
	if (error == ERR_INPT)
	{
		ft_printf("Pipex: infile command1 command2 outfile\n");
		exit_pipex(pipex, EXIT_FAILURE);
	}
	else if (error == ERR_OPEN)
	{
		ft_printf("Pipex: no such file or directory: %s\n",
			pipex->no_such_file);
		return ;
	}
	else if (error == ERR_EXCV || error == ERR_CHMI || error == ERR_CHMO)
	{
		if (pipex->no_such_file != NULL)
			ft_printf("Pipex: permission denied: %s\n", pipex->no_such_file);
		else	
			ft_printf("Pipex: permission denied:\n");
		if (error == ERR_CHMI)
			return ;
		exit_pipex(pipex, ERR_EXCV);
	}
	else if (error == ERR_NCMD)
	{
		ft_printf("Pipex: command not found: %s\n", pipex->no_such_cmd);
		exit_pipex(pipex, ERR_EXCV);
	}
}
