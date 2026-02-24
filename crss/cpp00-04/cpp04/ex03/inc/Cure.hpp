/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:25:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:33:13 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria {
	public :
		Cure(std::string const & type);
		Cure(const Cure& src);
		~Cure(void);

		Cure& operator=(const Cure& src);
};
#endif
