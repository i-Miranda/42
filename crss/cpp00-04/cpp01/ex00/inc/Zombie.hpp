/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:26:42 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/24 15:26:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	m_name;

	public:
		Zombie(std::string name);
		~Zombie(void);

		std::string	get_name(void);
		void		set_name(std::string name);
		void		announce(void);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);
#endif
