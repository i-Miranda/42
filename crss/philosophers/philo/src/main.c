/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/26 01:44:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_error	error;
	t_table	table;

	error = ENONE;
	if (argc < 5 || argc > 6)
		return (EARGC);
	error = check_args(argc, argv, &table);
	error = table_bon_apetit(&table);
	table_free(&table);
	return ((int)error);
}
