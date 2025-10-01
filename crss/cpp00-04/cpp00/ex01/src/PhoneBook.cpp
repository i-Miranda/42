/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:16:56 by ivmirand          #+#    #+#             */
/*   Updated: 2025/10/01 22:35:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string truncate_contact_param(Contact contact, t_contact_data type){
	std::string	contact_param;
	std::string	trunc;
	int			contact_param_len;

	contact_param = contact.get_param(type);
	contact_param_len = contact_param.length();
	if (contact_param_len >= TRUNC)
	{
		trunc.reserve(TRUNC);	
		for (int i = 0; i < TRUNC; i++)
			trunc.push_back(contact_param[i]);
		trunc[TRUNC - 1] = '.';
		return (trunc);
	}
	return (contact_param);
}

void	PhoneBook::_get_contacts_summary(void) {
	int	i;

	i = 0;
	while (i < MAX_CONTACTS && !this->m_contacts[i].is_empty()) {
		std::cout << i + 1 << " | ";
		std::cout << truncate_contact_param(this->m_contacts[i], FIRST_NAME);
		std::cout << " | "; 
		std::cout << truncate_contact_param(this->m_contacts[i], LAST_NAME); 
		std::cout << " | "; 
		std::cout << truncate_contact_param(this->m_contacts[i], NICKNAME);
		std::cout << std::endl; 
		i++;
	}
}

bool	PhoneBook::_get_contact_details(unsigned int index) {
	if (index < MAX_CONTACTS && !this->m_contacts[index].is_empty()) {
		std::cout << this->m_contacts[index].get_param(FIRST_NAME) << std::endl;
		std::cout << this->m_contacts[index].get_param(LAST_NAME) << std::endl;
		std::cout << this->m_contacts[index].get_param(NICKNAME) << std::endl;
		std::cout << this->m_contacts[index].get_param(PHONE_NUMBER) << std::endl;
		std::cout << this->m_contacts[index].get_param(DARKEST_SECRET) << std::endl;
		return (true);
	}
	std::cout << "Invalid contact index" << std::endl;
	return (false);
}

static bool	_is_allowed_phone_char(char c) {
	return ((c >= '0' && c <= '9')
		|| c == ' ' || c == '+' || c == '-' || c == '(' || c == ')');
}

bool	PhoneBook::_is_valid_phone_number(const std::string &phone) {
	bool	has_digit;
	char	c;

	has_digit = false;
	for (std::string::size_type i = 0; i < phone.length(); ++i) {
		c = phone[i];
		if (!_is_allowed_phone_char(c))
			return false;
		if (c >= '0' && c <= '9')
			has_digit = true;
	}
	return has_digit;
}

std::string	PhoneBook::_get_valid_line(const std::string &prompt, bool allow_empty) {
	std::string	input;
	
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			std::exit(0);
		}
		
		if (!input.empty() || allow_empty) {
			return (input);
		}
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

void	PhoneBook::_set_contact_params(Contact &contact) {
	std::string	param;

	param = _get_valid_line("First name: ");
	contact.set_param(FIRST_NAME, param);

	param = _get_valid_line("Last name: ");
	contact.set_param(LAST_NAME, param);

	param = _get_valid_line("Nickname: ");
	contact.set_param(NICKNAME, param);

	while (true) {
		param = _get_valid_line("Phone number: ");
		if (_is_valid_phone_number(param))
			break;
		std::cout << "Invalid phone number. Use digits, spaces, +, -, (, ) and include at least one digit." << std::endl;
	}
	contact.set_param(PHONE_NUMBER, param);

	param = _get_valid_line("Darkest secret: ");
	contact.set_param(DARKEST_SECRET, param);
}

PhoneBook::PhoneBook(void) {
}

void	PhoneBook::add(void) {
	Contact contact;

	this->_set_contact_params(contact);
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (this->m_contacts[i].is_empty()) {
			this->m_contacts[i] = contact;
			return;
		}
	}
	for (int i = 0; i < MAX_CONTACTS - 1; i++)
		this->m_contacts[i] = this->m_contacts[i + 1];
	this->m_contacts[MAX_CONTACTS - 1] = contact;
}

void	PhoneBook::search(void) {
	std::string		input;
	unsigned int	index;
	
	_get_contacts_summary();
	while (true) {
		input = _get_valid_line("Please enter the index of the contact desired: ", true);
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
			index = input[0] - '0';
			if (_get_contact_details(index - 1))
				break;
			else
				std::cout << "Contact not found." << std::endl;
		} 
		else 
			std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
	}
}
