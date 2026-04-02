/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:06:16 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 01:32:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>
#include <iostream>

class Brain {
	private :
		std::string m_ideas[100];
	public :
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);

		Brain& operator=(const Brain& src);

		const std::string& getIdea(const int index) const;
		void		setIdea(const std::string& idea, const int index);
};
#endif
