/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:08:42 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 11:34:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	pipex_error;

	pipex_error = ERR_INPT;
	if (argc < ARGC)
		return_error(pipex_error);
	pipex_error = pipex(argc - 1, &argv[1], envp);
	if (pipex_error < ERR_NONE)
		return_error(pipex_error);
	return (ERR_NONE);
}
