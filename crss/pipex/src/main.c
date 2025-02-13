/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:57:02 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/13 13:05:20 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != ARGC + 1)
		return (return_error(ERR_INPT, NULL));
	return (pipex(ARGC, &argv[1], env));
}
