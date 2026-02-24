/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 13:30:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <string>
#include <iostream>

class WrongAnimal {
	protected :
		std::string type;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal& src);

		void	makeSound(void) const;

		std::string getType(void) const;
		void		setType(const std::string type);
};
#endif
