/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/27 13:02:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_error	error;
	t_table	table;

	error = ENONE;
	if (argc < 5 || argc > 6)
	{
		print_string_fd("Error: incorrect argument count:\n", STDERR_FILENO);
		print_string_fd("1)[number philosophers] 2)[time to die] ",
			STDERR_FILENO);
		print_string_fd("3)[time to eat] 4)[time to sleep] ", STDERR_FILENO);
		print_string_fd("5)[times must eat(optional)]\n", STDERR_FILENO);
		return (EARGC);
	}
	error = check_args(argc, argv, &table);
	if (error != ENONE)
		return ((int)error);
	error = table_bon_apetit(&table);
	table_free(&table);
	return ((int)error);
}
