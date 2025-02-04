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

int	main(int argc, char *argv[])
{
	if (argc < 5)
		return (1);
	if (pipex(argv[1], argv[2], argv[3], argv[4]) < 0); 
		return (1);
	return (0);
}
