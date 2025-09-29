/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:26 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 11:23:31 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <string>

class PhoneBook {
	public:
		PhoneBook::PhoneBook(void);
		void add(Contact::Contact contact);
		void search(Contact::Contact contact);
	
	private:
		Contact::Contact[8] contacts;
}

#endif
