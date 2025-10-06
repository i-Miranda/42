/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:18:10 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/30 11:41:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CONTACT_H__
#define __CONTACT_H__

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
		Contact(void);
		Contact(std::string first, std::string last,
				std::string nick, std::string phone, std::string secret);
		bool		is_empty(void);
		void		set_empty(bool empty);
		void		set_param(t_contact_data type, std::string str);
		std::string	get_param(t_contact_data type);
	
	private:
		bool		m_is_empty;
		std::string m_first_name;	
		std::string m_last_name;	
		std::string m_nickname;	
		std::string m_phone_number;	
		std::string m_darkest_secret;	
};

#endif
