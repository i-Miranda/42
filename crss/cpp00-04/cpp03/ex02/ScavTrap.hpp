/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:31:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 17:26:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const std::string name, const int hit_points);
		ScavTrap(const std::string name, const int hit_points, const int energy_points); 
		ScavTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage); 
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap &src);
		
		void	guardGate(void);
};
#endif
