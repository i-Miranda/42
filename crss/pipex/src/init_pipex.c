/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 12:16:42 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int open_files(t_pipe *pipe_data)
{
	pipe_data->fildes[0] = open(pipe_data->infile, O_RDONLY | O_CREAT);
	pipe_data->fildes[1] = open(pipe_data->outfile, O_RDWR | O_CREAT, CHMOD_RWRR);
	if (pipe_data->fd_if == ERR_GNRL || pipe_data->fd_of == ERR_GNRL)
		return (ERR_GNRL);
	return (ERR_NONE);
}

int	init_pipex(t_pipe *pipe_data, char **args)
{
	pipe_data = malloc(sizeof(t_pipe));
	if (pipe_data == NULL)
		return (ERR_MLLC);
	pipe_data->infile = args[0];
	pipe_data->left_cmd = args[1];
	pipe_data->right_cmd = args[2];
	pipe_data->outfile = args[3];
	if (pipe(pipe_data->fildes) == ERR_GNRL)
		return (ERR_PIPE);
	if (open_files(pipe_data) == ERR_GNRL)
		return (ERR_OPEN);
	if (access(pipe_data->infile, R_OK) != ERR_NONE 
			|| access(pipe_data->outfile, W_OK) != ERR_NONE)
		return (ERR_ACS);	
	pipe_data->child_pid = fork();	
	pipe_data->parent_pid = fork();	
	if (pipe_data->child_pid == ERR_GNRL || pipe_data->parent_pid == ERR_GNRL)
		return (ERR_FORK);
	return (ERR_NONE);
}
