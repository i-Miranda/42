/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 02:11:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __A_ANIMAL_H__
#define __A_ANIMAL_H__

#include <string>
#include <iostream>

class AAnimal {
	protected :
		std::string type;
	public :
		AAnimal(void);
		AAnimal(const AAnimal& src);
		virtual ~AAnimal(void);

		AAnimal& operator=(const AAnimal& src);

		virtual void	makeSound(void) const = 0;

		std::string getType(void) const;
		void		setType(const std::string type);
};
#endif
