/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:16:56 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 13:37:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
}

void	add(Contact::Contact contact) {
	bool found_empty;

	found_empty = false;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!this._contacts[i]) {
			this._contacts[i] = contact;	
			found_empty = true;
		}
	}
	if (!found_empty)
		this._contacts[MAX_CONTACTS - 1] = contact;
}

void	search(Contact::Contact contact) {
	
}
