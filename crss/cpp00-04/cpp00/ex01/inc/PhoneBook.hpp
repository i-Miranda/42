/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:26 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/30 12:35:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Contact.hpp"

# define MAX_CONTACTS 8
# define TRUNC 10

class PhoneBook {
	public:
		PhoneBook(void);
		void	add(void);
		void	search(void);
	
	private:
		Contact m_contacts[MAX_CONTACTS];
		void	_get_contacts_summary(void); 
		bool	_get_contact_details(unsigned int index);
		void	_set_contact_params(Contact &contact);
		std::string	_get_valid_line(const std::string &prompt, bool allow_empty = false);
		bool		_is_valid_phone_number(const std::string &phone);
};
#endif
