#pragma once

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	m_name;
		Weapon* m_weapon;
	public:
		explicit HumanB(const std::string& name);
		~HumanB(void);

		const std::string& getName(void) const;
		void		setName(std::string name);
		Weapon		getWeapon(void) const;
		void		setWeapon(Weapon& weapon);
		void		attack(void) const;
};
#endif
