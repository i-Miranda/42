/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 01:59:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CAT_H__
#define __CAT_H__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private :
		Brain* m_brain;
	public :
		Cat(void);
		Cat(const Cat& src);
		~Cat(void);

		Cat& operator=(const Cat& src);

		void	makeSound(void) const;

		Brain&	getBrain(void);
		const Brain&	getBrain(void) const;
		void	setBrain(const Brain& src);
};
#endif
