/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:25:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 23:09:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
	protected :
		std::string type;
	public :
		AMateria(std::string const & type);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);

		AMateria& operator=(const AMateria& src);
		
		std::string const & getType(void) const; //Returns the materia type

		virtual AMateria* clone(void) const = 0;
		virtual void	use(ICharacter& target) = 0;
};
#endif
