#pragma once

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		std::string	get_name(void);
		void		set_name(std::string name);
		void		announce(void);
		~Zombie(void);
	
	private:
		std::string	m_name;
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);
