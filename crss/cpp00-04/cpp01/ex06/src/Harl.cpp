/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 23:41:55 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 04:23:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void	Harl::m_debug(void) {
	std::cerr << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::m_info(void) {
	std::cerr << "I cannot believe adding extra bacon costs more money. You didn't put enough boom in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::m_warning(void) {
	std::cerr << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here last month." << std::endl;
}

void	Harl::m_error(void) {
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void) {
	this->m_levels[0] = "debug";
	this->m_levels[1] = "info";
	this->m_levels[2] = "warning";
	this->m_levels[3] = "error";
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
			(this->*m_functions[0])();
			// fallthrough
		case INFO:
			(this->*m_functions[1])();
			// fallthrough
		case WARNING:
			(this->*m_functions[2])();
			// fallthrough
		case ERROR:
			(this->*m_functions[3])();
			break;
		default:
			std::cerr << "Complaint Level not found." << std::endl;
	}
}
