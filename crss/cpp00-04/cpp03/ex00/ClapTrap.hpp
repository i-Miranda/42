/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:07:11 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 14:38:15 by ivmirand         ###   ########.fr       */
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
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap& 	operator=(const ClapTrap &src);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int	amount);
		void		beRepaired(unsigned int	amount);
		void		getStatus(void);
};
#endif
