/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:52:43 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/19 16:55:08 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string m_name;
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const std::string name, const int hit_points);
		DiamondTrap(const std::string name, const int hit_points, const int energy_points); 
		DiamondTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage); 
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap &src);
		
		void		attack(const std::string& target);

		void	whoAmI(void);
};
#endif
