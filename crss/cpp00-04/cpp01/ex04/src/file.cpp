/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:51:21 by ivmirand          #+#    #+#             */
/*   Updated: 2025/11/04 21:23:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include "file.hpp"

File::File(const char *filename) {
	this->m_filestream = std::fstream::open(filename);
}

File::~File(void) {
	if (this->m_filestream.is_open())
		this->m_filestream.close();
}

void	File::substitute(std::string s1, std::string s2) 
	size_t	pos;

	getline(this->m_filestream, this->m_content);
	pos = this->m_content.find(s1, 0);
	while (pos != this->m_content.npos) {
		this->m_content.replace(pos, s2.length(), s2);
		pos = this->m_content.find(s1, pos + 1);
	}
}
#endif
