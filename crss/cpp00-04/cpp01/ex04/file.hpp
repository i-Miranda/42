/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 23:39:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 00:00:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

class File {
	private:
		std::ifstream m_filestream;
		std::ofstream m_newstream;
	public:
		File(std::string filename);	
		~File(void);

		void	substitute(std::string s1, std::string s2);
};
#endif
