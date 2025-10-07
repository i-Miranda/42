#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon(void) {}

std::string	Weapon::getType(void) {
	return (this->m_type);
}

void	Weapon::setType(std::string type) {
	this->m_type = type;
}
