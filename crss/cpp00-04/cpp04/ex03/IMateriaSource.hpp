/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:47:39 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:42:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include <string>
#include <iostream>

#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {}
		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif
