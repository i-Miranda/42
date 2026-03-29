/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:07:11 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 13:30:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string m_name;
		int			m_hit_points;
		int			m_energy_points;
		int			m_attack_damage;
	public:
		ClapTrap(void);
		ClapTrap(const std::string name); 
		ClapTrap(const std::string name, const int hit_points); 
		ClapTrap(const std::string name, const int hit_points, const int energy_points); 
		ClapTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage); 
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap& 	operator=(const ClapTrap &src);

		void		setName(const std::string& name);
		std::string	getName(void) const;
		void		setHitPoints(const int hit_points);
		int			getHitPoints(void) const;
		void		setEnergyPoints(const int energy_points);
		int			getEnergyPoints(void) const;
		void		setAttackDamage(const int attack_damage);
		int			getAttackDamage(void) const;

		void		attack(const std::string& target);
		void		takeDamage(unsigned int	amount);
		void		beRepaired(unsigned int	amount);
};
#endif
