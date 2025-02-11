/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:57:02 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 14:39:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != ARGC + 1)
		return_error(ERR_INPT, NULL);
	pipex(ARGC, &argv[1], env);
	return (0);
}
