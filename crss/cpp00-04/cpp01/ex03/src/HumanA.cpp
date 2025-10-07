#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon): m_name(name), m_weapon(weapon) {
	this->setName(name);
	this->setWeapon(weapon);
}

HumanA::~HumanA(void) {
	this->getWeapon().~Weapon();
}

std::string	HumanA::getName(void) {
	return (this->m_name);
}

void	HumanA::setName(std::string name) {
	this->m_name = name;
}

Weapon HumanA::getWeapon(void) {
	return (this->m_weapon.getType());
}

void	HumanA::setWeapon(Weapon weapon) {
	this->m_weapon = weapon;
}

void	HumanA::attack(void) {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
