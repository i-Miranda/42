#pragma once

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		std::string	get_name(void);
		void		set_name(std::string name);
		void		announce(void);
		~Zombie(void);
	
	private:
		std::string	m_name;
};

Zombie* zombieHorde(int N, std::string name); 

#endif
