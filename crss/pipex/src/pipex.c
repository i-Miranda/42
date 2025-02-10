/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:02 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 16:42:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	t_pipe	*pipe_data;
	int		error;
		
	error = init_pipex(&pipe_data, args);
	if (error != ERR_NONE)
		return (error);
	error = parse_cmds(&pipe_data, args);
	if (error != ERR_NONE)
		return (error);
	error = parse_args(&pipe_data, args);
	if (error != ERR_NONE)
		return (error);
	if (pipe(pipe_data->fildes) == ERR_GNRL)
		return (ERR_PIPE);
	error = run_processes(&pipe_data, envp);
	return (error);
}
