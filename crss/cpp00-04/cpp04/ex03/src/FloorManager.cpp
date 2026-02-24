/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloorManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:46:35 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:00:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

static void UpdateFloor(AMateria* m) {
	static AMateria* floor[100];

	for (int i = 0; i < 100; i++) {
		if ((*floor)[i] == NULL) {
			(*floor)[i] = m;
			return ;
		}
	}
	std::cerr << "Floor is full. Deleting first Materia in floor." << std::endl;
	delete (*floor)[0];
	for (int i = 0; i < 100; ++i) {
		(*floor)[i - 1] = (*floor)[i];
		(*floor)[i] == NULL;
	}
	(*floor)[99] = m;
}
