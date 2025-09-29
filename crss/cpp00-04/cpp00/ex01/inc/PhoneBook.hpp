/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:26 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 13:37:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <string>

#include "Contact.hpp"

# define MAX_CONTACTS 8
# define TRUNC 10

class PhoneBook {
	public:
		PhoneBook::PhoneBook(void);
		void add(Contact::Contact contact);
		void search(Contact::Contact contact);
	
	private:
		Contact::Contact[MAX_CONTACTS] _contacts;
}
#endif
