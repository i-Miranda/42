#pragma once

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
	private:
		std::string m_type;

	public:
		explicit Weapon(const std::string& type);
		~Weapon(void);

		const std::string& getType(void) const;
		void		setType(const std::string& type);
};
#endif
