#pragma once

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
	private:
		std::string m_type;
	public:
		Weapon(void);
		~Weapon(void);

		std::string Weapon::getType(void);
		void		Weapon::setType(std::string type);
};
#endif
