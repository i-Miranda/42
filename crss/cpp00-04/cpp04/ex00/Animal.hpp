/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/30 20:21:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>
#include <iostream>

class Animal {
	protected :
		std::string type;
	public :
		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal(void);

		Animal& operator=(const Animal& src);

		virtual void	makeSound(void) const;

		std::string getType(void) const;
		void		setType(const std::string animal_type);
};
#endif
