/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:17:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 11:28:12 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::Contact(void) {
	set_param(FIRST_NAME, (std::string)(""));
	set_param(LAST_NAME, static_cast<std::string>(""));
	set_param(NICKNAME, static_cast<std::string>(""));
	set_param(PHONE_NUMBER, static_cast<std::string>(""));
	set_param(DARKEST_SECRET, static_cast<std::string>(""));
}

void	set_param(t_contact_data type, std::string str){

}
