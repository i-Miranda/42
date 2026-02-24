/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:25:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 22:52:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria {
	public :
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);

		Ice& operator=(const Ice& src);

		AMateria* clone(void) const;
		void	use(ICharacter& target);
};
#endif
