/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloorManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:46:35 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 16:07:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FLOORMANAGER_H__
#define __FLOORMANAGER_H__

#include "AMateria.hpp"

class FloorManager {
	private : 
		AMateria* m_floor[100];
	public :
		FloorManager();
		FloorManager(const FloorManager& src);
		~FloorManager();

		FloorManager& operator=(const FloorManager& src);

		void store(AMateria* m);
};
#endif
