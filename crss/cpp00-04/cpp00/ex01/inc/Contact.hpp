/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:18:10 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 11:28:06 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

typedef enum e_contact_data {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
}	t_contact_data;

class Contact {
	public:
		void		Contact::Contact( void );
		void		set_param(t_contact_data type, std::string str);
		std::string	get_param(t_contact_data type);
	
	private:
		std::string _first_name;	
		std::string _last_name;	
		std::string _nickname;	
		std::string _phone_number;	
		std::string _darkest_secret;	
}

#endif
