#pragma once

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	m_name;
		Weapon m_weapon;
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		std::string HumanA::getName(void);
		void		HumanA::setName(std::string name);
		Weapon		HumanA::getWeapon(void);
		void		HumanA::setWeapon(Weapon weapon);
		void		HumanA::attack(void);
};
#endif
