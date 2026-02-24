/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 01:59:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __DOG_H__
#define __DOG_H__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private :
		Brain* m_brain;
	public :
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);

		Dog& operator=(const Dog& src);
	
		void	makeSound(void) const;

		Brain&	getBrain(void); 
		const Brain&	getBrain(void) const;
		void	setBrain(const Brain& src);
};
#endif
