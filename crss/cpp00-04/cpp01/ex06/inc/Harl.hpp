/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 23:38:59 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 04:23:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

typedef enum e_level_type{
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
	NOT_FOUND = 4
}	t_level_type;

class Harl {
	private:
		std::string m_levels[4];
		void (Harl::*m_functions[4])(void);
		void	m_debug(void);
		void	m_info(void);
		void	m_warning(void);
		void	m_error(void);
	public:
		Harl(void);	
		~Harl(void);

		t_level_type	complain(std::string level); 
		void			filter(t_level_type type); 
};
