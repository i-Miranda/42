#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Unnamed zombie was created." << std::endl;
}

Zombie::Zombie(std::string name) {
	set_name(name);	
	std::cout << this->get_name() << " was created." << std::endl;
}

std::string	Zombie::get_name(void) {
	return (this->m_name);
}

void	Zombie::set_name(std::string name) {
	this->m_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->get_name() << " was destroyed." << std::endl;
}
