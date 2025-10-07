#include "HumanB.hpp"

HumanB::HumanB(std::string name): m_name(name) {
	this->setName(name);
}

HumanB::~HumanB(void) {
	delete this->m_weapon;
}

std::string	HumanB::getName(void) {
	return (this->m_name);
}

void	HumanB::setName(std::string name) {
	this->m_name = name;
}

Weapon	HumanB::getWeapon(void) {
	return (this->m_weapon->getType());
}

void	HumanB::setWeapon(Weapon weapon) {
	this->m_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
