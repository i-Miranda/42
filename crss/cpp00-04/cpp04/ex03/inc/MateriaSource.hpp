/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:47:39 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:41:32 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private :
		AMateria* m_known_materia[4];
	public :
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);

		MateriaSource& operator=(const MateriaSource& src);
};
#endif
