/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/14 20:19:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_perror_prefix(t_pipex *pipex)
{
	char	*itoa;
	char	*new_str;
	char	*temp_str;

	itoa = NULL;
	temp_str = NULL;
	new_str = ft_strdup("Pipex: ");
	if (pipex != NULL)
	{
		itoa = ft_itoa(pipex->pid);
		temp_str = ft_strjoin(new_str, itoa);
		free(new_str);
		new_str = ft_strjoin(temp_str, ": ");
		free(temp_str);
		free(itoa);
	}
	return (new_str);
}

static void join_perror_str(char **str, char *append_str)
{
	char *new_str;

	new_str = NULL;
	if (append_str != NULL)
	{
		new_str = ft_strjoin(*str, append_str);
		free(append_str);
		free(*str);
	}
	if (new_str != NULL)
	{
		perror(new_str);
		*str = ft_strdup(new_str);
	}
	else
		perror(*str);
	free(new_str);
}

static int	exit_pipex(t_pipex *pipex, int exit_code)
{
	if (pipex != NULL)
		free_pipex(pipex);
	exit(exit_code);
	return (exit_code);
}

static int	handle_error(int error, char **str, t_pipex *pipex)
{
	if (error == ERR_INPT)
	{
		ft_printf("%sinfile command1 command2 outfile\n", *str);
		return(EXIT_FAILURE);
	}
	else if (error == ERR_OPNI || error == ERR_CHMI)
	{
		join_perror_str(str, ft_strjoin("cannot open ", pipex->no_such_file));
		return(EXIT_SUCCESS);
	}
	else if (error == ERR_OPNO || error == ERR_CHMO)
	{
		join_perror_str(str, ft_strjoin("cannot create ", pipex->no_such_file));
		if (error != ERR_CHMO)
			return (EXIT_FAILURE);
	}
	else if (error == ERR_NCMD)
		join_perror_str(str, pipex->no_such_cmd);
	else if (error == ERR_NULL)
		join_perror_str(str, pipex->no_such_cmd);
	else if (error == ERR_MLLC)
		join_perror_str(str, NULL);
	return (error);
}

int	return_error(int error, t_pipex *pipex, int exit)
{
	char	*str;
	int		error_code;

	str = build_perror_prefix(pipex);
	error_code = handle_error(error, &str, pipex);
	free(str);
	if (exit == TRUE)
		return (exit_pipex(pipex, error_code));
	else
		return (error_code);
}
