/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:08:42 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/09 12:09:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	pipex_error;

	pipex_error = -1;
	if (argc < 5)
		return_error (pipex_error);
	pipex_error = pipex(&argv[1], envp);
	if (pipex_error < 0)
		return_error(pipex_error);
	return (0);
}
