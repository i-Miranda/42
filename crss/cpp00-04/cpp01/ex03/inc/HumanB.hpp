#pragma once

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	m_name;
		Weapon m_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);

		std::string HumanB::getName(void);
		void		HumanB::setName(std::string name);
		Weapon		HumanB::getWeapon(void);
		void		HumanB::setWeapon(Weapon weapon);
		void		HumanB::attack(void);
};
#endif
