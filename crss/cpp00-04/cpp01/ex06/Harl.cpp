/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 23:41:55 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 03:18:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void	Harl::m_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::m_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough boom in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::m_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here last month." << std::endl;
}

void	Harl::m_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void) {
	this->m_levels[0] = "DEBUG";
	this->m_levels[1] = "INFO";
	this->m_levels[2] = "WARNING";
	this->m_levels[3] = "ERROR";

	this->m_functions[0] = &Harl::m_debug;
	this->m_functions[1] = &Harl::m_info;
	this->m_functions[2] = &Harl::m_warning;
	this->m_functions[3] = &Harl::m_error;
}

Harl::~Harl(void) {
}

t_level_type	Harl::complain(std::string level) {
	size_t	i;

	i = 0;
	while (i < sizeof(this->m_levels)/sizeof(this->m_levels[0])) {
		if (level == this->m_levels[i]) {
			return (static_cast<t_level_type>(i));
		}
		i++;
	}
	return (NOT_FOUND);
}

void	Harl::filter(t_level_type type) {
	switch(type){
		case DEBUG:
			std::cerr << "[ DEBUG ]" << std::endl;	
			(this->*m_functions[0])();
			std::cout << std::endl;
			// fallthrough
		case INFO:
			std::cerr << "[ INFO ]" << std::endl;	
			(this->*m_functions[1])();
			std::cout << std::endl;
			// fallthrough
		case WARNING:
			std::cerr << "[ WARNING ]" << std::endl;	
			(this->*m_functions[2])();
			std::cout << std::endl;
			// fallthrough
		case ERROR:
			std::cerr << "[ ERROR ]" << std::endl;	
			(this->*m_functions[3])();
			std::cout << std::endl;
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
