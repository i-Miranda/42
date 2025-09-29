/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 13:28:08 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::Contact(void) {
	set_param(FIRST_NAME, static_cast<std::string>(""));
	set_param(LAST_NAME, static_cast<std::string>(""));
	set_param(NICKNAME, static_cast<std::string>(""));
	set_param(PHONE_NUMBER, static_cast<std::string>(""));
	set_param(DARKEST_SECRET, static_cast<std::string>(""));
}

void	Contact::Contact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret) {
	set_param(FIRST_NAME, first);
	set_param(LAST_NAME, last);
	set_param(NICKNAME, nick);
	set_param(PHONE_NUMBER, phone);
	set_param(DARKEST_SECRET, secret);
}

void	set_param(t_contact_data type, std::string str) {
	switch (type){
		case FIRST_NAME:
			this._first_name = str;		
		case LAST_NAME:
			this._last_name = str;		
		case NICKNAME:
			this._nickname = str;		
		case PHONE_NUMBER:
			this._phone_number = str;		
		case DARKEST_SECRET:
			this._darkest_secret = str;		
	}
}

std::string	get_param(t_contact_data type) {
	switch (type) {
		case FIRST_NAME:
			return (this._first_name);
		case LAST_NAME:
			return (this._last_name);
		case NICKNAME:
			return (this._nickname);
		case PHONE_NUMBER:
			return (this._phone_number);
		case DARKEST_SECRET:
			return (this._darkest_secret);
	}
}
