/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/30 12:07:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	set_param(FIRST_NAME, static_cast<std::string>(""));
	set_param(LAST_NAME, static_cast<std::string>(""));
	set_param(NICKNAME, static_cast<std::string>(""));
	set_param(PHONE_NUMBER, static_cast<std::string>(""));
	set_param(DARKEST_SECRET, static_cast<std::string>(""));
	this->m_is_empty = true;
}

Contact::Contact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret) {
	set_param(FIRST_NAME, first);
	set_param(LAST_NAME, last);
	set_param(NICKNAME, nick);
	set_param(PHONE_NUMBER, phone);
	set_param(DARKEST_SECRET, secret);
	this->m_is_empty = false;
}

bool	Contact::is_empty(void) {
	return (this->m_is_empty);
}

void	Contact::set_empty(bool empty) {
	this->m_is_empty = empty;	
}

void	Contact::set_param(t_contact_data type, std::string str) {
	switch (type){
		case FIRST_NAME:
			this->m_first_name = str;		
			break;
		case LAST_NAME:
			this->m_last_name = str;		
			break;
		case NICKNAME:
			this->m_nickname = str;		
			break;
		case PHONE_NUMBER:
			this->m_phone_number = str;		
			break;
		case DARKEST_SECRET:
			this->m_darkest_secret = str;		
			break;
		default:
			return ;
	}
	this->set_empty(false);
}

std::string	Contact::get_param(t_contact_data type) {
	switch (type) {
		case FIRST_NAME:
			return (this->m_first_name);
		case LAST_NAME:
			return (this->m_last_name);
		case NICKNAME:
			return (this->m_nickname);
		case PHONE_NUMBER:
			return (this->m_phone_number);
		case DARKEST_SECRET:
			return (this->m_darkest_secret);
		default:
			return (std::string());
	}
}
