/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int open_files(t_pipe *pipe_data)
{
	pipe_data->fildes[0] = open(pipe_data->if_path, O_RDONLY | O_CREAT);
	pipe_data->fildes[1] = open(pipe_data->of_path, O_RDWR | O_CREAT, CHMOD_RWRR);
	if (pipe_data->fildes[0] == ERR_GNRL || pipe_data->fildes[1] == ERR_GNRL)
		return (ERR_GNRL);
	return (ERR_NONE);
}

int	init_pipex(t_pipe **pipe_data, char **args)
{
	int	i;
	(*pipe_data) = malloc(sizeof(t_pipe));
	if ((*pipe_data) == NULL)
		return (ERR_MLLC);
	if (open_files(*pipe_data) == ERR_GNRL)
		return (ERR_OPEN);
	i = 1;
	if (parse_args(pipe_data, args) < ERR_NONE)
		return (ERR_PRSA);
	if (parse_cmds(pipe_data, args) < ERR_NONE)
		return (ERR_PRSC);
	if (access((*pipe_data)->if_path, R_OK) != ERR_NONE 
			|| access((*pipe_data)->of_path, W_OK) != ERR_NONE)
		return (ERR_ACS);	
	return (ERR_NONE);
}
