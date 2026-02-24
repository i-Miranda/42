/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:52:43 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 18:03:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const std::string name, const int hit_points);
		FragTrap(const std::string name, const int hit_points, const int energy_points); 
		FragTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage); 
		FragTrap(const FragTrap &src);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap &src);
		
		void	highFiveGuys(void);
};
#endif
