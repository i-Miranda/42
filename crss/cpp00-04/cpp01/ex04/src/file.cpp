/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:51:21 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/16 22:47:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

File::File(std::string filename) {
	std::string new_filename;
	this->m_filestream.open(filename.c_str(), std::ios_base::in);
	if (!this->m_filestream)
		std::cerr << "ERROR\nFile: \"" << filename << "\" not found." << std::endl;
	new_filename = filename + ".replace";
	this->m_newstream.open(new_filename.c_str(), std::ios_base::out);
	if (!this->m_newstream)
		std::cerr << "ERROR\nFile: \"" << new_filename << "\" not created." << std::endl;
	else
		std::cout << new_filename << " created." << std::endl;
}

File::~File(void) {
	if (this->m_filestream.is_open())
		this->m_filestream.close();
	if (this->m_newstream.is_open())
		this->m_newstream.close();
}

void	File::substitute(std::string s1, std::string s2) {
	size_t		pos;
	std::string	current;	

	if (s1.empty())
		return ;
	while (std::getline(this->m_filestream, current)) {
		pos = current.find(s1);
		while (pos != std::string::npos) {
			current.erase(pos, s1.length());
			current.insert(pos, s2);
			pos = current.find(s1, pos + s2.length());
		}
		this->m_newstream << current << std::endl;
	}
}
