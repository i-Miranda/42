/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 13:18:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		WrongCat(void);
		WrongCat(const WrongCat& src);
		~WrongCat(void);

		WrongCat& operator=(const WrongCat& src);

		void	makeSound(void) const;
};
#endif
