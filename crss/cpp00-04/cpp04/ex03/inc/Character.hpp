/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:38:36 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:41:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"

class Character : public ICharacter {
	private :
		std::string m_name;
		AMateria* m_inventory[4];
	public :
		Character(std::string const _name);
		Character(const Character& src);
		~Character(void);
		
		Character& operator=(const Character& src);
};
#endif
