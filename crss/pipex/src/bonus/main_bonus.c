/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:57:02 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 12:00:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	if (pipex->cmds)
	{
		while (pipex->cmds[i])
		{
			j = 0;
			while (pipex->cmds[i][j])
				free(pipex->cmds[i][j++]);
			free(pipex->cmds[i++]);
		}
	}
	free(pipex->cmds);
	i = 0;
	while (pipex->path_split && pipex->path_split[i])
		free(pipex->path_split[i++]);
	free(pipex->path_split);
	free(pipex);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != ARGC + 1)
		return_error(ERR_INPT, NULL);
	pipex(ARGC, &argv[1], env);
	return (0);
}
