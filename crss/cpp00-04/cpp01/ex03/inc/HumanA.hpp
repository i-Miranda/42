#pragma once

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	m_name;
		Weapon&		m_weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);

		const std::string&	getName(void) const;
		void				setName(std::string name);
		Weapon&		getWeapon(void) const;
		void				setWeapon(Weapon weapon);
		void				attack(void) const;
};
#endif
